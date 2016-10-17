#include <iostream>
#include "node.h"
#include "b_search_tree.h"

using namespace std;

b_search_tree::b_search_tree() {
  p_root = NULL;
}

b_search_tree::b_search_tree(node * r) {
  p_root = r;
}

b_search_tree::~b_search_tree() {
  if(this->p_root == NULL) {
    return;
  }
  destroy_tree(this->p_root);
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
    p_root = r;
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
      p_node->set_parent(p_current);
    }
  } else if (key > current_key) {
    if(p_current->get_right() != NULL) {
      insert_node(p_node, p_current->get_right());
    } else {
      p_current->set_right(p_node);
      p_node->set_parent(p_current);
    }
  } else if (key == current_key) {
    delete(p_node);
    cout<<"duplicated key"<<endl;
  }
}

void b_search_tree::delete_node(int key) {
  node * searched = search_node(key, this->p_root);
  if(searched == NULL) {
    cout<<"cannot find deleted node"<<endl;
  } else {
    
    
  }
}

node * b_search_tree::search_node(int key, node * p_node) {
  if(p_node == NULL) {
    return NULL;
  }
  if(key == p_node->get_key()) {
    return p_node;
  }
  if(key<p_node->get_value() && p_node->get_left()!=NULL) {
    return search_node(key, p_node->get_left());
  }
  if(key>p_node->get_value() && p_node->get_right()!=NULL) {
    return search_node(key, p_node->get_right());
  }

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

