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

AdjacencyMatrix::AdjacencyMatrix(const std::string &connections)  //created an adjacency matrix
{
    Facebook fb(connections);
    std::vector<std::vector<int>> data = fb.getAV();  //data stores the 2d vector of data
    int max = 0;
    
    for (int i = 0; i < data.size(); i++)    //find the maximum node to determine number of iterations through dataset
    {
        for (int j = 0; j < data.at(i).size(); j++)
        {
            if (max < data.at(i).at(j))
            {
                max = data.at(i).at(j);
            }
        }
    }
    
    for (int i = 0; i <= max; i++)  //fills adjacency matrix with 0(no connection) or 1(connection) and loops through the number of nodes 
    {
        vector<bool> b;
        g_.adjMatrix.push_back(b);
        for (int j = 0; j <= max; j++)   
        {
            g_.adjMatrix.at(i).push_back(false);  //initially fill all connections as false
        }
    }
    cout << "height: " << g_.adjMatrix.size() << "width: " << g_.adjMatrix.at(0).size() << endl;
    
    for (int i = 0; i < data.size(); i++)  //creates a connection between 2 nodes. Since undirected graph, if a connection is set btw nodes a and b, then connection must be set btw nodes b and a in adjacency matrix
    {

        g_.adjMatrix.at(data.at(i).at(0)).at(data.at(i).at(1)) = true;
        g_.adjMatrix.at(data.at(i).at(1)).at(data.at(i).at(0)) = true;
    }
    
}
AdjacencyMatrix::AdjacencyMatrix()  //empty constructor
{
}

void AdjacencyMatrix::addEdge(Graph *g, int src, int dest)  //creates an edge between 2 nodes
{
    g_.adjMatrix[src][dest] = true;
}

/*void AdjacencyMatrix::removeEdge(Graph *g, int src, int dest)
{
}
*/

void AdjacencyMatrix::DisplayOut()   //print out contents of adjacency matrix
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

vector<bool> AdjacencyMatrix::bfs(int begin) //used to search through a structure for a specified node
{
    // vector<vector<int>> adj_vect_ = getAV();
    vector<bool> is_visited;
    queue<int> qu;
    qu.push(begin);
    for(size_t i = 0; i < g_.adjMatrix.size(); i++) {
        is_visited.push_back(false);
    }

    is_visited[begin] = true;

    int index = 0;

    while (!qu.empty())  //bfs algoithm that continues to check each node and add to queue until queue is empty
    {
        index = qu.front();  
        qu.pop();
        for (unsigned i = 0; i < g_.adjMatrix[index].size(); i++)
        {
            if (g_.adjMatrix[index][i] == 1 && (!is_visited[i])) //this checks if the node you are on is not yet visitied, adds node to queue and marks node as visited
            {
                qu.push(i);
                is_visited[i] = true;
            }
        }
    }
    int counter = 0;
    for (int i = 0; i < is_visited.size(); i++) // loop keeps track of the nodes that were already visited
    {
        if (is_visited[i] == 1)
        {
            counter++;
            // this means that you visited the node
        }
    }
    return is_visited;
}

//perform dijkstras algorithm to find distances between a src and every other vertex where the index of the return
 //vector is the  distance between the source and the vertex stored at that index in the graph
std::vector<int> AdjacencyMatrix::dijkstras(Graph g, Vertex src)
{
    std::vector<int> ret; // create return vector
    bool visited[g.adjMatrix.at(0).size()];  //create vector to use in loop to track visited vertices
    for(int i = 0; i < g.adjMatrix.at(0).size(); i++){ //loop sets every index of visited to false and sets distance to max for each index
        ret.push_back(INT_MAX);
        visited[i] = false;
    }
    ret[src.v] = 0; //sets the return value of the source to itself to zero
    for(int a = 0; a < g.adjMatrix.at(0).size()-1; a++){//loop through each row in graph
        int min = INT_MAX;
        int min_index;//initialize int to track the minimum distance from current vertex
        for(int v = 0; v < g.adjMatrix.at(0).size(); v++){//loop through each column in the row of the graph
            if(visited[v] == false && ret[v] <= min){ //update the minimum index and value if not already visited and less than min
                min = ret[v];
                min_index = v;
            }
        }
        visited[min_index] = true; //set minimum index to true in visited vector
        for (int z = 0; z < g.adjMatrix.at(0).size(); z++){ //loop through each row in graph
            if (!visited[z] && (int)g.adjMatrix[min_index][z]>0 && ret[min_index] != INT_MAX && ret[min_index] + (int)g.adjMatrix[min_index][z] < ret[z]){
                ret[z] = ret[min_index] + (int)g.adjMatrix[min_index][z]; //adds the distance to the return vector if conditions met
            }
        }

    } 
    return ret;//return the return vector

}

//getter function for the graph
AdjacencyMatrix::Graph AdjacencyMatrix::getGraph() {
    return g_; //returns the graph
}
//function to return a vector which sums to one, with each index in the 
//vector storing how popular the corresponding node is
//parameters are number of iterations for the algorithm and the dampening factor
vector<double> AdjacencyMatrix::pageRank(int iters, double dampfact) {
    
    vector<double> ranks; //initializes return vector 
    vector<vector<double>> M_hat; //matrix that when multiplied by the ranks matrix produces a new, more accurate ranks vector 
    size_t N = g_.adjMatrix.size(); //size of adjacency matrix
    double dist = 1.0 / N; 

    //initializes values in ranks so that each proportion starts off as equal
    for(size_t i =0; i < N; i++) {
        ranks.push_back(dist);
    }

    //Creates M_hat based on dampening factor
    for (size_t i =0; i < g_.adjMatrix.size(); i ++) {
        vector<double> tmp;
        M_hat.push_back(tmp);
        for (size_t j =0; j < g_.adjMatrix.at(i).size(); j ++) {
            M_hat.at(i).push_back(g_.adjMatrix.at(i).at(j)*dampfact+(1-dampfact)/N);
        }
    }

    //multiply ranks and m_hat and update ranks iters times 
    for (int i =0; i < iters; i++) {
        ranks = multArr(ranks, M_hat);
    }
    //make value in ranks a proportion which sums to 1
    double tot = 0;
    for (size_t i = 0; i < ranks.size(); i++) {
        tot += ranks.at(i);
    }
    for (size_t i = 0; i < ranks.size(); i++) {
        ranks.at(i) = ranks.at(i)/tot;
    }

    //return a vector of the the proportion of connectedness of each vertex
    return ranks;
}

//helper function to multiply a N x N matrix by a N x 1 vector
vector<double> AdjacencyMatrix::multArr(vector<double> ranks, vector<vector<double>> M_hat) {
    vector<double> ret; //initialize return vector
    for (size_t i =0; i < M_hat.size(); i ++) {
        double tot = 0;
        for (size_t j =0; j < M_hat.at(i).size(); j ++) {
           tot +=  M_hat.at(i).at(j) * ranks.at(j);
        }
        ret.push_back(tot);
    }
    // returns a N x 1 vector
    return ret;
}