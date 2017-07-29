//
// Created by rick on 2017/7/28.
//
#include <boost/container/vector.hpp>
#include <boost/container/stable_vector.hpp>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;
using namespace boost::container;

struct animal {
  boost::container::vector<animal> children;
};

TEST(Container, Recursive_Containers) {
  animal parent, child1, child2;
  parent.children.push_back(child1);
  parent.children.push_back(child2);
}

TEST(Container, stable_vector) {
  stable_vector<int> v(2,1);
  int &i = v[1];
  v.erase(v.begin());
  cout << i << endl;
}

