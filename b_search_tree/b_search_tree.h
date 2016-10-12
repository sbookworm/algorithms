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
  int set_root(node * r);
  void insert_node(node n);
  void delete_node(int key);
  node * search_node(int key);
  void destroy_tree(node * p_node);
};

#endif
