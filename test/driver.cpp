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

#include <unistd.h>
#include "gtest/gtest.h"
#include "transaction.h"
#include "t_csv.h"
#include "t_cfg.h"

#include <locale.h>
#include <langinfo.h>
#include <iostream>
#include <ostream>
#include <sstream>
#include <iomanip>

TEST(CSVFile, General) {
  Transactions ts;
  TFile tf("transactions_in.csv");
  EXPECT_EQ (0, tf.load(ts, "transactions_in.csv"));
}

TEST(ParseNumericStrings_C, General) {
  //use C locale
  //sugestion: https://sourceware.org/ml/libc-help/2015-10/msg00002.html
  int nLocType = LC_NUMERIC;
  const char *pOldLocale = setlocale(nLocType, "ro_RO.UTF-8");
  double d1 = 1000.43, d2;
  sscanf("1.000,43", "%'lf", &d2);
  EXPECT_EQ (d1, d2);
  setlocale(nLocType, pOldLocale);
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

TEST(TClassesCfg_load_classification, General) {
  TClassesCfg tt;
  EXPECT_EQ (0, tt.load_classification("classification.xml"));
}

int main(int argc, char **argv) {
#ifdef __ATTACH_DEBUG__
  int i = 100000;
  while ( 0 < i )
    {
      usleep(500);
      i--;
    }
#endif // __ATTACH_DEBUG__
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}


