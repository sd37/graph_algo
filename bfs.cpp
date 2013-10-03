// assume all vertices are numbered from 0 to V - 1
#include<iostream>
#include<stdio.h>
#include<list>
#include<stdlib.h>
#include<string.h>
#include<queue>
using namespace std;

class Graph
{
        unsigned int V;
        list<unsigned int> *adj;
    
    public:
        Graph(unsigned int V);
        void BFS(unsigned int v);
        void addEdge(unsigned int s,unsigned int d);
};

Graph::Graph(unsigned int V)
{
    this->V = V;
    this->adj = new list<unsigned int>[V];
}

void Graph::addEdge(unsigned int s, unsigned int d)
{
    this->adj[s].push_back(d);
}

void Graph::BFS(unsigned int v)
{
    bool *visited = new bool[this->V];
    
    for(int i = 0; i < this->V; i++)
    {
        visited[i] = false;        
    }

    queue<unsigned int>bfsQueue;
    
    bfsQueue.push(v);
    visited[v] = true;

    while(!bfsQueue.empty())
    {
        unsigned int vv = bfsQueue.front();
        
        printf("%u ",vv);
        
        visited[vv] = true; //just paranoid although not required
        bfsQueue.pop();
        //enqueue all its unvisited neighbours
        
        list<unsigned int>::iterator it;

        for(it = adj[vv].begin(); it != adj[vv].end(); it++)
        {
            if(!visited[*it])
            {
                bfsQueue.push(*it);
                visited[*it] = true;
            }
        }
    
    }
}

int main()
{
    fflush(stdout);
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(2,0);
    g.addEdge(2,3);
    g.addEdge(3,3);
    
    printf("bfs from vertex 2:\n");
    g.BFS(2);
    
    printf("\n");
    return 0;
}
