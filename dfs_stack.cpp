// assume all vertices are numbered from 0 to V - 1
#include<iostream>
#include<stdio.h>
#include<list>
#include<stdlib.h>
#include<string.h>
#include<stack>
using namespace std;

class Graph
{
        unsigned int V;
        list<unsigned int> *adj;
        void DfsUtil(unsigned int v,bool visited[]);
    
    public:
        Graph(unsigned int V);
        void DFS(unsigned int v);
        void DFSComplete();
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

void Graph::DFS(unsigned int v)
{
    bool *visited = new bool[this->V];
    
    for(unsigned int i = 0; i < this->V ; i++)
        visited[i] = false;

    this->DfsUtil(v,visited);
    
}

void Graph::DfsUtil(unsigned int v,bool visited[])
{
    stack<unsigned int> dfsStack;

    dfsStack.push(v);

    while(!dfsStack.empty())
    {
        unsigned int vv = dfsStack.top();
        visited[vv] = true;
        printf("%u ",vv);
        dfsStack.pop();
        
        list<unsigned int>::iterator it;
        for(it = adj[vv].begin(); it != adj[vv].end(); it++)
        {
            if(!visited[*it])
            {
                dfsStack.push(*it);
                visited[*it] = true;
            }    
        }
    
    }

}

void Graph::DFSComplete()
{
    bool *visited = new bool[this->V];

    for(unsigned int i = 0; i < this->V; i++)
    {
        visited[i] = false;
    }
    
    for(unsigned int v = 0; v < this->V; v++)
    {
        if(!visited[v])
        {
            this->DfsUtil(v,visited);
        }
    }
}

int main()
{
    fflush(stdout);
    
    
    Graph g(3);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(2,1);
    

/*    
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(2,0);
    g.addEdge(2,3);
    g.addEdge(3,3);
*/  
    g.DFS(0);
    
    printf("\nall nodes in the Graph:\n");
    g.DFSComplete();
    printf("\n");
    return 0;
}
