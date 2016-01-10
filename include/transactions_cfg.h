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

#include "transaction_class.h"

class TransactionsClassesCfg
{
 public:
  TransactionsClassesCfg();
  int load_classification(const char *szFilePath);
  int load_classification_old(const char *szFilePath);
  int load_classification_new(const char *szFilePath);
  int as_xml(std::string &sOut);
  const TransactionClasses &getTransactionClasses() const;
  
 protected:
  int build_classes_tree(std::vector<xmlNodePtr> &arrClasses);
  TransactionClasses m_arrRoots;
};




