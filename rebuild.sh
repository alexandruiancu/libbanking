#!/bin/sh

autoreconf

#./configure --enable-debug=true --with-csvparser=/home/andu/src/dev/c_c++/libcsv_parser++-1.0.0 --with-libxml=/usr --with-gtest=/home/andu/src/dev/c_c++/git/googletest/googletest CFLAGS="-D__ATTACH_DEBUG__" CXXFLAGS="-D__ATTACH_DEBUG__"

#./configure --enable-debug=true --with-csvparser=/home/andu/src/dev/c_c++/libcsv_parser++-1.0.0 --with-libxml=/usr --with-gtest=/home/andu/src/dev/c_c++/git/googletest/googletest

./configure --enable-debug=true --with-csvparser=/home/andu/src/src/github_work/libcsv_parser-1.0.0/libcsv_parser++-1.0.0 --with-libxml=/usr --with-gtest=/home/andu/src/src/github_work/googletest/googletest

make VERBOSE=1





