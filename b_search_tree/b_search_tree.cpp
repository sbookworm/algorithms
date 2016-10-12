#include <iostream>
#include "node.h"
#include "b_search_tree.h"

using namespace std;

b_search_tree::b_search_tree() {
  root = NULL;
}

b_search_tree::b_search_tree(node * r) {
  root = r;
}

b_search_tree::~b_search_tree() {
  // TODO: implement destroy
  if(this->root == NULL) {
    return;
  }
  // postorder traversal
  destroy_tree(this->root);

}

void b_search_tree::destroy_tree(node * p_node) {

}

int b_search_tree::set_root(node * r) {
  if(root == NULL) {
    root = r;
    return 0;
  } else {
    return 1;
  }
}

void b_search_tree::insert_node(node n) {

}

void b_search_tree::delete_node(int key) {

}

node * b_search_tree::search_node(int key) {
  return NULL;
}
