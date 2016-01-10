/*

 libbankingc++ - bank account transactions log analyzer

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

#include <csv_parser/csv_parser.hpp>
#include "transaction.h"

Transaction::Transaction()
{
  initialize();
}

int Transaction::initialize()
{
  m_primary_attrs.clear();
  m_attrs.clear();

  return 0;
}

int Transaction::set_primary_attributes(const vs &vAttrs)
{
  if ( 0 >= vAttrs.size() )
    return 1;
  m_primary_attrs.resize(vAttrs.size());
  int nCount = 0;
  for ( vs::const_iterator it = vAttrs.begin(); it != vAttrs.end(); ++it )
    {// init attribute names
      m_primary_attrs[nCount].first = *it;
      nCount++;
    }
  return 0;
}

int Transaction::set_primary_attribute_values(const vs &vAttrVals)
{
  if ( m_primary_attrs.size() != vAttrVals.size() )
    return 1;
  int nCount = 0;
  for ( vs::const_iterator it = vAttrVals.begin(); it != vAttrVals.end(); ++it )
    {// init attribute values
      m_primary_attrs[nCount].second = *it;
      nCount++;
    }
  return 0;
}

int Transaction::add_attributes(const std::vector<vs> &vAttrVals)
{
  for ( std::vector<vs>::const_iterator it = vAttrVals.begin(); it != vAttrVals.end(); ++it )
    {
      vs crt = *it;
      for ( vs::const_iterator vit = crt.begin(); vit != crt.end(); ++vit )
	{
	  m_attrs.insert(*vit);
	}
    }
  return 0;
}

int Transaction::get_credit_index(int &nIndex)
{
  if ( 0 == m_primary_attrs.size() )
    return 1;

  int nCount = 0;
  for (std::vector<ps>::iterator it = m_primary_attrs.begin();
       it != m_primary_attrs.end(); ++it, nCount++)
    {
      if ( "Credit" == it->first )
	{
	  nIndex = nCount;
	  break;
	}
    }

  return 0;
}

int Transaction::get_transaction_details(std::string &sTransactionDetails)
{
  if ( 3 > m_primary_attrs.size() )
    return 1;
  sTransactionDetails = m_primary_attrs[2].second;
  return 0;
}

int Transaction::as_xml(std::string &sOut)
{
  sOut = "<transaction ";
  as_xml_primary_attributes(sOut);
  as_xml_attributes(sOut);
  sOut += "</transaction>";
  return 0;
}

int Transaction::as_xml_primary_attributes(std::string &sOut)
{
  for (std::vector<ps>::iterator it = m_primary_attrs.begin(); it != m_primary_attrs.end(); it++)
    {
      sOut += it->first + "=\"" + it->second + "\" ";
    }
  sOut += ">\n";
  return 0;
}

int Transaction::as_xml_attributes(std::string &sOut)
{
  sOut += "<properties>\n";
  for (ss::iterator it = m_attrs.begin(); it != m_attrs.end(); it++)
    {
      sOut += "<property>" + *it + "</property>\n";
    }
  sOut += "</properties>\n";
  return 0;
}

IsCreditTransaction::IsCreditTransaction(int nIndex)
{
  m_nCreditAttributeIndex = nIndex;
}

bool IsCreditTransaction::operator()(Transaction *pT) const
{
  return pT->m_primary_attrs[m_nCreditAttributeIndex].second.empty() ? false : true;
}

