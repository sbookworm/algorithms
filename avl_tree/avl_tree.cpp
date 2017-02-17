#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>

#include "node.h"
#include "avl_tree.h"

using namespace std;

int NUM_SIZE = 4; // set three space for number

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
  int result = insert_node(p_node, this->p_root);

  int balance_result = balance();
  if (balance_result == -1 || check_balance()) {
    cout<<"=======balancing error!!======="<<endl;
  }
  return result;
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

int avl_tree::remove(int k) {

  node * p_node = find(k);
  if(p_node == NULL) {
    return -1;
  }
  
  node * p_right = p_node->get_right();
  node * p_left  = p_node->get_left();
  node * p_parent = p_node->get_parent();
  // if the node is root node, need some notice

  
  if (p_right == NULL && p_left == NULL) {
    if(p_parent == NULL) {
      p_root = NULL;
    } else if (p_parent->get_left()->get_key() == k) {
      p_parent->set_left(NULL);
    } else {
      p_parent->set_right(NULL);
    }
    delete p_node;
  } else if (p_right == NULL && p_left != NULL) {
    if (p_parent == NULL) {
      p_root = p_left;
    } else if (p_parent->get_left()->get_key() == k) {
      p_parent->set_left(p_left);
    } else {
      p_parent->set_right(p_left);
    }
    p_left->set_parent(p_parent);
    delete p_node;
  } else if (p_right != NULL && p_left == NULL) {
    if (p_parent == NULL) {
      p_root = p_left;
    } else if (p_parent->get_left()->get_key() == k) {
      p_parent->set_left(p_right);
    } else {
      p_parent->set_right(p_right);
    }
    p_right->set_parent(p_parent);
    delete p_node;
  } else {
    node * p_max_left = p_left;
    int has_right = 0;
    while(p_max_left->get_right() != NULL) {
      has_right = 1;
      p_max_left = p_max_left->get_right();
    }
    p_node->set_key(p_max_left->get_key());
    p_node->set_value(p_max_left->get_value());

    node * p_max_left_child = p_max_left->get_left();
    node * p_max_left_parent = p_max_left->get_parent();
    if(p_max_left_child != NULL) {
      p_max_left_child->set_parent(p_max_left_parent);
    }
    if (has_right) {
      p_max_left_parent->set_right(p_max_left_child);
    } else {
      p_max_left_parent->set_left(p_max_left_child);
    }
    delete p_max_left;
  }
  return 0;
}

node * avl_tree::find(int k) {
  node * p_node = this->p_root;
  while (p_node != NULL) {
    if (p_node->get_key() == k) {
      break;
    } else if (k > p_node->get_key()) {
      p_node = p_node->get_right();
    } else {
      p_node = p_node->get_left();
    }
  }
  return p_node;
}

void avl_tree::left_rotate(node * p_node) {
  node * p_right = p_node->get_right();
  node * p_right_left = p_right->get_left();
  node * p_parent = p_node->get_parent();

  if (p_parent == NULL) {
    p_root = p_right;
  } else {
    p_parent->set_left(p_right);
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
  } else {
    p_parent->set_right(p_left);
  }

  p_left->set_parent(p_parent);
  p_left->set_right(p_node);
  p_node->set_parent(p_left);
  p_node->set_left(p_left_right);

  if (p_left_right) {
    p_left_right->set_parent(p_node);
  }
}

int avl_tree::balance() {
  node * p_left = this->p_root->get_left();
  node * p_right = this->p_root->get_right();

  int left_hight = get_hight(p_left);
  int right_hight = get_hight(p_right);

  if(abs(left_hight - right_hight) < 2) {
    return 0;
  }
  int count_before = get_count();
  if (left_hight > right_hight) {
    node * p_left_left = p_left->get_left();
    node * p_left_right = p_left->get_right();

    if (get_hight(p_left_left) > get_hight(p_left_right)) {
      right_rotate(p_root);
    } else {
      left_rotate(p_left);
      right_rotate(p_root);
    }
  } else {
    node * p_right_left = p_right->get_left();
    node * p_right_right = p_right->get_right();

    if (get_hight(p_right_left) > get_hight(p_right_right)) {
      right_rotate(p_right);
      left_rotate(p_root);
    } else {
      left_rotate(p_root);
    }
  }

  int count_after = get_count();

  if (count_after == count_before) {
    return 0;
  }
  return -1;
}

int avl_tree::check_balance() {
  int left_hight = get_hight(this->p_root->get_left());
  int right_hight = get_hight(this->p_root->get_right());
  if (abs(left_hight - right_hight) > 1) {
    return 1;
  }
  return 0;
}

int avl_tree::get_count() {
  return count(this->p_root);
}

int avl_tree::count(node * p_node) {
  if (p_node == NULL) {
    return 0;
  }
  int left_count = count(p_node->get_left());
  int right_count = count(p_node->get_right());

  return left_count+right_count+1;
}


int avl_tree::get_hight(node * p_node) {
  if (p_node == NULL) {
    return 0;
  }
  return max(get_hight(p_node->get_left()), get_hight(p_node->get_right())) + 1;
}

void avl_tree::print() {
  int hight = get_hight(this->p_root);
  int line_node_num = pow(2, hight-1);
  queue <node*> tree_nodes;
  tree_nodes.push(this->p_root);
  for(int i=0; i<hight; i++) {
    layer_print(tree_nodes, hight, i+1);
  }
}

void print_tab(int tab) {
  for(int i=0; i<tab; i++) {
    cout<<" ";
  }
}

void print_line(int size) {
  for(int i=0; i<size; i++) {
    cout<<"-";
  }
}

void avl_tree::layer_print(queue<node*>& q, int hight, int layer) {
  queue <node*> next_line;
  int size = q.size();

  int line_node_num = pow(2, hight-1);
  int width = (2*line_node_num)*NUM_SIZE;
  int len = width/size;

  for(int i=0; i<int(pow(2, layer-2)); i++) {
    print_tab((len-NUM_SIZE)/2);
    print_line(len);
    print_tab((len-NUM_SIZE)/2+4);
  }

  cout<<endl;
  while(q.size()) {
    node * p_first = q.front();
    q.pop();
    if (p_first == NULL) {
      next_line.push(NULL);
      next_line.push(NULL);
    } else {
      next_line.push(p_first->get_left());
      next_line.push(p_first->get_right());
    }

    print_tab((len-NUM_SIZE)/2);
    if(p_first) {
      cout<<p_first->get_key();
    } else {
      cout<<"    ";
    }
    print_tab((len-NUM_SIZE)/2);
  }

  while(next_line.size()) {
    q.push(next_line.front());
    next_line.pop();
  }

  cout<<endl;
}
