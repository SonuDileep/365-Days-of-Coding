/*
Program to create undirected graphs
*/

#include "Graph.h"

using namespace std;

int main()
{   //Create the Graph - input the nodes and edges
    Graph g;
    vector<int> v0 = {1,2,3}; // Each vertex and connected nodes
    vector<int    // Initializing 2D vector "vect" with > v1 = {0,3};
    vector<int> v2 = {0,3,5,6};
    vector<int> v3 = {0,1,2,4};
    vector<int> v4 = {5,3};
    vector<int> v5 = {4,2,6};
    vector<int> v6 = {5,2};
    g.add_edge(v0);
    g.add_edge(v1);
    g.add_edge(v2);
    g.add_edge(v3);
    g.add_edge(v4);
    g.add_edge(v5);
    g.add_edge(v6);

    vector<vector<int>> graphs;
    graphs = g.get_graph();
    cout<<graphs[6][0]<<endl;
    return 0;
}

