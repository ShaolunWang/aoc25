#include <cstdint>
#include <future>
#include <utility>
#include <vector>
class Day02Solution {
public:
  Day02Solution() = default;
  void parseInput();
  void SolvePart1();
  void SolvePart2();
  uint64_t getResultPart1() const { return m_result1; }
  uint64_t getResultPart2() const { return m_result2; }
#ifdef DEBUGTEST
  void setInput(const std::vector<std::pair<uint64_t, uint64_t>> &_input) {
    m_input = _input;
  }
#endif

private:
  static constexpr const char *m_filename = "input/day02.txt";
  uint64_t m_result1{0};
  uint64_t m_result2{0};
  std::vector<std::pair<uint64_t, uint64_t>> m_input;

  static uint64_t iterOverRangePart1(uint64_t a, uint64_t b);
  static uint64_t iterOverRangePart2(uint64_t a, uint64_t b);

  std::vector<std::future<uint64_t>> m_futuresP1;
  std::vector<std::future<uint64_t>> m_futuresP2;
};
