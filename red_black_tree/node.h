#ifndef __NODE_H_
#define __NODE_H_

class node {
 private:
  int key;
  int value;

  // color 0 is red, and 1 is black
  bool color;
  node * p_left;
  node * p_right;
  node * p_parent;

 public:
  node * get_left();
  node * get_right();
  node * get_parent();

  void set_left(node * p_l);
  void set_right(node * p_r);
  void set_parent(node * p_p);

  node();
  node(int, int);
  ~node();
  
  int get_value();
  int get_key();

  void set_key(int k);
  void set_value(int v);

  bool get_color();
  void set_color(bool c);
   
};

#endif
