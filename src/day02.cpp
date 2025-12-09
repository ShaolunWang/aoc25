#include "day02.h"
#include "fmt/base.h"
#include "fmt/ranges.h"
#include <fstream>
#include <sstream>

void Day02Solution::parseInput() {
  std::ifstream infile(m_filename, std::ios::binary | std::ios::in);
  m_input.reserve(50);
  std::string line;
  while (std::getline(infile, line, ',')) {
    std::stringstream ss{line};
    uint64_t a;
    uint64_t b;
    char dash;
    ss >> a >> dash >> b;
    m_input.emplace_back(a, b);
  }
}

uint64_t Day02Solution::iterOverRangePart1(uint64_t a, uint64_t b) {
  uint64_t sum = 0;
  for (uint64_t i = a; i <= b; i++) {
    std::string s = std::to_string(i);
    if (s.size() % 2 == 0) {
      // fmt::print("{} ", s.substr(0, s.size() / 2));
      // fmt::print("{} \n", s.substr(s.size() / 2));
      if (s.substr(s.size() / 2) == s.substr(0, (s.size() / 2))) {
        // fmt::println("{}", i);
        sum += i;
        // fmt::println("valid");
      }
      // fmt::print("-----------\n");
    }
  }
  return sum;
}

void Day02Solution::SolvePart1() {

#ifndef TEST
  for (auto &[start, end] : m_input) {
    m_futuresP1.push_back(
        std::async(std::launch::async, iterOverRangePart1, start, end));
  }

  for (auto &res : m_futuresP1) {
    m_result1 += res.get();
  }
#else
  for (auto &[start, end] : m_input) {
    fmt::println("{} {}", start, end);
    m_result1 += iterOverRangePart1(start, end);
  }
#endif
}

uint64_t Day02Solution::iterOverRangePart2(uint64_t a, uint64_t b) {
  uint64_t sum = 0;

  for (uint64_t i = a; i <= b; i++) {
    // fmt::println("currently checking: {}", i);
    bool allMatches = true;
    if (i < 11) {
      continue;
    }
    std::string s = std::to_string(i);
    // iter through all possible windows and see which one matches
    for (int window = 1; window <= s.size() / 2; window++) {
      allMatches = true;
      // ignore invalid cases
      if (s.size() % window != 0) {
        allMatches = false;
        continue;
      }
      std::string base = s.substr(0, window);
      // fmt::println("base: {}", base);
      for (auto splitSize = window; splitSize <= s.size() - window;
           splitSize += window) {
        // fmt::println("splitSize: {} | window: {} :substr: {}", splitSize,
                     // window, s.substr(splitSize, window));
        if (s.substr(splitSize, window) != base) {
          // fmt::println("invalid.");
          allMatches = false;
          break;
        }
      }

      // if we have found then just break
      // no need of checking other windows
      if (allMatches) {
        break;
      }
    }
    sum += allMatches ? i : 0;
  }
  return sum;
}
void Day02Solution::SolvePart2() {

#ifndef TEST
  for (auto &[start, end] : m_input) {
    m_futuresP2.push_back(
        std::async(std::launch::async, iterOverRangePart2, start, end));
  }

  for (auto &res : m_futuresP2) {
    m_result2 += res.get();
  }

#else
  for (auto &[start, end] : m_input) {
    m_result2 += iterOverRangePart2(start, end);
  }
#endif
}

#ifndef TEST
int main() {
  Day02Solution sol;
  sol.parseInput();
  sol.SolvePart1();
  sol.SolvePart2();
  fmt::println("{}", sol.getResultPart1());
  fmt::println("{}", sol.getResultPart2());
  return 0;
}
#endif
