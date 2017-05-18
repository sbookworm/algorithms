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
  result += insert_fixup(p_node);  
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
  p_node->set_color(0);
  return 0;
}

int red_black_tree::insert_fixup(node * p_node) {
  node * p_current = p_node;
  while (p_current->get_parent()->get_color() == 0) {
    node * p_parent = p_current->get_parent();
    if(p_parent->get_parent()->get_left() == p_parent) {
      node * p_uncle = p_parent->get_parent()->get_right();
      if(p_uncle == NULL || p_uncle->get_color() == 1) {
        if(p_current == p_parent->get_left()) {
          p_parent->set_color(1);
          p_parent->get_parent()->set_color(0);
          right_rotate(p_parent->get_parent());
        } else if(p_current == p_parent->get_right()) {
          p_current = p_parent;
          left_rotate(p_parent);
        }
      } else if(p_uncle != NULL && p_uncle->get_color() == 0) {
        p_parent->get_parent()->set_color(0);
        p_parent->set_color(1);
        p_uncle->set_color(1);
        p_current = p_parent->get_parent();
      }

    } else if(p_parent->get_parent()->get_right() == p_parent) {
      node * p_uncle = p_parent->get_parent()->get_left();
      if(p_uncle == NULL || p_uncle->get_color() == 1) {
        if(p_current == p_parent->get_right()) {
          p_parent->set_color(1);
          p_parent->get_parent()->set_color(0);
          left_rotate(p_parent->get_parent());
        } else if(p_current == p_parent->get_left()) {
          p_current = p_parent;
          right_rotate(p_parent);
        }        
      } else if(p_uncle != NULL && p_uncle->get_color() == 0) {
        p_parent->get_parent()->set_color(0);
        p_parent->set_color(1);
        p_uncle->set_color(1);
        p_current = p_parent->get_parent();
      }
    }
  }
  return 0;
}

void red_black_tree::left_rotate(node * p_node) {
  node * p_parent = p_node->get_parent();
  node * p_right = p_node->get_right();
  if(p_right != NULL) {
    node * p_right_left = p_right->get_left();
    p_right->set_parent(p_parent);
    p_right->set_left(p_node);
    p_node->set_right(p_right_left);
    if(p_right_left != NULL) {
      p_right_left->set_parent(p_node);
    }
    if(p_parent == NULL) {
      p_root = p_right;
    } else if(p_node == p_parent->get_right()) {
      p_parent->set_right(p_right);
    } else if(p_node == p_parent->get_left()) {
      p_parent->set_left(p_right);
    }
  }
}

void red_black_tree::right_rotate(node * p_node) {
  node * p_parent = p_node->get_parent();
  node * p_left = p_node->get_left();

  if(p_left != NULL) {
    node * p_left_right = p_left->get_right();
    p_left->set_parent(p_parent);
    p_left->set_right(p_node);
    p_node->set_left(p_left_right);

    if(p_left_right != NULL) {
      p_left_right->set_parent(p_node);
    }
    if(p_parent == NULL) {
      p_root = p_left;
    } else if(p_node == p_parent->get_right()) {
      p_parent->set_right(p_left);
    } else if(p_node == p_parent->get_left()) {
      p_parent->set_left(p_left);
    }
  }
}

node * red_black_tree::find(int k) {
  return NULL;
}

int red_black_tree::remove(int k) {
  return 0;
}
