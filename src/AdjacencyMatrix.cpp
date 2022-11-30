
#include <fstream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
#include "AdjacencyMatrix.h"
#include <cmath>


AdjacencyMatrix::AdjacencyMatrix(){
    std::vector<std::vector<int>> data = getAV();
    int max = 0;
    for(int i = 0; i<data.size(); i++){
        for(int j = 0; j<data.at(i).size(); j++){
            max = std::abs(max, data.at(i).at(j));
        }
    }

    for(int i = 0; i<=max; i++){
        vector<bool> b;
        g_.adjMatrix.push_back(b);
        for(int j = 0; j<=max; j++){
            g_.adjMatrix.at(i).push_back(false);
        }
    }

    for(int i = 0; i<data.size(); i++){
        for(int j = 0; j<data.at(i).size(); j++){
            g_.adjMatrix.at(i).at(j)=true;
            g_.adjMatrix.at(j).at(i)=true;
        }
    }

}


void AdjacencyMatrix::addEdge(Graph* g, int src, int dest){
    g->adjMatrix[src][dest] = true;
}

void AdjacencyMatrix::removeEdge(Graph* g, int src, int dest){

}

bool AdjacencyMatrix::containsEdge(Graph const * const g, int src, int dest){
    if(g->adjMatrix[src][dest]){
        return true;
    }
    return false;
}

int AdjacencyMatrix::numOutgoingEdges(Graph const * const g, int v){
    int out = 0;
    for (int i = 0; i < g->n; i++) {
        if (g->adjMatrix[v][i]){
            out++;
        }
    }
    return out;
}

int AdjacencyMatrix::numIncomingEdges(Graph const * const g, int v){
    int out = 0;
    for (int i = 0; i < g->n; i++) {
        if (g->adjMatrix[i][v]){
            out++;
        }
    }
    return out;
}
