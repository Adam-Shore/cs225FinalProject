

#include <iostream>
#include "facebook.hpp"
#include "AdjacencyMatrix.hpp"
using namespace std;
int main(int argc, char *argv[])
{

    /*cout << "hello" << endl;
    Facebook f("data/FacebookDataset.txt");
    f.DisplayOut();
    // cout << "hello" << endl;
    */

    AdjacencyMatrix adj("data/FacebookDataset.txt");
    adj.DisplayOut();

    return 0;
}