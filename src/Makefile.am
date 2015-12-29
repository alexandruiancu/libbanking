## Makefile.am -- Process this file with automake to produce Makefile.in

lib_LTLIBRARIES = libbanking.la
libbanking_la_SOURCES = transaction.cpp transaction_class.cpp transactions_csv.cpp transactions_tree.cpp
libbanking_la_CFLAGS = -I$(top_srcdir)/include -I@CSVPARSER_DIR@/include $(CFLAGS)
libbanking_la_CXXFLAGS = -I$(top_srcdir)/include -I@CSVPARSER_DIR@/include $(CXXFLAGS)
libbanking_la_LDFLAGS = -L@CSVPARSER_DIR@/lib
libbanking_la_LIBADD = -lcsv_parser








