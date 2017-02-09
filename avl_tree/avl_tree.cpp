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

void avl_tree::left_rotate(node * p_node) {
  node * p_right = p_node->get_right();
  node * p_right_left = p_right->get_left();
  node * p_parent = p_node->get_parent();

  if (p_node->get_parent() == NULL) {
    p_root = p_right;
  }

  p_right->set_parent(p_parent);
  p_right->set_left(p_node);

  p_node->set_parent(p_right);
  p_node->set_right(p_right_left);

  if (p_right_left) {
    p_right_left->set_parent(p_node);
  }
}


void avl_tree::right_rotate(node * p_node) {
  node * p_left = p_node->get_left();
  node * p_left_right = p_left->get_right();
  node * p_parent = p_node->get_parent();
  if (p_node->get_parent() == NULL) {
    p_root = p_left;
  }
  p_left->set_parent(p_parent);
  p_left->set_right(p_node);

  p_node->set_parent(p_left);
  p_node->set_left(p_left_right);

  if (p_left_right) {
    p_left_right->set_parent(p_node);
  }
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
