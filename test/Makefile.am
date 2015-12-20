## Makefile.am -- Process this file with automake to produce Makefile.in

bin_PROGRAMS = tests
tests_SOURCES = driver.cpp
tests_CFLAGS = -I$(top_srcdir)/include -I@GTEST_DIR@ -isystem @GTEST_DIR@/include $(CFLAGS)
tests_CXXFLAGS = -I$(top_srcdir)/include -I@GTEST_DIR@ -isystem @GTEST_DIR@/include $(CXXFLAGS)
#tests_CFLAGS = -I$(top_srcdir)/include -I@GTEST_DIR@/include $(CFLAGS)
#tests_CXXFLAGS = -I$(top_srcdir)/include -I@GTEST_DIR@/include $(CXXFLAGS)
tests_LDFLAGS = -L@GTEST_DIR@ -L$(top_srcdir)/lib
#tests_LDADD = -lbanking -lgtest -lgtest_main -lpthread
tests_LDADD = -lbanking -lgtest -lpthread



