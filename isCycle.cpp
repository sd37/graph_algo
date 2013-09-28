//assume all vertices are numbered from 0 to V - 1
//detect if cycle is present or not

#define present(c,x) ((c).find(x) != (c).end())
#include<iostream>
#include<stdio.h>
#include<list>
#include<stdlib.h>
#include<string.h>
#include<stack>
#include<set>
using namespace std;

class Graph
{
        unsigned int V;
        list<unsigned int> *adj;
        bool isCycleUtil(unsigned int v,set<unsigned int>& visited,set<unsigned int>& recStack);
    
    public:
        Graph(unsigned int V);
        bool isCycle(unsigned int v);
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

bool Graph::isCycle(unsigned int v)
{
    set<unsigned int> visited;
    set<unsigned int> recStack;
   
    visited.clear();
    recStack.clear();
    return this->isCycleUtil(v,visited,recStack);
}

bool Graph::isCycleUtil(unsigned int v,set<unsigned int>& visited,set<unsigned int>& recStack)
{
    stack<unsigned int> dfsStack;

    dfsStack.push(v);
    recStack.insert(v);

    while(!dfsStack.empty())
    {
        unsigned int vv = dfsStack.top();
        visited.insert(vv);
        printf("%u ",vv);
        recStack.erase(vv);
        dfsStack.pop();
        
        list<unsigned int>::iterator it;
        for(it = adj[vv].begin(); it != adj[vv].end(); it++)
        {
            if(present(recStack,*it))
                return true;

            if(!present(visited,*it) && !present(recStack,*it))
            {
                dfsStack.push(*it);
                recStack.insert(*it);
            }    
        }
    
    }

    return false;

}

int main()
{
    fflush(stdout);
    Graph g(3);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,2);
    //g.addEdge(2,1);

    /*
    Graph g(4);
    
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(2,0);
    g.addEdge(2,3);
    g.addEdge(3,3);
    */
    if(g.isCycle(0))
        printf("yes");
    else
        printf("no");
    
    printf("\n");
    return 0;
}
