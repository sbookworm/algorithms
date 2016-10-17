#ifndef NODE_H
#define NODE_H

class node {
 private:
  int key;
  int value;
  node * p_left;
  node * p_right;

 public:
  node * get_left();
  node * get_right();
  void set_left(node * p_l);
  void set_right(node * p_r);

  node();
  node(int, int);
  ~node();
  
  int get_value();
  int get_key();
};


#endif
