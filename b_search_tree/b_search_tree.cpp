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
  if(p_node->get_left() != NULL) {
    destroy_tree(p_node->get_left());
  }
  if(p_node->get_right() != NULL) {
    destroy_tree(p_node->get_right());
  }
  delete(p_node);
}

void b_search_tree::set_root(node * r) {
    root = r;
}

void b_search_tree::insert_node(node * p_node, node * p_current) {
  if(p_node == NULL) {
    return;
  }
  int key = p_node->get_key();
  int current_key = p_current->get_key();
  if(key < current_key) {
    if(p_current->get_left() != NULL) {
      insert_node(p_node, p_current->get_left());
    } else {
      p_current->set_left(p_node);
    }
  } else if (key > current_key) {
    if(p_current->get_right() != NULL) {
      insert_node(p_node, p_current->get_right());
    } else {
      p_current->set_right(p_node);
    }
  }
}

void b_search_tree::delete_node(int key) {
}

node * b_search_tree::search_node(int key) {
  return NULL;
}

void b_search_tree::print_mid_iter(node * p_node) {
  if(p_node == NULL) {
    return;
  }
  if(p_node->get_left() != NULL) {
    print_mid_iter(p_node->get_left());
  }
  cout<<p_node->get_value()<<" ";
  if(p_node->get_right() != NULL) {
    print_mid_iter(p_node->get_right());
  }
}

