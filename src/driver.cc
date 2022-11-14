

#include <iostream>
#include "facebook.hpp"
using namespace std;
int main(int argc, char *argv[])
{

    cout << "hello" << endl;
    Facebook f("data/FacebookDataset.txt");
    f.DisplayOut();
    return 0;
}