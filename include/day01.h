#include <tuple>
#include <vector>
class Day01Solution {
public:
  Day01Solution() = default;
  void ReadFromFile();
  void Simulate();

  std::vector<std::tuple<char, int>> getFormattedInput() const {
    return m_input;
  }
  int getResultPart1() const { return m_result1; }
  int getResultPart2() const { return m_result2; }

#ifdef DEBUGTEST
  void setFormattedInput(std::vector<std::tuple<char, int>> _input) {
    m_input = _input;
  }
#endif

private:
  static constexpr const char *m_filename = "input/day01.txt";
  std::vector<std::tuple<char, int>> m_input;
  int m_result1{0};
  int m_result2{0};
};
