## Makefile.am -- Process this file with automake to produce Makefile.in

bin_PROGRAMS = tests
tests_SOURCES = driver.cpp
tests_CFLAGS = -I$(top_srcdir)/include -I@GTEST_DIR@/googletest -isystem @GTEST_DIR@/googletest/include -I@LIBXML_DIR@/include/libxml2 $(CFLAGS)
tests_CXXFLAGS = -I$(top_srcdir)/include -I../@GTEST_DIR@/googletest -isystem ../@GTEST_DIR@/googletest/include -I@LIBXML_DIR@/include/libxml2 $(CXXFLAGS)
tests_LDFLAGS = -L../@GTEST_DIR@/build/googlemock/gtest -L$(top_srcdir)/src/.libs -L@LIBXML_DIR@/lib64
tests_LDADD = -lbanking -lxml2 -lgtest -lpthread



