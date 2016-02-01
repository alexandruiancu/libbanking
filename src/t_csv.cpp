/*

 libbtgraph - bank account transactions log analyzer

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

#include <algorithm>
#include <fstream>
#include <csv_parser/csv_parser.hpp>
#include "t_csv.h"

TCsvFile::TCsvFile()
{
}

TCsvFile::TCsvFile(const std::string &sPath)
{
  if ( 0 != load(m_transactions, sPath.c_str()) ||
       filter_credit(m_transactions) )
    m_transactions.clear();
}

int TCsvFile::load(Transactions &ts, const char *szPath)
{
  if ( nullptr == szPath )
    return 1;

  ts.clear();

  csv_parser parser;
  if ( !parser.init(szPath) )
    return 1;
  parser.set_enclosed_char('\"', ENCLOSURE_OPTIONAL);
  
  if ( !parser.has_more_rows() )
    return 2;
  const csv_row &rowAttributes = parser.get_row();
  Transaction *pT = nullptr;
  bool bDiscardTransaction = false;
  std::vector<csv_row> transaction_rows;

  while ( parser.has_more_rows() )
    {
      const csv_row &row = parser.get_row();
      if ( is_start_row(row) )
	{
	  if ( !bDiscardTransaction && 0 != transaction_rows.size() )
	    {
	      pT->add_attributes(transaction_rows);
	      ts.push_back(pT);
	      pT = nullptr;
	    }

	  if ( nullptr == pT )
	    pT = new Transaction();
	  bDiscardTransaction =
	    (0 != pT->initialize() ||
	     0 != pT->set_primary_attributes(rowAttributes) ||
	     0 != pT->set_primary_attribute_values(row));
	  transaction_rows.clear();
	}
      else
	transaction_rows.push_back(row);
    }

  // add last transaction
  if ( !bDiscardTransaction && 0 != transaction_rows.size() &&
       nullptr != pT )
    {
      pT->add_attributes(transaction_rows);
      ts.push_back(pT);
    }
  return 0;
}

int TCsvFile::filter_credit(Transactions &ts)
{
  int nIndex = -1;
  for (Transactions::iterator it = ts.begin(); it != ts.end(); ++it)
    {
      if ( 0 == (*it)->get_credit_index(nIndex) )
	break;
    }
  ts.erase(std::remove_if(ts.begin(), ts.end(), IsCreditTransaction(nIndex)), ts.end());
  
  return 0;
}

bool TCsvFile::is_start_row(vs vRow)
{
  if ( 0 < vRow.size() && !vRow[0].empty() )
    return true;
  return false;
}

int TCsvFile::as_xml(const std::string &sPath)
{
  std::fstream sOut(sPath, ios_base::out | ios_base::trunc);
  sOut << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\
<transactions>\
";
  bool bWithError = false;
  for_each(m_transactions.begin(), m_transactions.end(), [&] (Transaction *pT)
	   {
	     std::string sOutTemp;
	     if ( 0 == pT->as_xml(sOutTemp) )
	       sOut << sOutTemp;
	     else
	       bWithError = false;
	   });
  if ( bWithError )
    {
      sOut.close();
      return 1;
    }
  sOut << "</transactions>";
  sOut.close();
  return 0;
}







