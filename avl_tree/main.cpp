#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "node.h"
#include "avl_tree.h"


using namespace std;

int MAX_RAND = 500;

int main() {
  srand((unsigned)time(0));
  avl_tree * p_tree = new avl_tree();

  for(int i=0; i<10; i++) {
    int key = ((int)rand())%MAX_RAND;;
    int value = key;
    node * p_node = new node(key, value);
    p_tree->insert(p_node);
  }
  p_tree->print();
  delete p_tree;
  return 0;
}
