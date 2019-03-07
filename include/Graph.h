#ifndef AISDI_GRAPHS
#define AISDI_GRAPHS

#include <cstddef>
#include <stdexcept>
#include <utility>
#include <iostream>
#include <list>
#include <stack>
#include <vector>

class Graph
{
  struct Node
  {
    bool nodeUsed;
    std::list<int> neighborList;
    Node();
    ~Node();
  };

  std::vector<Node*> vertexVect;
  std::list<std::pair<int,int>> mostList;
  int numOfNodes;

public:
  Graph();
  ~Graph();
  int calcNumOfConsistParts() const;
  void findMosts();
  void showMosts() const;
  void addVertex();
  void addEdge(int, int);
};
#endif //AISDI_GRAPHS
