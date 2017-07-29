//
// Created by rick on 2017/7/28.
//
#include <boost/algorithm/cxx11/one_of.hpp>
#include <array>
#include <iostream>
#include <gtest/gtest.h>

using namespace boost::algorithm;
using namespace std;

TEST(algorithm,one_of) {
  array<int, 6> a{{0,5,2,1,4,3}};
  auto predicate = [](int i){return i == 4;};
  cout.setf(ios::boolalpha);
  cout << one_of(a.begin(), a.end(), predicate) << endl;
  cout << one_of_equal(a.begin(),a.end(), 4) << endl;
}
