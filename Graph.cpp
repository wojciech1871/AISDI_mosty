#include "Graph.h"

Graph::Node::Node()
: nodeUsed(true)
{}

Graph::Node::~Node()
{}

Graph::Graph()
: numOfNodes(0)
{}

Graph::~Graph()
{
  for(auto it=vertexVect.begin();it!=vertexVect.end();it++)
  {
    delete *it;
  }
}

int Graph::calcNumOfConsistParts() const //function calculate number of consistent parts
{
  std::vector<int> visitedNodes(numOfNodes, 0);
  int numOfConsistParts=0;
  int v, u;
  std::stack<int> S;

  for(int i=0;i<numOfNodes;i++)
  {
    if(vertexVect[i]->nodeUsed && !visitedNodes[i])
    {
      numOfConsistParts++;
      S.push(i);
      visitedNodes[i]=numOfConsistParts;
      while(!S.empty())
      {
        v=S.top();
        S.pop();
        for(auto it=vertexVect[v]->neighborList.begin();it!=vertexVect[v]->neighborList.end();it++)
        {
          u=*it;
          if(vertexVect[u]->nodeUsed && !visitedNodes[u])
          {
            S.push(u);
            visitedNodes[u]=numOfConsistParts;
          }
        }
      }
    }
  }
  if(numOfConsistParts==0)
  {
    numOfConsistParts=1;
  }
  return numOfConsistParts;
}

void Graph::findMosts()
{
  int numOfConsistParts=calcNumOfConsistParts();
  for(int v=0;v<numOfNodes;v++)
  {
    for(auto it=vertexVect[v]->neighborList.begin(); it!=vertexVect[v]->neighborList.end(); it++)
    {
      int u=*it;
      if(u>v)
      {
        vertexVect[v]->nodeUsed=vertexVect[u]->nodeUsed=false;
        if(calcNumOfConsistParts()>numOfConsistParts)
        {
          mostList.push_back(std::make_pair(v,u));
        }
        vertexVect[v]->nodeUsed=vertexVect[u]->nodeUsed=true;
      }
    }
  }
}

void Graph::showMosts() const
{
  for(auto it=mostList.begin(); it!=mostList.end(); it++)
  {
    std::cout <<it->first <<" " <<it->second <<std::endl;
  }
}

void Graph::addVertex()
{
  vertexVect.push_back(new Node);
  numOfNodes++;
}

void Graph::addEdge(int v, int u)
{
  if(v>=numOfNodes || u>=numOfNodes)
  {
    throw std::out_of_range("Vertices don't exist");
  }
  vertexVect[v]->neighborList.push_back(u);
  vertexVect[u]->neighborList.push_back(v);
}
