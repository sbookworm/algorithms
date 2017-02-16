#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "node.h"
#include "avl_tree.h"


using namespace std;

int MAX_RAND = 500;

int main() {
  srand((unsigned)time(0));
  avl_tree * p_tree = new avl_tree();

  //int test[] = {498, 482, 220, 408, 400};
  for(int i=0; i<10; i++) {
    int key = ((int)rand())%MAX_RAND;;
    //int key = test[i];
    int value = key;
    cout<<key<<endl;
    node * p_node = new node(key, value);
    int result = p_tree->insert(p_node);
    if (result != 0) {
      cout<<"duplicated!"<<endl;
      delete p_node;
    }
  }
  p_tree->print();
  //cout<<"size is:"<<p_tree->get_count()<<endl;
  delete p_tree;
  return 0;
}
