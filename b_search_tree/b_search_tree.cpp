#include <iostream>
#include "node.h"
#include "b_search_tree.h"

using namespace std;

b_search_tree::b_search_tree() {
  p_root = NULL;
}

b_search_tree::b_search_tree(node * r) {
  p_root = r;
}

b_search_tree::~b_search_tree() {
  if(this->p_root == NULL) {
    return;
  }
  destroy_tree(this->p_root);
}

void b_search_tree::destroy_tree(node * p_node) {
  if(p_node->get_left() != NULL) {
    destroy_tree(p_node->get_left());
  }
  if(p_node->get_right() != NULL) {
    destroy_tree(p_node->get_right());
  }
  delete(p_node);
}

void b_search_tree::set_root(node * r) {
    p_root = r;
}

void b_search_tree::insert_node(node * p_node, node * p_current) {
  if(p_node == NULL) {
    return;
  }
  int key = p_node->get_key();
  int current_key = p_current->get_key();
  if(key < current_key) {
    if(p_current->get_left() != NULL) {
      insert_node(p_node, p_current->get_left());
    } else {
      p_current->set_left(p_node);
      p_node->set_parent(p_current);
    }
  } else if (key > current_key) {
    if(p_current->get_right() != NULL) {
      insert_node(p_node, p_current->get_right());
    } else {
      p_current->set_right(p_node);
      p_node->set_parent(p_current);
    }
  } else if (key == current_key) {
    delete(p_node);
    cout<<"duplicated key"<<endl;
  }
}

void b_search_tree::delete_node(int key) {
  node * searched = search_node(key, this->p_root);
  if (searched == NULL) {
    cout<<"cannot find deleted node"<<endl;
    return;
  }

  node * tmp_parent = searched->get_parent();
  if(searched->get_left() == NULL && searched->get_right() == NULL) {
    if (tmp_parent == NULL) {
      this->p_root = NULL;
    } else if(tmp_parent->get_left() == searched) {
      tmp_parent->set_left(NULL);
    } else {
      tmp_parent->set_right(NULL);
    }
    delete(searched);

  } else if (searched->get_left() != NULL && searched->get_right() == NULL) {
    if (tmp_parent == NULL) {
      p_root = searched->get_left();
      searched->get_left()->set_parent(NULL);
    } else if(tmp_parent->get_left() == searched) {
      tmp_parent->set_left(searched->get_left());
      searched->get_left()->set_parent(tmp_parent);
    } else {
      tmp_parent->set_right(searched->get_left());
      searched->get_left()->set_parent(tmp_parent);
    }
    delete(searched);
  } else if (searched->get_left() == NULL && searched->get_right() != NULL) {
    if (tmp_parent == NULL) {
      p_root = searched->get_right();
      searched->get_right()->set_parent(NULL);
    } else if (tmp_parent->get_left() == searched) {
      tmp_parent->set_left(searched->get_right());
      searched->get_right()->set_parent(tmp_parent);
    } else {
      tmp_parent->set_right(searched->get_right());
      searched->get_right()->set_parent(tmp_parent);
    }
    delete(searched);
  } else {
    node * p_next = searched->get_left();
    node * p_next_parent = searched;
    while (p_next->get_right() != NULL) {
      p_next_parent = p_next;
      p_next = p_next->get_right();
    }
    searched->set_key(p_next->get_key());
    searched->set_value(p_next->get_value());
    if (p_next_parent == searched) {
      searched->set_left(p_next->get_left());
    } else {
      p_next_parent->set_right(p_next->get_left());
    }
    if (p_next->get_left() != NULL) {
      p_next->get_left()->set_parent(p_next_parent);
    }
    delete(p_next);
  }
}

node * b_search_tree::search_node(int key, node * p_node) {
  if(p_node == NULL) {
    return NULL;
  }
  if(key == p_node->get_key()) {
    return p_node;
  }
  if(key<p_node->get_value() && p_node->get_left()!=NULL) {
    return search_node(key, p_node->get_left());
  }
  if(key>p_node->get_value() && p_node->get_right()!=NULL) {
    return search_node(key, p_node->get_right());
  }

  return NULL;
}

void b_search_tree::print_mid_iter(node * p_node) {
  if(p_node == NULL) {
    return;
  }
  if(p_node->get_left() != NULL) {
    print_mid_iter(p_node->get_left());
  }
  cout<<p_node->get_value()<<" ";
  if(p_node->get_right() != NULL) {
    print_mid_iter(p_node->get_right());
  }
}

node * b_search_tree::get_root() {
  return p_root;
}

