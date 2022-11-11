#pragma once

#include <fstream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
#include "AdjacencyMatrix.h"

void AdjacencyMatrix::addVertex(){

}

void AdjacencyMatrix::removeVertex(){

}

void AdjacencyMatrix::addEdge(Graph* g, int src, int dest){

}

void AdjacencyMatrix::removeEdge(Graph* g, int src, int dest){

}

bool AdjacencyMatrix::containsEdge(Graph const * const g, int src, int dest){
    return true;
}

int AdjacencyMatrix::numOutgoingEdges(Graph const * const g, int v){
    return 0;
}

int AdjacencyMatrix::numIncomingEdges(Graph const * const g, int v){
    return 0;
}

#endif