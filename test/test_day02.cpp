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
  ASSERT_EQ(sol.getResultPart1(), 11 + 22 + 33 + 44 + 55 + 66 + 77 + 88 + 99);
}

TEST(Day02, Part2Example) {
  Day02Solution sol;
  sol.parseInput();
  sol.SolvePart2();
  ASSERT_EQ(sol.getResultPart2(), 4174379265);
}
TEST(Day02, Part2TwoDigitSingleInput) {
  Day02Solution sol;
  sol.setInput({{565655, 565657}});
  sol.SolvePart2();
  ASSERT_EQ(sol.getResultPart2(), 565656);
}
TEST(Day02, Part2OneDigitSingleInput) {
  Day02Solution sol;
  sol.setInput({{11111, 11112}});
  sol.SolvePart2();
  ASSERT_EQ(sol.getResultPart2(), 11111);
}
TEST(Day02, Part2ThreeAnswers) {
  Day02Solution sol;
  sol.setInput({{101101, 101102}});
  sol.SolvePart2();
  ASSERT_EQ(sol.getResultPart2(), 101101);
}
TEST(Day02, Part2BunchOfZeros) {
  Day02Solution sol;
  sol.setInput({{100001, 100100}});
  sol.SolvePart2();
  ASSERT_EQ(sol.getResultPart2(), 100100);
}
TEST(Day02, Part2OneZeroRepeat) {
  Day02Solution sol;
  sol.setInput({{101010, 101110}});
  sol.SolvePart2();
  ASSERT_EQ(sol.getResultPart2(), 101010 + 101101);
}
TEST(Day02, Part2Invalid) {
  Day02Solution sol;
  sol.setInput({{222221, 222222}});
  sol.SolvePart2();
  ASSERT_EQ(sol.getResultPart2(), 222222);
}
TEST(Day02, Part2EdgeCase) {
  Day02Solution sol;
  sol.setInput({{1, 22}});
  sol.SolvePart2();
  ASSERT_EQ(sol.getResultPart2(), 33);
}
