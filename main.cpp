#include <iostream>
#include <fstream>
#include "class/Node.hpp"
#include "class/Element.hpp"
#include "class/Net.hpp"
using namespace std;

Net *createNet(const char * path) {
    ifstream in(path);
    int nn, ne, id, bc, id1, id2;
    float x, S, k, alfa, q, tout;

    in >> nn;
    in >> ne;
    Node ** nodes = new Node*[nn];
    Element ** elements = new Element*[ne];
    for(int i = 0; i < nn; i++) {
        in >> id;
        in >> bc;
        in >> x;
        nodes[id] = new Node(id,x,bc);
    }
    for(int i = 0; i < ne; i++) {
        in >> id1;
        in >> id2;
        in >> S;
        in >> k;
        in >> alfa;
        in >> q;
        in >> tout;
        elements[i] = new Element(S,k,alfa,q,tout,nodes[id1], nodes[id2]);
    }
    Net *net = new Net(ne, nn, nodes, elements);
    //net->showNodesAndElements();
    in.close();
    return net;
}

float * metodaGaussaSeidla(float **H, float *P, int n) {
  float m = 0;
  for (int j = 0; j < n; j++)
  {
    for (int i = j + 1; i< n; i++)
    {
      m = H[i][j] / H[j][j];
      H[i][j] -= m*H[j][j];
      for (int k = j + 1; k < n; k++)
      {
        H[i][k] -= (m*H[j][k]);
      }
      P[i] -= m*P[j];
    }
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      m = H[i][j] / H[j][j];
      H[i][j] -= m*H[j][j];
      for (int k = j + 1; k < n; k++)
      {
        H[i][k] -= m*H[j][k];
      }
      P[i] -= m*P[j];
    }
  }
	float* t = new float[n];
  for(int i = 0; i < n; i++) {
    t[i] = P[i] / H[i][i];
  }
  return t;
}

int main() {
  Net *net = createNet("dane_my_own_5.txt");
  net->wyznaczMacierzWspolczynnikowUkladuRownan();
  //net->wypiszMacierzWspolczynnikow();
  int n = net->ne+1;
  float *p = new float[n];
  float **h = new float*[n];
  for(int i = 0; i < n; i++) {
      h[i] = new float[n];
  }
  // Kopiowanie danych
  for(int i = 0; i < n; i++) {
      p[i] = -1 * net->P[i];
      for(int j = 0; j < n; j++) {
          h[i][j] = net->H[i][j];
      }
  }
  // Próba gouss'a
  float *t = metodaGaussaSeidla(h,p,n);
  net->setCalculatedTemperatures(t);
  net->saveNodesInFile("wyniki.txt");
}
