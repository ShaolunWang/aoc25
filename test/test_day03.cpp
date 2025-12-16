#include "day03.h"
#include "gtest/gtest.h"
#include <vector>
TEST(Day03, Sample) {
  Day03Solution sol;
  sol.parseInput();
  sol.SolvePart1();
  ASSERT_EQ(357, sol.getResultPart1());
}
TEST(Day03, RepeatedDigitsLow) {
  Day03Solution sol;
  std::vector<std::vector<int>> _input = {{1, 1, 1, 1, 1, 1, 2}};
  sol.setInput(_input);
  sol.SolvePart1();
  ASSERT_EQ(12, sol.getResultPart1());
}
TEST(Day03, RepeatedDigitsLow2) {
  Day03Solution sol;
  std::vector<std::vector<int>> _input = {{2, 1, 1, 1, 1, 1, 2}};
  sol.setInput(_input);
  sol.SolvePart1();
  ASSERT_EQ(22, sol.getResultPart1());
}
TEST(Day03, RepeatedDigitsLowReplace) {
  Day03Solution sol;
  std::vector<std::vector<int>> _input = {{1, 1, 2, 1, 1, 1, 3}};
  sol.setInput(_input);
  sol.SolvePart1();
  ASSERT_EQ(23, sol.getResultPart1());
}
TEST(Day03, RepeatedDigitsHigh) {
  Day03Solution sol;
  std::vector<std::vector<int>> _input = {{9, 9, 9, 8, 9, 9, 9}};
  sol.setInput(_input);
  sol.SolvePart1();
  ASSERT_EQ(99, sol.getResultPart1());
}
TEST(Day03, MultiUpdate) {
  Day03Solution sol;
  std::vector<std::vector<int>> _input = {{5, 9, 4, 9, 8, 3}};
  sol.setInput(_input);
  sol.SolvePart1();
  ASSERT_EQ(99, sol.getResultPart1());
}
TEST(Day03, Sum) {

  Day03Solution sol;
  std::vector<std::vector<int>> _input = {
      {5, 9, 4, 9, 8, 3}, {1, 1, 1, 1, 1, 1, 2}, {1, 1, 2, 1, 1, 1, 3}};
  sol.setInput(_input);
  sol.SolvePart1();
  ASSERT_EQ(99 + 12 + 23, sol.getResultPart1());
}
TEST(Day03, LastDigit) {

  Day03Solution sol;
  std::vector<std::vector<int>> _input = {{1, 1, 2, 4, 1, 1, 2}};
  sol.setInput(_input);
  sol.SolvePart1();
  ASSERT_EQ(42, sol.getResultPart1());
}
