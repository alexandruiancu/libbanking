dnl -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ(2.61)

AC_INIT([libbankingc++],
	[0.1.0],
	[alexandru.iancu@gmail.com])

AC_CONFIG_AUX_DIR(config)
AC_CONFIG_SRCDIR([src/transaction.cpp])
AC_CONFIG_HEADERS(config.h)
AC_CONFIG_MACRO_DIR([m4])
AM_INIT_AUTOMAKE
## TODO: ce inseamna parametrii AM_INIT_AUTOMAKE ?
# AM_INIT_AUTOMAKE([1.11 tar-ustar dist-xz no-dist-gzip -Wno-portability foreign])
# AM_MAINTAINER_MODE([enable])
# AM_SILENT_RULES([yes])

# Checks for programs.
AC_PROG_CC
AC_PROG_CXX
AC_PROG_LIBTOOL
AC_PROG_INSTALL

## don't rerun to this point if we abort
AC_CACHE_SAVE

CXXFLAGS="-std=c++11 $CXXFLAGS"

# Checks for flags
AC_ARG_ENABLE([debug],
	[AS_HELP_STRING([--enable-debug], ["Add -DDEBUG -Wall -g3 flags to compiler"])],
	[
	CFLAGS="-DDEBUG -Wall -g3 $CFLAGS"
	CXXFLAGS="-DDEBUG -Wall -g3 $CXXFLAGS"
	],
	[])

# Checks for libraries.
AC_ARG_WITH([csvparser],
	[AS_HELP_STRING([--with-csvparser],["Add csv_parser lib include and link paths"])],
	[
	CSVPARSER_DIR=$with_csvparser
	AC_SUBST(CSVPARSER_DIR)
	],
	[AC_MSG_ERROR([missing csv_parser library.])])


AC_CONFIG_FILES([
	Makefile
	include/Makefile
	src/Makefile
])

AC_OUTPUT

echo "
    libbankingc++ $VERSION

    prefix: 	    ${prefix}
    C compiler:	    ${CC}
    C++ compiler:   ${CXX}
    LDFLAGS:	    ${LDFLAGS}
    CSVPARSER_DIR:  ${CSVPARSER_DIR}

    Now type 'make' to build $PACKAGE
"






