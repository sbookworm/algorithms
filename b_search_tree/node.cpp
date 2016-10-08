#include <iostream>
#include "node.h"

using namespace std;

node::node() {
  key = 0;
  value = 0;
  left = NULL;
  right = NULL;
}

node::node(int k, int v) {
  key = k;
  value = v;
  left = NULL;
  right = NULL;
}


node::~node() {
  
}

int node::get_value() {
  return value;
}
