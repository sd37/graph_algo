#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>

using namespace std;

struct Subset
{
    int parent;
    int rank;
};

namespace UnionFind
{
    int find(struct Subset subsets[],int i);
    void Union(struct Subset subsets[],int x,int y);
}

namespace UnionFind
{
    int find(struct Subset subsets[],int i)
    {
        if(subsets[i].parent != i)
            subsets[i].parent = find(subsets,subsets[i].parent); //path compression will make every node in the 
                                                                //path directly attached to its parent.
        return subsets[i].parent;
    }

    void Union(struct Subset subsets[],int x, int y)
    {
        int xset = UnionFind::find(subsets,x);
        int yset = UnionFind::find(subsets,y);

        if(subsets[xset].rank < subsets[yset].rank)
            subsets[xset].parent = yset;
        else if (subsets[xset].rank > subsets[yset].rank)
            subsets[yset].parent = xset;
        else
        {
            subsets[yset].parent = xset;
            subsets[xset].rank++;
        }

    }

}
struct Edge
{
    int src;
    int dst;
};


class Graph
{
    int V;
    int E;
    vector<struct Edge> e;
public:
    Graph(int V,int E);
    void addEdge(int src,int dst);
    bool isCycle();
};

Graph::Graph(int V,int E)
{
   this->V = V;
   this->E = E;
   this->e.clear();
}

void Graph::addEdge(int src,int dst)
{
    Edge ee;
    ee.src = src;
    ee.dst = dst;
    this->e.push_back(ee);
}

bool Graph::isCycle()
{
    struct Subset* subsets = new struct Subset[this->V];

    for (int v = 0; v < this->V; v++)
    {
        subsets[v].parent = v;
        subsets[v].rank = 1;
    }

    for(int i = 0 ; i < this->E ; i++)
    {
        int x = UnionFind::find(subsets,this->e[i].src);
        int y = UnionFind::find(subsets,this->e[i].dst);
          
        if(x == y)
            return true;
        
        UnionFind::Union(subsets, x , y);
    }

    return false;
}

int main()
{
    int V = 3 , E = 3;

    Graph g(V,E);

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(0,2);

    if(g.isCycle())
        cout << "yes" << endl;
    else
        cout << "no" << endl;
    
    return 0;
}
