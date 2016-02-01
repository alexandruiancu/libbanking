## Makefile.am -- Process this file with automake to produce Makefile.in

lib_LTLIBRARIES = libbtgraph.la
libbtgraph_la_SOURCES = transaction.cpp t_class.cpp t_csv.cpp t_cfg.cpp t_xml.cpp
libbtgraph_la_CFLAGS = -I$(top_srcdir)/include -I@CSVPARSER_DIR@/include -I@LIBXML_DIR@/include/libxml2 $(libbtgraph_CFLAGS) $(CFLAGS)
libbtgraph_la_CXXFLAGS = -I$(top_srcdir)/include -I../@CSVPARSER_DIR@/include -I@LIBXML_DIR@/include/libxml2 $(libbtgraph_CFLAGS) $(CXXFLAGS)
libbtgraph_la_LDFLAGS = -L../@CSVPARSER_DIR@/.libs -L@LIBXML_DIR@/lib64
libbtgraph_la_LIBADD = -lcsv_parser -lxml2 $(libbtgraph_LIBS)









