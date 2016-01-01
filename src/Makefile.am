## Makefile.am -- Process this file with automake to produce Makefile.in

lib_LTLIBRARIES = libbanking.la
libbanking_la_SOURCES = transaction.cpp transaction_class.cpp transactions_csv.cpp transactions_tree.cpp
libbanking_la_CFLAGS = -I$(top_srcdir)/include -I@CSVPARSER_DIR@/include -I@LIBXML_DIR@/include/libxml2 $(CFLAGS)
libbanking_la_CXXFLAGS = -I$(top_srcdir)/include -I@CSVPARSER_DIR@/include -I@LIBXML_DIR@/include/libxml2 $(CXXFLAGS)
libbanking_la_LDFLAGS = -L@CSVPARSER_DIR@/.libs -L@LIBXML_DIR@/lib64
libbanking_la_LIBADD = -lcsv_parser -lxml2








