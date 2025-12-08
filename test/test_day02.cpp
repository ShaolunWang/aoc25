#include "day02.h"
#include "gtest/gtest.h"

TEST(Day02, Part1Example) {
  Day02Solution sol;
  sol.parseInput();
  sol.SolvePart1();
  ASSERT_EQ(sol.getResultPart1(), 1227775554);
}
TEST(Day02, Part1Across34) {
  Day02Solution sol;
  sol.setInput({{613, 1077}});
  sol.SolvePart1();
  ASSERT_EQ(sol.getResultPart1(), 1010);
}
TEST(Day02, Part1WithLeading0) {
  Day02Solution sol;
  sol.setInput({{905, 1015}});
  sol.SolvePart1();
  ASSERT_EQ(sol.getResultPart1(), 1010);
}
TEST(Day02, Part1With0) {
  Day02Solution sol;
  sol.setInput({{0, 100}});
  sol.SolvePart1();
  ASSERT_EQ(sol.getResultPart1(), 11+22+33+44+55+66+77+88+99);
}
