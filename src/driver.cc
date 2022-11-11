#include <iostream>
#include "facebook.hpp"

using namespace std;

int main(int argc, char *argv[])
{

    cout << "hello" << endl;
    return -1;
    Facebook f("http://snap.stanford.edu/data/ego-Facebook.html");
    f.DisplayOut();
}