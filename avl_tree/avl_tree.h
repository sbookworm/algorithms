#ifndef AVL_TREE
#define AVL_TREE

#include <iostream>
#include <queue>
#include "node.h"

using namespace std;

class avl_tree {
 private:
  node * p_root;
 public:
  int insert(node * p_node);
  int insert_node(node * p_node, node * p_current);
  int remove(int k);
  node * find(int k);
  int get_hight(node * p_node);
  void destroy_tree(node * p_node);
  void left_rotate(node * p_node);
  void right_rotate(node * p_node);
  int balance();
  int check_balance();
  void print();
  int get_count();
  int count(node * p_node);
  void layer_print(queue<node*>& q, int hight, int layer);

  avl_tree();
  ~avl_tree();
};

#endif
