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

#include <unistd.h>
#include "gtest/gtest.h"
#include "transaction.h"
#include "transactions_csv.h"

#include <locale.h>
#include <langinfo.h>
#include <iostream>
#include <ostream>
#include <sstream>
#include <iomanip>

TEST(TransactionCSVFileTests, General) {
  Transactions ts;
  TransactionsFile tf("transactions.csv");
  EXPECT_EQ (0, tf.load_transactions_file(ts, "transactions.csv"));
}

TEST(ParseNumericStrings_C, General) {
  //use C locale
  const char *pOldLocale = setlocale(LC_ALL, "ro_RO.UTF-8");
  double d1 = 1000.43, d2;
  sscanf("1.000,43", "%'lf", &d2);
  EXPECT_EQ (d1, d2);
  setlocale(LC_NUMERIC, pOldLocale);
}

TEST(ParseNumericStrings_Cpp, General) {
  // use C++ locale
  std::stringstream ss("1.000,43");
  std::locale loc("ro_RO.UTF-8");
  ss.imbue(loc);
  //char separator = std::use_facet< std::numpunct<char> >(ss.getloc()).thousands_sep();
  //std::cout << separator << std::endl;
  double d;
  ss >> d;
  EXPECT_EQ (1000.43, d);
}

int main(int argc, char **argv) {
  // int i = 100000;
  // while ( 0 < i )
  //   {
  //     usleep(500);
  //     i--;
  //   }
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}


