#include <iostream>
#include "node.h"
#include "red_black_tree.h"

using namespace std;

int main() {
  red_black_tree * p_tree = new red_black_tree();

  int test[] = {498, 482, 220, 408, 400,491,15,435,384,335,102,495,152,483,43};
  for(int i=0; i<4; i++) {
    int key = test[i];
    int value = key;
    cout<<key<<endl;
    node * p_node = new node(key, value);
    int result = p_tree->insert(p_node);
    if (result != 0) {
      cout<<"duplicated!"<<endl;
      delete p_node;
    }
  }
  delete p_tree;
  return 0;
}
