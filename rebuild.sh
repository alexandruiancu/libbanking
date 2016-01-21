#!/bin/sh

make clean

autoreconf

# debug
#./configure --enable-debug --with-csvparser=../libcsv_parser-1.0.0/libcsv_parser++-1.0.0 --with-libxml=/usr --with-gtest=../googletest
# release
./configure --with-csvparser=../libcsv_parser-1.0.0/libcsv_parser++-1.0.0 --with-libxml=/usr --with-gtest=../googletest

make VERBOSE=1





