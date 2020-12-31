#include "Graph.h"

void Graph::add_edge(vector <int> b)
{
    this->graph_list.push_back(b);
}

vector<vector<int>> Graph::get_graph()
{
    return this->graph_list;
}