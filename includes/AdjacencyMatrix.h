#pragma once

#include <fstream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

class AdjacencyMatrix
{
    public:
        struct Graph {
            bool** adjMatrix;
            int n;
        };
        struct Vertex {
            string v;
        };
        struct Edge {
            Vertex source;
            Vertex dest;
        };

        void addVertex(int v);
        void removeVertex(int v);
        void addEdge(Graph* g, int src, int dest);
        void removeEdge(Graph* g, int src, int dest);
        bool containsEdge(Graph const * const g, int src, int dest);
        int numOutgoingEdges(Graph const * const g, int v);
        int numIncomingEdges(Graph const * const g, int v);
        

    private:
        Graph g_;
        vector<Vertex> vertices_;
        vector<Edge> edges_;


};

#endif