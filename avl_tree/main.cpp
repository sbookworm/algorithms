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

  int test[] = {498, 482, 220, 408, 400,491,15,435,384,335,102,495,152,483,43};
  for(int i=0; i<15; i++) {
    //int key = ((int)rand())%MAX_RAND;;
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
  p_tree->print();

  int test_flag = 0;
  for(int i=0; i<15; i++) {
    if(p_tree->find(test[i]) == NULL) {
      cout<<"test find error"<<endl;
      test_flag = 1;
    }
  }

  if(p_tree->find(321) == NULL && test_flag == 0) {
    cout<<"test 1 find ok"<<endl;
  }

  for(int i=0; i<5; i++) {
    p_tree->remove(test[i]);
  }

  for(int i=0; i<5; i++) {
    if(p_tree->find(test[i]) != NULL) {
      test_flag = 1;
    }
  }

  for(int i=5; i<15; i++) {
    if(p_tree->find(test[i]) == NULL) {
      test_flag = 1;
    }
  }

  if(test_flag == 0) {
    cout<<"test 2 ok"<<endl;
  } else {
    cout<<"test 2 failed"<<endl;
  }
  for(int i=5; i<15; i++) {
    if(p_tree->remove(test[i]) != 0) {
      test_flag = 1;
    }
  }
  if(test_flag == 0) {
    cout<<"test 3 ok"<<endl;
  } else {
    cout<<"test 3 failed"<<endl;
  }

  p_tree->print();
  delete p_tree;
  return 0;
}
