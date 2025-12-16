#include "day03.h"
#include "fmt/base.h"
#include "fmt/ranges.h"
#include <algorithm>
#include <fstream>
#include <numeric>
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

int Day03Solution::iterOverRangePart1(const std::vector<int> &_vec) {
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
    m_futuresP1.emplace_back(
        std::async(std::launch::async, iterOverRangePart1, bank));
  }
  for (auto &res : m_futuresP1) {
    m_result1 += res.get();
  }
}
uint64_t Day03Solution::iterOverRangePart2(const std::vector<int> &_vec) {
  std::vector<int> _out;
  _out.reserve(12);
  std::string res;
  // calculate bank
  int window = _vec.size() - 12;
  for (const int &i : _vec) {
    if (window == 0) {
      _out.emplace_back(i);
      continue;
    }
    // remove until the current one is no bigger
    while (window > 0 && !_out.empty() && i > _out.back()) {
      _out.pop_back();
      window--;
    }
    _out.emplace_back(i);
  }
  // remove extra out values
  while (_out.size() > 12) {
    _out.pop_back();
  }
  // generate the answer
  for (auto &x : _out) {
    res += std::to_string(x);
  }
  return static_cast<uint64_t>(std::stoll(res));
}
void Day03Solution::SolvePart2() {

  // NOTE: we can assume that there would be no zeros in the input set
  // solved using two pointers
  for (auto &bank : m_input) {
    m_futuresP2.emplace_back(
        std::async(std::launch::async, iterOverRangePart2, bank));
  }
  for (auto &res : m_futuresP2) {
    m_result2 += res.get();
  }
}

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
