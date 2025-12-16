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
int Day03Solution::iterOverRangePart1(std::vector<int> _vec) {
  int slow = 0;
  int fast = 0;
  // incrementally finding the largest number in the _vec
  for (int i = 0; i < _vec.size() - 1; i++) {
    if (_vec[i] > slow) {
      slow = _vec[i];
      fast = _vec[i + 1];
    }
    for (int j = i + 1; j < _vec.size(); j++) {
      if (_vec[j] > slow && j != _vec.size() - 1) {
        slow = _vec[j];
        fast = _vec[j + 1];
        i = j;
        break;
      }
      fast = std::max(_vec[j], fast);
    }
  }
  return (slow * 10) + fast;
}
void Day03Solution::SolvePart1() {
  // NOTE: we can assume that there would be no zeros in the input set
  // solved using two pointers
  for (auto &bank : m_input) {
    m_futuresP1.push_back(
        std::async(std::launch::async, iterOverRangePart1, bank));
  }
  for (auto &res : m_futuresP1) {
    m_result1 += res.get();
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
