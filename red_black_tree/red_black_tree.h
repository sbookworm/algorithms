#ifndef __RED_BLACK_H_
#define __RED_BLACK_H_

#include "node.h"

/*
1. node is red or black
2. root is black
3. leaf nodes(NULL ones) are black
4. children of red nodes are black
5. the black nodes count must be equal, which go from one node to the leaf node
*/
class red_black_tree {

 private:
  node * p_root;
  void destroy(node * p_node);
 public:

  red_black_tree();
  ~red_black_tree();
  
  void set_root(node * p_node);
  node * get_root();

  int insert(node * node);
  node * find(int k);
  int remove(int k);
};

#endif
