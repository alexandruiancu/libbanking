dnl -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ(2.61)

AC_INIT([libbanking],
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

DEFAULT_CFLAGS=$CFLAGS
DEFAULT_CXXFLAGS=$CXXFLAGS

# add flags
AC_ARG_ENABLE([debug],
	[AS_HELP_STRING([--enable-debug], ["Add debug flags to compiler"])],
	[
	CFLAGS="-DDEBUG -D__ATTACH_DEBUG__ -Wall -g3 -O0"
	CXXFLAGS="-DDEBUG -D__ATTACH_DEBUG__ -Wall -g3 -O0"
	],
	[])

AC_ARG_ENABLE([c++11],
	[AS_HELP_STRING([--disable-c++11], ["Before C++11 compilation"])],
	[],
	[
	CXXFLAGS="-std=c++11 $CXXFLAGS"
	])

# csv library
AC_ARG_WITH([csvparser],
	[AS_HELP_STRING([--with-csvparser],["Add csv_parser lib include and link paths"])],
	[
	CSVPARSER_DIR=$with_csvparser
	AC_SUBST(CSVPARSER_DIR)
	],
	[AC_MSG_ERROR([missing csv_parser library.])])

# libxml library
AC_ARG_WITH([libxml],
	[AS_HELP_STRING([--with-libxml],["Add libxml lib include and link paths"])],
	[
	LIBXML_DIR=$with_libxml
	AC_SUBST(LIBXML_DIR)
	],
	[AC_MSG_ERROR([missing libxml library.])])

# add google test library
AC_ARG_WITH([gtest],
	[AS_HELP_STRING([--with-gtest],["Add google test framework library include and link paths"])],
	[
	GTEST_DIR=$with_gtest
	AC_SUBST(GTEST_DIR)
	HAVE_TEST=yes
	],
	[
	AC_MSG_ERROR([missing google test framework library.])
	HAVE_TEST=no
	])

PKG_CHECK_MODULES([libbanking], libxml++-2.6 >= 2.30)
AC_SUBST(libbanking_CFLAGS)
AC_SUBST(libbanking_LIBS)

AM_CONDITIONAL([BUILD_TESTS],[test "$HAVE_TEST" = "yes"])

AC_CONFIG_FILES([
	Makefile
	include/Makefile
	src/Makefile
	test/Makefile
])

AC_OUTPUT

echo "
    $PACKAGE $VERSION

    prefix:		${prefix}
    C compiler:		${CC}
    C++ compiler:	${CXX}
    default C flags:	${DEFAULT_CFLAGS}
    default C++ flags:	${DEFAULT_CXXFLAGS}
    C flags:		${CFLAGS}
    C++ flags:		${CXXFLAGS}
    LDFLAGS:		${LDFLAGS}
    CSVPARSER_DIR:	${CSVPARSER_DIR}
    LIBXML_DIR:	        ${LIBXML_DIR}
    GTEST_DIR:	        ${GTEST_DIR}
    HAVE_TEST:		$HAVE_TEST

    Now type 'make' to build $PACKAGE
"






