//
// Created by rick on 2017/7/27.
//

#include <boost/multi_array.hpp>
#include <iostream>
#include <algorithm>
#include <cstring>

#include <gtest/gtest.h>

using namespace boost;
using namespace std;

TEST(Multiarray, array1) {
  multi_array<char, 1> a{extents[6]};
  a[0] = 'B';
  a[1] = 'o';
  a[2] = 'o';
  a[3] = 's';
  a[4] = 't';
  a[5] = '\0';

  cout << a.origin() << endl;
}

TEST(Multiarray, two_dimensional_array) {
  typedef multi_array<char, 2>::array_view<1>::type array_view;
  using range = multi_array_types::index_range;

  multi_array<char, 2> a{extents[2][6]};

  array_view view = a[indices[0][range{0,5}]];
  memcpy(view.origin(), "tsooB", 6);
  std::reverse(view.begin(), view.end());

  cout << view.origin() << endl;

  multi_array<char, 2>::reference subarray = a[1];
  memcpy(subarray.origin(),"C++", 4);
  cout << subarray.origin() << endl;

}