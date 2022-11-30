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
    bool visited[g.adjMatrix.at(0).size()];
    for(int i = 0; i < g.adjMatrix.at(0).size(); i++){
        ret.push_back(INT_MAX);
        visited[i] = false;
    }
    ret[src.v] = 0;
    for(int a = 0; a < g.adjMatrix.at(0).size()-1; a++){
        int min = INT_MAX;
        int min_index;
        for(int v = 0; v < g.adjMatrix.at(0).size(); v++){
            if(visited[v] == false && ret[v] <= min){
                min = ret[v];
                min_index = v;
            }
        }
        visited[min_index] = true;
        for (int z = 0; z < g.adjMatrix.at(0).size(); z++){
            if (!visited[z] && (int)g.adjMatrix[min_index][z]>0 && ret[min_index] != INT_MAX && ret[min_index] + (int)g.adjMatrix[min_index][z] < ret[z]){
                ret[z] = ret[min_index] + (int)g.adjMatrix[min_index][z];
            }
        }

    } 
    return ret;

}
AdjacencyMatrix::Graph AdjacencyMatrix::getGraph() {
    return g_;
}
vector<double> AdjacencyMatrix::pageRank(int iters, double dampfact) {
    
    vector<double> ranks;
    /*
    if len(G) == 0:
        return {}
  
    if not G.is_directed():
        D = G.to_directed()
    else:
        D = G
  
    # Create a copy in (right) stochastic form
    W = nx.stochastic_graph(D, weight=weight)
    N = W.number_of_nodes()
  
    # Choose fixed starting vector if not given
    if nstart is None:
        x = dict.fromkeys(W, 1.0 / N)
    else:
        # Normalized nstart vector
        s = float(sum(nstart.values()))
        x = dict((k, v / s) for k, v in nstart.items())
  
    if personalization is None:
  
        # Assign uniform personalization vector if not given
        p = dict.fromkeys(W, 1.0 / N)
    else:
        missing = set(G) - set(personalization)
        if missing:
            raise NetworkXError('Personalization dictionary '
                                'must have a value for every node. '
                                'Missing nodes %s' % missing)
        s = float(sum(personalization.values()))
        p = dict((k, v / s) for k, v in personalization.items())
     if dangling is None:
  
        # Use personalization vector if dangling vector not specified
        dangling_weights = p
    else:
        missing = set(G) - set(dangling)
        if missing:
            raise NetworkXError('Dangling node dictionary '
                                'must have a value for every node. '
                                'Missing nodes %s' % missing)
        s = float(sum(dangling.values()))
        dangling_weights = dict((k, v/s) for k, v in dangling.items())
    dangling_nodes = [n for n in W if W.out_degree(n, weight=weight) == 0.0]
  
    # power iteration: make up to max_iter iterations
    for _ in range(max_iter):
        xlast = x
        x = dict.fromkeys(xlast.keys(), 0)
        danglesum = alpha * sum(xlast[n] for n in dangling_nodes)
        for n in x:
  
            # this matrix multiply looks odd because it is
            # doing a left multiply x^T=xlast^T*W
            for nbr in W[n]:
                x[nbr] += alpha * xlast[n] * W[n][nbr][weight]
            x[n] += danglesum * dangling_weights[n] + (1.0 - alpha) * p[n]
  
        # check convergence, l1 norm
        err = sum([abs(x[n] - xlast[n]) for n in x])
        if err < N*tol:
            return x
    raise NetworkXError('pagerank: power iteration failed to converge '
                        'in %d iterations.' % max_iter)


*/

    return ranks;
}