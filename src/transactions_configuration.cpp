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
#include "types.h"
#include "transactions_configuration.h"

CategoryConfig::CategoryConfig(const std::string &sConfigFilePath)
{
  if ( 0 != load_config_file(sConfigFilePath) )
    m_categories.clear();
}

int CategoryConfig::load_config_file(const std::string &sPath)
{
  csv_parser parser;
  if ( !parser.init(sPath.c_str()) )
    return 1;
  parser.set_enclosed_char('\"', ENCLOSURE_OPTIONAL);
  
  if ( !parser.has_more_rows() )
    return 2;

  while ( parser.has_more_rows() )
    {
      const csv_row &row = parser.get_row();
      if ( 1 > row.size() )
	continue;
      std::vector<std::string>::const_iterator it = row.begin();
      ++it;
      vs vCrtTags;
      for (; it != row.end(); ++it)
	  vCrtTags.push_back(*it);
      m_categories[*row.begin()] = vCrtTags;
    }
  return 0;
}

// int CategoryConfig::classify_transactions(t_c_node &root)
// {
//   return 0;
// }



