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

TEST(TransactionCSVFileTests, General) {
  Transactions ts;
  TransactionsFile tf("transactions.csv");
  EXPECT_EQ (0, tf.load_transactions_file(ts, "transactions.csv"));
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


