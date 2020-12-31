/*
Breadth first search to find the path to destination
*/

#include "Graph.h"
#include<queue>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<int> const &a) 
{
   cout << "The vector elements are : ";

   for(int i=0; i < a.size(); i++)
   {
       cout << a.at(i) << ' ';
   } 
   cout<<endl;
}

int bfs_search(vector<vector<int>> a, int s, int f)
{
    int current_vertex = s;
    vector<int> current_edges = a[s];
    vector<int> checked;
    vector<int> q;
    path.push_back(s);
    int p;

    for(int i=0; i < current_edges.size(); i++)
   {
       q.push_back(current_edges.at(i));
   }

   while (!q.empty()) 
   {
        print(q);
        if ((count(q.begin(), q.end(), f)))
       {
           cout<<"Destination Reached"<<endl;
           print(checked);
           return 0;
       }
       else{
           if (!(count(checked.begin(), checked.end(), q.front())))
           {
                checked.push_back(q.front());
                current_edges = a[q.front()];
                for(int i=0; i < current_edges.size(); i++)
                {
                    if (!(count(checked.begin(), checked.end(), current_edges.at(i))))
                    {   if (!(count(q.begin(), q.end(), current_edges.at(i))))
                    {   p = current_edges.at(i);
                        q.push_back(current_edges.at(i));
                        path.push_back(p);
                    }                       
                    }
                    
                }
                q.erase(q.begin());
           }
           
       }
   }
    return 0;
}


int main()
{   //Create the Graph - input the nodes and edges
    Graph g;
    vector<int> v0 = {1,2,3}; // Each vertex and connected nodes
    vector<int> v1 = {0,3};
    vector<int> v2 = {0,3,5,6};
    vector<int> v3 = {0,1,2,4};
    vector<int> v4 = {5,3};
    vector<int> v5 = {4,2,6};
    vector<int> v6 = {5,2,7};
    vector<int> v7 = {8,6};
    vector<int> v8 = {7};
    g.add_edge(v0);
    g.add_edge(v1);
    g.add_edge(v2);
    g.add_edge(v3);
    g.add_edge(v4);
    g.add_edge(v5);
    g.add_edge(v6);
    g.add_edge(v7);
    g.add_edge(v8);

    vector<vector<int>> graphs;
    graphs = g.get_graph();

//BFS Search
    int s = 0; //Starting Vertex
    int f = 8; //destination vertex
    vector<int> path;
    bfs_search(graphs,s,f);
//    print(path);
    return 0;
}

