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

uint64_t Day02Solution::iterOverRange(uint64_t a, uint64_t b) {
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
    m_futures.push_back(
        std::async(std::launch::async, iterOverRange, start, end));
  }

  for (auto &res : m_futures) {
    m_result1 += res.get();
  }
#else
  for (auto &[start, end] : m_input) {
    fmt::println("{} {}", start, end);
    m_result1 += iterOverRange(start, end);
  }
#endif
}

#ifndef TEST
int main() {
  Day02Solution sol;
  sol.parseInput();
  sol.SolvePart1();
  fmt::println("{}", sol.getResultPart1());
  // fmt::println("{}", sol.getResultPart2());
  return 0;
}
#endif
