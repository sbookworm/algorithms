#ifndef NODE_H
#define NODE_H

class node {
 private:
  int key;
  int value;
  node * left;
  node * right;

 public:
  node();
  node(int, int);
  ~node();
  
  int get_value();

};


#endif
