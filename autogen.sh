#!/bin/sh
# Run this to generate all the initial makefiles, etc.

test -n "$srcdir" || srcdir=`dirname "$0"`
test -n "$srcdir" || srcdir=.

OLDDIR=`pwd`
cd $srcdir

LIBTOOLIZE=`which libtoolize`
if test -z $LIBTOOLIZE; then
    echo "*** No LIBTOOLIZE found, please install it ***"
    exit 1
fi

libtoolize
aclocal
autoheader
automake --add-missing

AUTORECONF=`which autoreconf`
if test -z $AUTORECONF; then
    echo "*** No autoreconf found, please install it ***"
    exit 1
fi

autoreconf --force --install --verbose

cd $OLDDIR
#echo "$@"
test -n "$NOCONFIGURE" || "$srcdir/rebuild.sh" "$@"

