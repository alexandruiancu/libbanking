#include "2Dmatrix.h"
#include <string>

template<class T>
matrix<T>::matrix()
{
  m_nRowLength = m_nColumnLength = 0;
}

template<class T>
int matrix<T>::row_push_back(std::vector<T> &&row)
{
  if ( 0 == m_nRowLength )
    m_nRowLength = row.size();
  else if ( m_nRowLength != row.size() )
    return 1;

  std::move(row.begin(), row.end(), std::back_inserter(m_data));
  m_nColumnLength = m_data.size()/m_nRowLength;
  
  return 0;
}

template<class T>
int matrix<T>::row_pop_front(std::vector<T> &rowReturn)
{
  if ( 0 == m_nColumnLength )
    return 1;
  for ( unsigned int i = 0; i < m_nRowLength; i++ )
    rowReturn[i] =  std::move(m_data[i]);
  m_data.erase(m_data.begin(), m_data.begin()+m_nRowLength);
  return 0;
}

template class matrix<std::string>;
