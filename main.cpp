#include <iostream>
#include "Graph.h"

int main()
{
  Graph testGraph;
  int x, y, numOfNodes;
  std::cin >>numOfNodes;

  if(numOfNodes!=0)
  {
    for (int i = 0; i < numOfNodes; i++)
    {
        testGraph.addVertex();
    }

    while (std::cin >> x >> y) {
        testGraph.addEdge(x, y);
    }

    testGraph.findMosts();
    testGraph.showMosts();
  }
  return 0;
}
