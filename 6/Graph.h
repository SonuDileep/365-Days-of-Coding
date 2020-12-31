/*
Create Undirected Graph in C++
*/

#include<iostream>
#include<vector>

using namespace std;

class Graph
{
    private:
        int v; //Stores number of vertices
        vector<vector<int>> graph_list;

    public:
        void add_edge(vector <int> b); // a is the parent node and b child
        vector<vector<int>> get_graph();//Return the entire graph
};