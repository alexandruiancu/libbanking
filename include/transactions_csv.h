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

#pragma once

#include <string>
#include "transaction.h"

class TransactionsFile
{
 public:
  TransactionsFile();
  TransactionsFile(const std::string &sPath);
  int load_transactions_file(Transactions &ts, const char *szPath);
  //int load_transactions_file(Transactions &ts, const std::string &sPath);
  int filter_credit_transactions(Transactions &ts);
  bool is_transaction_start_row(std::vector<std::string> vRow);

  Transactions m_transactions;
};
