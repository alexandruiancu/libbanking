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

#include <libxml/tree.h>

#include "transactions_csv.h"
#include "transactions_cfg.h"

class TransactionsTree
{
 public:
  TransactionsTree();

  int set_transactions_csv(const TransactionsFile &csv);
  int set_transactions_cfg(const TransactionsClassesCfg &cfg);
  int classify_transactions(xmlNodePtr pTransactionsRoot);

  TransactionsFile m_csv;
  TransactionsClassesCfg m_cfg;
};
