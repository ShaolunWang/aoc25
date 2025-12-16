#include "day01.h"
#include "fmt/ranges.h"
#include <fstream>
#include <string>
void Day01Solution::ReadFromFile() {
  std::ifstream infile(m_filename, std::ios::binary | std::ios::in);
  m_input.reserve(4500);
  std::string line;
  while (std::getline(infile, line)) {
    char direction = line[0];
    int value = std::stoi(line.substr(1));
    m_input.emplace_back(direction, value);
  }
}

void Day01Solution::Simulate() {
  int current = 50;

  for (auto &[direction, value] : m_input) {
    if (direction == 'R') {
      // Rotate Right
      while (value > 100) {
        m_result2++;
        value -= 100;
      }
      // regardless whether it hits 0 or not,
      // we will incr the value since it doesn't matter
      // however we don't increase the value
      // if we are starting from 0
      if (current + value >= 100 && current != 0) {
        current += value;
        current -= 100;
        m_result2++;
      } else {
        if (current + value == 0) {
          m_result2++;
        }
        current += value;
      }
    } else {
      // Rotate Left
      while (value > 100) {
        // if it's larger than 100,
        // we'd be rotating them more than a cycle
        // thus we need to make it below
        // a cycle

        m_result2++;
        value -= 100;
      }

      // we don't increase the value
      // if we are starting from 0
      if (current - value < 0 && current != 0) {
        current -= value;
        current += 100;
        m_result2++;
      } else {
        if (current - value == 0) {
          m_result2++;
        }
        current -= value;
        // NOTE: only left rotation requires this
        // edge check
        if (current < 0) {
          current += 100;
        }
      }
    }
    fmt::println("result: {}\n--------------------", current);
    if (current == 0) {
      m_result1++;
    }
  }
}

#ifndef DEBUGTEST
int main() {
  Day01Solution sol;
  sol.ReadFromFile();
  sol.Simulate();
  fmt::println("{}", sol.getResultPart1());
  fmt::println("{}", sol.getResultPart2());
  return 0;
}
#endif
