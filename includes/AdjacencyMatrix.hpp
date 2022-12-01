#ifndef ADJACENCYMATRIX_HPP
#define ADJACENCYMATRIX_HPP

#include <fstream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
#include "facebook.hpp"
#include <cmath>
#include <iostream>
using namespace std;

class AdjacencyMatrix
{
public:
    struct Graph
    {
        std::vector<std::vector<bool> > adjMatrix; // true of there exists an edge between matrices
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
    void DisplayOut();
    AdjacencyMatrix();
    void addEdge(Graph *g, int src, int dest);
    // void removeEdge(Graph *g, int src, int dest);
    // bool containsEdge(Graph const *const g, int src, int dest);
    // int numOutgoingEdges(Graph const *const g, int v);
    // int numIncomingEdges(Graph const *const g, int v);
    void bfs(int begin, string fname);
    vector<int> dijkstras(Graph g, Vertex src);
    vector<double> pageRank(int iters = 100, double dampfact = 0.85);
    AdjacencyMatrix(const std::string &connections);
    Graph getGraph();
    vector<double> multArr(vector<double> ranks, vector<vector<double> > M_hat);
private:
    Graph g_;
    vector<Vertex> vertices_;
    vector<Edge> edges_;
    // Facebook fb;
};
#endif