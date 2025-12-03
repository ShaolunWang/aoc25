#include "day01.h"
#include "gtest/gtest.h"
#include <vector>
TEST(Example, Part1) {
  Day01Solution sol;
  sol.ReadFromFile();
  sol.Simulate();
  ASSERT_EQ(sol.getResultPart1(), 3);
}

TEST(Example, Part2) {
  Day01Solution sol;
  sol.ReadFromFile();
  sol.Simulate();
  ASSERT_EQ(sol.getResultPart2(), 6);
}

TEST(SimpleStep, Part2Rot2) {
  Day01Solution sol;
  std::vector<std::tuple<char, int>> _input = {{'R', 1000}, {'L', 1000}};
#ifdef TEST
  sol.setFormattedInput(_input);
  sol.Simulate();
  ASSERT_EQ(sol.getResultPart2(), 20);
#endif
}

TEST(SimpleStep, Part2ComplexRot) {
  Day01Solution sol;
  /// R1000 # +10 (50) 10
  // L1000 # +10 (50) 20
  // L50   # +1  (0)  21
  // R1    # +0  (1)  21
  // L1    # +1  (0)  22
  // L1    # +0  (99) 22
  // R1    # +1  (0)  23
  // R100  # +1  (0)  24
  // R1    # +0  (1)  24
  std::vector<std::tuple<char, int>> _input = {
      {'R', 1000}, {'L', 1000}, {'L', 50},  {'R', 1},
      {'L', 1},    {'L', 1},  {'R', 100}, {'R', 1}};
#ifdef TEST
  sol.setFormattedInput(_input);
  sol.Simulate();
  ASSERT_EQ(sol.getResultPart2(), 24);
#endif
}
TEST(SimpleStep, Part2RotToZero) {
  Day01Solution sol;
  std::vector<std::tuple<char, int>> _input = {
      {'R', 150}, {'L', 50}, {'R', 50}};
#ifdef TEST
  sol.setFormattedInput(_input);
  sol.Simulate();
  ASSERT_EQ(sol.getResultPart2(), 3);
#endif
}
