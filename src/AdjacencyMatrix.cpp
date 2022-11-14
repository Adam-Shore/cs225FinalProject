
#include <fstream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
#include "AdjacencyMatrix.h"

void AdjacencyMatrix::addVertex(int v)
{
}

void AdjacencyMatrix::removeVertex(int v)
{
}

void AdjacencyMatrix::addEdge(Graph *g, int src, int dest)
{
    g->adjMatrix[src][dest] = true;
}

void AdjacencyMatrix::removeEdge(Graph *g, int src, int dest)
{
}

bool AdjacencyMatrix::containsEdge(Graph const *const g, int src, int dest)
{
    if (g->adjMatrix[src][dest])
    {
        return true;
    }
    return false;
}

int AdjacencyMatrix::numOutgoingEdges(Graph const *const g, int v)
{
    int out = 0;
    for (int i = 0; i < g->n; i++)
    {
        if (g->adjMatrix[v][i])
        {
            out++;
        }
    }
    return out;
}

int AdjacencyMatrix::numIncomingEdges(Graph const *const g, int v)
{
    int out = 0;
    for (int i = 0; i < g->n; i++)
    {
        if (g->adjMatrix[i][v])
        {
            out++;
        }
    }
    return out;
}
