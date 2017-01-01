#include <iostream>
#include "node.h"
#include "avl_tree.h"

using namespace std;


avl_tree::avl_tree() {
  p_root = NULL;
}

avl_tree::~avl_tree() {
  if(p_root == NULL) {
    return;
  }
  destroy_tree(p_root);
}

void avl_tree::destroy_tree(node * p_node) {
  
}

int avl_tree::insert(node * p_node) {
  return 0;
}

node * remove(int k) {
  return NULL;
}

node * find(int k) {
  return NULL;
}
