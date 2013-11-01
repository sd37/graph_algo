#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<list>
#include<map>
#include<set>
#include<queue>

#define present(c,x) ((c).find(x) != (c).end())

typedef int d;
typedef int v;
typedef int wt;

using namespace std;

namespace Print
{
    void printMap(map<v,d> &mp)
    {
       map<v,d>::iterator it;
       for(it = mp.begin();it!=mp.end();it++)
       {
            cout << it->first << "=>" << it->second << endl;
       }
    }
}
class Graph
{
    map<v  , list<pair<v,wt> > > adjLst; // pair = (dst,edge wt)
public:
    Graph();
    void addEdge(int src,int dst,int wt);
    map<v,d> dijkstra(int src);
};

Graph::Graph()
{
   this->adjLst.clear();
}

void Graph::addEdge(int src,int dst,int wt)
{
    adjLst[src].push_back(make_pair(dst,wt));
    adjLst[dst].push_back(make_pair(src,wt));
}

map<v,d> Graph::dijkstra(int src)
{
    map<v,d> closed; //map<vertex,distance> 
    priority_queue< pair<d,v>, vector<pair<d,v> >, greater<pair<d,v> > > pq;
    pq.push(make_pair(0,src));
    
    while(!pq.empty())
    {
        pair<d,v> vv = pq.top();
        pq.pop();

        int vertx = vv.second;
        int dist = vv.first;
       
        if(present(closed,vertx))
            continue;

        closed[vertx] = dist;

        list<pair<v,wt> >::iterator it;
        
        for (it = adjLst[vertx].begin(); it != adjLst[vertx].end(); it++)
        {
           if(!present(closed,it->first))
           {
               //use the extracted min to update the distances of the neighbouring nodes.
               //this can be done NOT replacing the element but just inserting the element pair into the heap.
               //this may create redundancy but does not effect the performance by much
              
               pq.push(make_pair(it->second + dist,it->first));
           }
        }
    }
    return closed;
}

int main()
{
    Graph g;

    g.addEdge(0,1,4);
    g.addEdge(0,7,8);
    g.addEdge(1,2,8);
    g.addEdge(1,7,11);
    g.addEdge(2,3,7);
    g.addEdge(2,8,2);
    g.addEdge(2,5,4);
    g.addEdge(3,4,9);
    g.addEdge(3,5,14);
    g.addEdge(4,5,10);
    g.addEdge(5,6,2);
    g.addEdge(6,7,1);
    g.addEdge(6,8,6);
    g.addEdge(7,8,7);

    //Do Dijkstra
    
    map<v,d> res = g.dijkstra(0);
    Print::printMap(res);
    return 0;
}
