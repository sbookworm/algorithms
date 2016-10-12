#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "node.h"
#include "b_search_tree.h"

using namespace std;

int MAX_RAND = 200;

int main() {
  std::cout<<"test"<<endl;
  srand((unsigned)time(0));
  //node *  a = new node(1, 2);
  //cout << a->get_value() << endl;

  // init a b search tree
  b_search_tree * p_tree = new b_search_tree();
  int root_key = 50;
  int root_value = root_key;
  node * p_root = new node(root_key, root_value);
  
  p_tree->set_root(p_root);
  for(int i=1; i<50; i++) {
    int key = ((int)rand())%MAX_RAND;
    int val = key;
    node * p_rand_node = new node(key, val);
    

  }
  
  
  delete(p_tree);
  //delete(a);

  return 0;

}
