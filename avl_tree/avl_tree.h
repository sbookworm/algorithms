#ifndef AVL_TREE
#define AVL_TREE

#include "node.h"

class avl_tree {
 private:
  node * p_root;
 public:
  int insert(node * p_node);
  node * remove(int k);
  node * find(int k);
  
  
  avl_tree();
  ~avl_tree();
  void destory_tree(node * p_node);
};

#endif
