#include <fstream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
#include "AdjacencyMatrix.hpp"
#include "facebook.hpp"
#include <cmath>
#include <iostream>
#include <limits.h>

using namespace std;

AdjacencyMatrix::AdjacencyMatrix(const std::string &connections)
{
    Facebook fb(connections);
    std::vector<std::vector<int>> data = fb.getAV();
    int max = 0;
    
    for (int i = 0; i < data.size(); i++)
    {
        for (int j = 0; j < data.at(i).size(); j++)
        {
            if (max < data.at(i).at(j))
            {
                max = data.at(i).at(j);
            }
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
    cout << "height: " << g_.adjMatrix.size() << "width: " << g_.adjMatrix.at(0).size() << endl;
    
    for (int i = 0; i < data.size(); i++)
    {

        g_.adjMatrix.at(data.at(i).at(0)).at(data.at(i).at(1)) = true;
        g_.adjMatrix.at(data.at(i).at(1)).at(data.at(i).at(0)) = true;
    }
    
}
AdjacencyMatrix::AdjacencyMatrix()
{
}

void AdjacencyMatrix::addEdge(Graph *g, int src, int dest)
{
    g_.adjMatrix[src][dest] = true;
}

/*void AdjacencyMatrix::removeEdge(Graph *g, int src, int dest)
{
}
*/

void AdjacencyMatrix::DisplayOut()
{
    for (int i = 0; i < g_.adjMatrix.size(); i++)
    {
        for (int j = 0; j < g_.adjMatrix[i].size(); j++)
            cout << g_.adjMatrix[i][j] << " ";
        cout << '\n';
    }
}
/*bool AdjacencyMatrix::containsEdge(Graph const *const g, int src, int dest)
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
*/

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


std::vector<int> AdjacencyMatrix::dijkstras(Graph g, Vertex src)
{
    std::vector<int> ret;
    bool sptSet[g.at(0).size()];
    for(int i = 0; i < g.at(0).size(); i++){
        ret[i] = INT_MAX;
        sptSet[i] = false;
    }
    ret[src.v] = 0;
    for(int a = 0; g.at(0).size()-1){
        int min = INT_MAX;
        int min_index;
        for(int v = 0; v < g.at(0).size(); v++){
            if(sptSet[v] == false && ret[v] <= min){
                min = ret[v];
                min_index = v;
            }
        }
        sptSet[min_index] = true;
        for (int z = 0; z < V; z++){
            if (!sptSet[z] && g[min_index][z]>0 && ret[min_index] != INT_MAX && ret[min_index] + g[min_index][z] < ret[z]){
                ret[z] = ret[min_index] + g[min_index][z];
            }
        }

    }
    return ret;

}