#include <iostream>
#include "node.h"

using namespace std;

node::node() {
  key = 0;
  value = 0;
  color = 0;
  p_left = NULL;
  p_right = NULL;
  p_parent = NULL;
}

node::node(int k, int v) {
  key = k;
  value = v;
  p_left = NULL;
  p_right = NULL;
  p_parent = NULL;
}

node::~node() {
}

int node::get_value() {
  return value;
}

node * node::get_left() {
  return p_left;
}

node * node::get_right() {
  return p_right;
}

int node::get_key() {
  return key;
}

void node::set_left(node * p_l) {
  this->p_left = p_l;
}

void node::set_right(node * p_r) {
  this->p_right = p_r;
}

void node::set_parent(node * p_p) {
  this->p_parent = p_p;
}

node * node::get_parent() {
  return p_parent;
}

void node::set_key(int k) {
  this->key = k;
}

void node::set_value(int v) {
  this->value = v;
}

void node::set_color(bool c) {
  this->color = c;
}

bool node::get_color() {
  return this->color;
}
