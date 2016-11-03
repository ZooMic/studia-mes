#ifndef ELEMENT_HPP
#define ELEMENT_HPP
#include "Node.hpp"
class Element {
    public:
      Node *n1;   // Pierwszy węzeł
      Node *n2;   // Drugi węzeł
      float S;    // Przekrój pręta
      float k;    // Współczynnik przewodzenia ciepła
      float alfa; // Współczynnik konwekcyjnej wymiany ciepła
      float q;    // Strumień ciepła
      float tout; // Temperatura otoczenia
      float **LH; // Lokalna macierz współczynników układu równań
      float *LP;  // Wektor obciążeń (strumienie cieplne);
      Element(float S, float k, float alfa, float q, float tout, Node *n1, Node *n2);
      void set_global_H(float **H);
      void set_global_P(float *P);
      void show();
    private:
      void set_local_H();
      void set_local_P();
};
#endif
