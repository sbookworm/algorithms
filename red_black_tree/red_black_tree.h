#ifndef __RED_BLACK_H_
#define __RED_BLACK_H_

#include "node.h"

class red_black_tree {

 public:
  node * p_root;

 private:

  red_black_tree();
  ~red_black_tree();
  
  void set_root(node * p_node);
  node * get_root();

  int insert(node * node);
  node * find(int k);
  int remove(int k);

  void destroy(node * p_node);

};

#endif
