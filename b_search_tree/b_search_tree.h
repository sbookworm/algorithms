#ifndef B_SEARCH_TREE
#define B_SEARCH_TREE

#include "node.h"

class b_search_tree {
 private:
  node * root;
 public:
  b_search_tree();
  b_search_tree(node * r);
  ~b_search_tree();
  node * get_root();
  void set_root(node * r);
  void insert_node(node * p_node, node * p_parent);
  void delete_node(int key);
  node * search_node(int key);
  void destroy_tree(node * p_node);
  void print_mid_iter(node * p_node);
};

#endif
