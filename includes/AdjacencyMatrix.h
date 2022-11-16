#pragma once

#include <fstream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
#include "facebook.hpp"
#include <cmath>
using namespace std;

class AdjacencyMatrix : public Facebook
{
public:
    struct Graph
    {
        std::vector<std::vector<bool>> adjMatrix; // true of there exists an edge between matrices
        int n;                                    // length of rows and columns
    };
    struct Vertex
    {
        int v;
    };
    struct Edge
    {
        Vertex source;
        Vertex dest;
    };

    AdjacencyMatrix();
    void addEdge(Graph *g, int src, int dest);
    void removeEdge(Graph *g, int src, int dest);
    bool containsEdge(Graph const *const g, int src, int dest);
    int numOutgoingEdges(Graph const *const g, int v);
    int numIncomingEdges(Graph const *const g, int v);
    void bfs(int begin, string fname);

private:
    Graph g_;
    std::vector<Vertex> vertices_;
    std::vector<Edge> edges_;
};