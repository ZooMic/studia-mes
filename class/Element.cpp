#include "Node.hpp"
#include "Element.hpp"
#include <cmath>
#include <iostream>
using namespace std;
//#include <math.h>
Element::Element(float S, float k, float alfa, float q, float tout, Node *n1, Node *n2) {
    this->S = S;
    this->k = k;
    this->n1 = n1;
    this->n2 = n2;
    this->alfa = alfa;
    this->q = q;
    this->tout = tout;
    this->set_local_H();
    this->set_local_P();
};

void Element::set_local_H() {
  this->LH = new float*[2];
  this->LH[0] = new float[2];
  this->LH[1] = new float[2];
  float c = (this->S * this->k) / abs(this->n2->x - this->n1->x);
  this->LH[0][0] = c;
  this->LH[0][1] = -1*c;
  this->LH[1][0] = -1*c;
  this->LH[1][1] = c;
  if(this->n1->bc == 2) this->LH[0][0] += this->alfa * this->S;
  if(this->n2->bc == 2) this->LH[1][1] += this->alfa * this->S;
};

void Element::set_local_P() {
  LP = new float[2];
  if(this->n1->bc == 1) {
    LP[0] = this->q * this->S;
  } else if(this->n1->bc == 2) {
    LP[0] = -1*this->alfa * this->S * this->tout;
  }
  if(this->n2->bc == 1) {
    LP[1] = this->q * this->S;
  } else if(this->n2->bc == 2) {
    LP[1] = -1*this->alfa * this->S * this->tout;
  }
};

void Element::set_global_H(float **H) {
    int id1 = n1->id;
    int id2 = n2->id;
    H[id1][id1] += this->LH[0][0];
    H[id1][id2] += this->LH[0][1];
    H[id2][id1] += this->LH[1][0];
    H[id2][id2] += this->LH[1][1];
}

void Element::set_global_P(float *P) {
    P[n1->id] = this->LP[0];
    P[n2->id] = this->LP[1];
}

void Element::show() {
    cout << "{";
    this->n1->show();
    cout << ",";
    this->n2->show();
    cout << "," << this->S << ",";
    cout << this->k << "," << this->alfa << "," << this->q << "," << this->tout << "}";
}
