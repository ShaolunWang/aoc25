#include <array>
#include <future>
#include <vector>
class Day03Solution {
public:
  Day03Solution() = default;

  void parseInput();

  void SolvePart1();
  void SolvePart2();
  int getResultPart1() const { return m_result1; }
  uint64_t getResultPart2() const { return m_result2; }
#ifdef DEBUGTEST
  void setInput(std::vector<std::vector<int>> &_input) { m_input = _input; }
#endif
private:
  int m_result1{0};
  uint64_t m_result2{0};
  static constexpr const char *m_filename = "input/day03.txt";
  std::vector<std::vector<int>> m_input;
  static int iterOverRangePart1(const std::vector<int> &_vec);
  static uint64_t iterOverRangePart2(const std::vector<int> &_vec);

  std::vector<std::future<int>> m_futuresP1;
  std::vector<std::future<uint64_t>> m_futuresP2;
};
