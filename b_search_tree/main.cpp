#include <iostream>
#include "node.h"
#include "b_search_tree.h"

using namespace std;

int main() {
  std::cout<<"test"<<endl;
  node *  a = new node(1, 2);
  cout << a->get_value() << endl;
  b_search_tree * tree = new b_search_tree();
  delete(tree);
  delete(a);

  return 0;

}
