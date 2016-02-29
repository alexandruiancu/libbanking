// resizable 2D matrix

#include <vector>

template<class T>
class matrix
{
  typedef std::vector<T> T2Dmatrix;
 public:
  matrix();
  int row_push_back(std::vector<T> &&row);
  int row_pop_front(std::vector<T> &rowReturn);
 protected:
  T2Dmatrix m_data;
  unsigned int m_nRowBegin, m_nRowEnd;
  unsigned int m_nRowLength, m_nColumnLength;
};
