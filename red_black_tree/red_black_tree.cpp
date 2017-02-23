#include <iostream>
#include "red_black_tree.h"
#include "node.h"

red_black_tree::red_black_tree() {
  p_root = NULL;
}

red_black_tree::~red_black_tree() {
  destroy(p_root);
}

void red_black_tree::destroy(node * p_node) {
  if(p_node != NULL) {
    destroy(p_node->get_left());
    destroy(p_node->get_right());
    delete p_node;
  }
}

void red_black_tree::set_root(node * p_node) {
  this->p_root = p_node;
}

node * red_black_tree::get_root() {
  return this->p_root;
}

int red_black_tree::insert(node * p_node) {
  if(p_root == NULL) {
    p_node->set_color(1);
    p_root = p_node;
    return 0;
  }
  int result = insert_node(p_node, p_root);
  
  return result;
}

int red_black_tree::insert_node(node * p_node, node * p_current) {
  int k = p_node->get_key();
  int m = p_current->get_key();
  if (k == m) {
    return -1;
  }
  if(k < m && p_current->get_left() != NULL) {
    return insert_node(p_node, p_current->get_left());
  }
  if(k > m && p_current->get_right() != NULL) {
    return insert_node(p_node, p_current->get_right());
  }
  if(k < m && p_current->get_left() == NULL) {
    p_current->set_left(p_node);
    p_node->set_parent(p_current);
  } else if(k > m && p_current->get_right() == NULL) {
    p_current->set_right(p_node);
    p_node->set_parent(p_current);
  }
  return 0;
}


node * red_black_tree::find(int k) {
  return NULL;
}

int red_black_tree::remove(int k) {
  return 0;
}
