#ifndef NET_HPP
#define NET_HPP
#include "Element.hpp"
#include "Node.hpp"
class Net {
    public:
      int ne;
      int nn;
      Element **elements;
      Node **nodes;
      float **H;
      float *P;
      Net(int ne, int nn, Node **nodes, Element **elements);
      void wyznaczMacierzWspolczynnikowUkladuRownan();
      void wypiszMacierzWspolczynnikow();
      void showNodesAndElements();
      void setCalculatedTemperatures(float *t);
      void saveNodesInFile(const char * path);
};
#endif
