#ifndef GRAPH_H
#define GRAPH_H

#include <QString>
#include <QDebug>
#include<bits/stdc++.h>
using namespace std;
# define INF 0x3f3f3f3f

// This class represents a directed graph using
// adjacency list representation
class Graph
{
    int V;    // No. of vertices
    // In a weighted graph, we need to store vertex
    // and weight pair for every edge
    list< pair<int, int> > *adj;

public:
    Graph(int V);  // Constructor
    void addEdge(int u, int v, int w);    // function to add an edge to graph
    QString shortestPath(int s);      // prints shortest path from s
};

#endif // GRAPH_H





