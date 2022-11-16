#include <fstream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
#include "AdjacencyMatrix.h"
#include <cmath>
#include <iostream>

AdjacencyMatrix::AdjacencyMatrix()
{
    std::vector<std::vector<int>> data = getAV();
    int max = 0;
    for (int i = 0; i < data.size(); i++)
    {
        for (int j = 0; j < data.at(i).size(); j++)
        {
            max = std::max(max, data.at(i).at(j));
        }
    }

    for (int i = 0; i <= max; i++)
    {
        vector<bool> b;
        g_.adjMatrix.push_back(b);
        for (int j = 0; j <= max; j++)
        {
            g_.adjMatrix.at(i).push_back(false);
        }
    }

    for (int i = 0; i < data.size(); i++)
    {
        for (int j = 0; j < data.at(i).size(); j++)
        {
            g_.adjMatrix.at(i).at(j) = true;
            g_.adjMatrix.at(j).at(i) = true;
        }
    }
}

void AdjacencyMatrix::addEdge(Graph *g, int src, int dest)
{
    g_.adjMatrix[src][dest] = true;
}

void AdjacencyMatrix::removeEdge(Graph *g, int src, int dest)
{
}

bool AdjacencyMatrix::containsEdge(Graph const *const g, int src, int dest)
{
    if (g_.adjMatrix[src][dest])
    {
        return true;
    }
    return false;
}

int AdjacencyMatrix::numOutgoingEdges(Graph const *const g, int v)
{
    int out = 0;
    for (int i = 0; i < g_.n; i++)
    {
        if (g_.adjMatrix[v][i])
        {
            out++;
        }
    }
    return out;
}

int AdjacencyMatrix::numIncomingEdges(Graph const *const g, int v)
{
    int out = 0;
    for (int i = 0; i < g_.n; i++)
    {
        if (g_.adjMatrix[i][v])
        {
            out++;
        }
    }
    return out;
}

void AdjacencyMatrix::bfs(int begin, string fname)
{
    // vector<vector<int>> adj_vect_ = getAV();
    vector<bool> is_visited;
    queue<int> qu;
    qu.push(begin);
    is_visited[begin] = true;

    int index = 0;
    while (!qu.empty())
    {
        index = qu.front();
        qu.pop();

        for (unsigned i = 0; i < g_.adjMatrix[index].size(); i++)
        {
            if (g_.adjMatrix[index][i] == 1 && (!is_visited[i]))
            {
                qu.push(i);
                is_visited[i] = true;
            }
        }
    }
    int counter = 0;
    for (int i = 0; i < is_visited.size(); i++)
    {
        if (is_visited[i] == 1)
        {
            counter++;
            // this means that you visited the node
        }
    }
}
