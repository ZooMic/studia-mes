#ifndef NODE_HPP
#define NODE_HPP
class Node {
    public:
      int id;       // Numer identyfikacyjny węzła
      float t;      // Temperatur (wartość którą wyliczam)
      int bc;       // Boundary Condition - warunek brzegowy [0 - brak], [1 - q], [2 - alfa*tout]
      float x;      // Pozycja węzła
      Node(int id, float x, int bc);
      void show();
};
#endif
