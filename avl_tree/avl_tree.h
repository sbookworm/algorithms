#ifndef AVL_TREE
#define AVL_TREE

#include "node.h"

class avl_tree {
 private:
  node * p_root;
 public:
  int insert(node * p_node);
  int insert_node(node * p_node, node * p_current);
  node * remove(int k);
  node * find(int k);
  int get_hight(node * p_node);
  void destroy_tree(node * p_node);
  void left_rotate(node * p_node);
  void right_rotate(node * p_node);
  void balance();
  void print();
  void print_node(node * p_node, int deepth);

  avl_tree();
  ~avl_tree();
};

#endif
