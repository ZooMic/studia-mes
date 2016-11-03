#include <iostream>
#include "Node.hpp"
#include "Element.hpp"
#include "Net.hpp"
using namespace std;
Net::Net(int ne, int nn, Node **nodes, Element **elements) {
    this->ne = ne;
    this->nn = nn;
    this->nodes = nodes;
    this->elements = elements;
    this->H = new float *[ne+1];
    this->P = new float[ne+1];
    for(int i = 0; i <= ne ; i++) {
        this->H[i] = new float[ne+1];
        this->P[i] = 0;
    }
    for(int i = 0; i <= ne ; i++) {
        for(int j = 0; j <= ne; j++) {
            this->H[i][j] = 0;
        }
    }
};

void Net::wyznaczMacierzWspolczynnikowUkladuRownan() {
    Element ** elements = this->elements;
    for(int i = 0; i < ne; i++) {
        elements[i]->set_global_H(this->H);
        elements[i]->set_global_P(this->P);
    }
};

void Net::wypiszMacierzWspolczynnikow() {
    for(int i = 0;i <= ne;i++) {
        cout << "| ";
        for(int j = 0; j <= ne; j++) {
            cout << this->H[i][j] << "  ";
        }
        cout << " | " << this->P[i] << endl;
    }
};

void Net::showNodesAndElements() {
    for(int i = 0; i < this->nn; i++) {
        this->nodes[i]->show();
        cout << endl;
    }
    cout << endl;
    for(int i = 0; i < this->ne; i++) {
        this->elements[i]->show();
        cout << endl;
    }
    cout << endl;
}
