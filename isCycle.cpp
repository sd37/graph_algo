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
        bool isCycle();
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

bool Graph::isCycleUtil(unsigned int v,set<unsigned int>& visited,set<unsigned int>& recStack)
{
    if(!present(visited,v))
    {
        visited.insert(v);
        recStack.insert(v);

        list<unsigned int>::iterator i;
        for(i = adj[v].begin(); i != adj[v].end(); i++)
        {
            if(!present(visited,*i) && isCycleUtil(*i, visited, recStack) )
                return true;
            
            else if(present(recStack,*i))
                return true;
        }
    }

    set<unsigned int>::iterator it = recStack.find(v); 
    
    if(it != recStack.end())
        recStack.erase(it);

    return false;
}

bool Graph::isCycle()
{
    // Returns true if the graph contains a cycle, else false
    
    //Mark all vertices as not visited and not part of recursion
    //stack
    
    set<unsigned int> visited;
    set<unsigned int> recStack;
    
    //Call recursive helper function to detect cycle in different
    //DFS Trees.
    
    for (unsigned int i = 0; i < this->V; i++)
    {
        if(isCycleUtil(i,visited,recStack))
            return true;
    }

    return false;
}
int main()
{
    fflush(stdout);
    Graph g(3);
    g.addEdge(0,1);
    //g.addEdge(2,0);
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
    if(g.isCycle())
        printf("yes");
    else
        printf("no");
    
    printf("\n");
    return 0;
}
