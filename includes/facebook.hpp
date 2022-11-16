#ifndef FACEBOOK_HPP
#define FACEBOOK_HPP

#include <fstream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Facebook
{
public:
    // constructor
    Facebook();

public:
    // constructor
    Facebook(const std::string &connections);
    std::vector<int> GetSub(const std::string &str, char delimiter);
    void DisplayOut();
    std::vector<std::vector<int>> getAV();

private:
    // used to read in file data
    std::vector<std::vector<int>> adj_vect_;
};

#endif