#include <fstream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
#include "AdjacencyMatrix.h"

class AdjacencyMatrix
{
    public:
        struct LinkedListNode {
            LinkedListNode* next;
            int v;
        };

        struct AdjacencyList {
            int vertex;
            LinkedListNode* edges;
        };

        struct Graph {
            AdjacencyList* adjLists;
            int n;
        };

        void addVertex(int v);
        void removeVertex(int v);
        void addEdge(Graph* g, int src, int dest);
        void removeEdge(Graph* g, int src, int dest);
        bool containsEdge(Graph const * const g, int src, int dest);
        int numOutgoingEdges(Graph const * const g, int v);
        int numIncomingEdges(Graph const * const g, int v);
        

    private:
        //graph
        //vector of edges
        //vector of vertices


};

