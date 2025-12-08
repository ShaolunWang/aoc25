class Day02Solution {
public:
  Day02Solution() = default;
  static constexpr const char *m_filename = "input/day02.txt";

  int getResultPart1() const { return m_result1; }
  int getResultPart2() const { return m_result2; }

private:
  int m_result1{0};
  int m_result2{0};
};
