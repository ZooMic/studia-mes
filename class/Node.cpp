#include "Node.hpp"
#include <iostream>
using namespace std;
Node::Node(int id, float x, int bc) {
  this->id = id;
  this->x = x;
  this->bc = bc;
  this->t = 0;
};
void Node::show() {
    cout << "<" << this->id << "," << this->bc << "," << this->x << "," << this->t << ">";
}
