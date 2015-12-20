## Makefile.am -- Process this file with automake to produce Makefile.in
ACLOCAL_AMFLAGS = -I m4 ${ACLOCAL_FLAGS}

if BUILD_TESTS
TESTS_PATH = test
else
TESTS_PATH =
endif

SUBDIRS = src include $(TESTS_PATH)

MAINTAINERCLEANFILES = \
	m4		\
	$(NULL)






