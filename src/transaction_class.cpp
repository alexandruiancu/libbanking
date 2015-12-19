/*

 libbankingc - bank account transactions log analyzer

 Copyright (C) 2015  Alexandru Iancu <alexandru.iancu@gmail.com>

 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 2
 of the License, or (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

*/

#include <string>
#include <sstream>
#include <map>
#include <csv_parser/csv_parser.hpp>
#include "transaction.h"
#include "transaction_class.h"

TransactionClass::TransactionClass(std::string sLabel, Transactions &ts)
{
  m_sLabel = sLabel;
  
  ps p;
  m_primary_attrs.push_back(p);//empty date
  m_primary_attrs.push_back(p);//empty second place

  p.first = "Debit";
  int nDebitValue = 0;
  std::stringstream ss;
  int nTemp = 0;
  for ( Transactions::iterator it = ts.begin(); it != ts.end(); ++it )
    {
      ss << it->m_primary_attrs[2].second;
      ss >> nTemp;
      nDebitValue += nTemp;
      ss.str("");//empty stream
    }
  ss << nDebitValue;
  p.second = ss.str();
  m_primary_attrs.push_back(p);
  p.first = "";
  p.second = "";
  m_primary_attrs.push_back(p);
  m_primary_attrs.push_back(p);
  m_primary_attrs.push_back(p);
}










