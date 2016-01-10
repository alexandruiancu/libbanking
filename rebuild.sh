#!/bin/sh

autoreconf

./configure --enable-debug=true --with-csvparser=../libcsv_parser-1.0.0/libcsv_parser++-1.0.0 --with-libxml=/usr --with-gtest=../googletest

make VERBOSE=1





