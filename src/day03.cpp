#include "day03.h"
#include "fmt/base.h"
#include "fmt/ranges.h"
#include <algorithm>
#include <fstream>
#include <vector>

void Day03Solution::parseInput() {
  std::ifstream infile(m_filename, std::ios::binary | std::ios::in);
  // input size known
  m_input.reserve(200);
  std::string line;
  while (std::getline(infile, line)) {
    std::vector<int> _line;
    _line.reserve(line.size());
    for (char i : line) {
      // just get the value
      _line.emplace_back(i - '0');
    }
    m_input.push_back(_line);
  }
}
void Day03Solution::SolvePart1() {
  // NOTE: we can assume that there would be no zeros in the input set
  // solved using two pointers
  for (auto &bank : m_input) {
    fmt::println("current line: {}", bank);
    int slow = 0;
    int fast = 0;
    // incrementally finding the largest number in the bank
    for (int i = 0; i < bank.size() - 1; i++) {
      if (bank[i] > slow) {
        slow = bank[i];
        fast = bank[i + 1];
      }
      for (int j = i + 1; j < bank.size(); j++) {
        if (bank[j] > slow && j != bank.size() - 1) {
          slow = bank[j];
          fast = bank[j + 1];
          i = j;
          break;
        }
        fast = std::max(bank[j], fast);
      }
    }
    m_result1 += ((slow * 10) + fast);
    fmt::println("slow {}, fast {}, value {}", slow, fast,
                 ((slow * 10) + fast));
    fmt::println("----------------------");
  }
}
void Day03Solution::SolvePart2() {}

#ifndef DEBUGTEST
int main() {
  Day03Solution sol;
  sol.parseInput();
  sol.SolvePart1();
  sol.SolvePart2();
  fmt::println("Solution for part 1 {}", sol.getResultPart1());
  fmt::println("Solution for part 2 {}", sol.getResultPart2());
}
#endif
