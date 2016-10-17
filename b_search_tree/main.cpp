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
  // init a b search tree
  b_search_tree * p_tree = new b_search_tree();
  int root_key = 50;
  int root_value = root_key;
  node * p_root = new node(root_key, root_value);
  
  p_tree->set_root(p_root);
  for(int i=1; i<19; i++) {
    int key = ((int)rand())%MAX_RAND;
    int val = key;
    cout<<key<<" ";
    node * p_rand_node = new node(key, val);
    p_tree->insert_node(p_rand_node, p_root);
  }
  cout<<endl;
  p_tree->print_mid_iter(p_root);
  delete(p_tree);
  return 0;
}
