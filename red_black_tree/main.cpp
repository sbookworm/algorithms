#include <iostream>
#include "node.h"
#include "red_black_tree.h"

using namespace std;

int main() {
  red_black_tree * p_tree = new red_black_tree();
  
  delete p_tree;
  return 0;
}
