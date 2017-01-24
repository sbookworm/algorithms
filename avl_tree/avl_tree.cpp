#include <iostream>
#include <algorithm>
#include "node.h"
#include "avl_tree.h"

using namespace std;

int NUM_SIZE = 3; // set three space for number

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
  if(p_node->get_left() != NULL) {
    destroy_tree(p_node->get_left());
  }
  if(p_node->get_right() != NULL) {
    destroy_tree(p_node->get_right());
  }
  delete p_node;
}

int avl_tree::insert(node * p_node) {
  if(this->p_root == NULL) {
    this->p_root = p_node;
    return 0;
  }
  return insert_node(p_node, this->p_root);
}

int avl_tree::insert_node(node * p_node, node * p_current) {
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

node * remove(int k) {
  return NULL;
}

node * find(int k) {
  return NULL;
}

void avl_tree::balance() {

}

int avl_tree::get_hight(node * p_node) {
  if (p_node == NULL) {
    return 0;
  }
  return max(get_hight(p_node->get_left()), get_hight(p_node->get_right())) + 1;
}

void avl_tree::print() {
  //int hight = get_hight(this->p_root);
  //cout<<hight<<endl;
  //int tab = hight/2 + 1;

  //cout<<

}

void avl_tree::print_node(node * p_node, int deepth) {
  cout<<p_node->get_value()<<endl;
  print_node(p_node->get_left(), deepth+1);
  print_node(p_node->get_right(), deepth+1);
}
