

#include <iostream>
#include "facebook.hpp"
#include "AdjacencyMatrix.hpp"
using namespace std;
int main(int argc, char *argv[])
{

    cout << "hello" << endl;
    /*
    Facebook f("data/FacebookDataset.txt");
    f.DisplayOut();
    // cout << "hello" << endl;
    */
    Facebook f("data/FacebookDataset.txt");
    //cout << f.GetSub("13 4", ' ').at(0) << endl;
    //cout << f.GetSub("13 4", ' ').at(0) << endl;
    //cout << f.GetSub("13 4", ' ').at(0) << endl;
    //cout << f.GetSub("13 4", ' ').at(1) << endl;
    //cout << f.getAV().at(3).at(1) << endl;
   // f.DisplayOut();
    // cout << f.getAV().size() << endl;
    // cout << f.getAV().at(0).size() << endl;

    AdjacencyMatrix adj("data/FacebookDataset.txt");
    adj.DisplayOut();

    return 0;
}