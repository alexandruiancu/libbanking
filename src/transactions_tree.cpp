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

#include <libxml/tree.h>

#include "transactions_tree.h"

int TransactionsTree::set_transactions(const TransactionsFile &csv)
{
  for ( Transactions::const_iterator it = csv.m_transactions.begin(); it != csv.m_transactions.end(); ++it )
    m_transactions.push_back(*it);

  return 0;
}

int TransactionsTree::set_transactions_cfg(const TransactionsClassesCfg &cfg)
{
  const TransactionClasses &transactionClasses = cfg.getTransactionClasses();
  for ( TransactionClasses::const_iterator it = transactionClasses.begin();
	it != transactionClasses.end(); ++it )
    m_cfgTransactionClasses.push_back(*it);

  return 0;
}

int TransactionsTree::classify_transactions(xmlNodePtr pTransactionsRoot)
{
  return 0;
}






