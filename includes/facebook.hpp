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
    //constructor 
    public:
    //constructor 
    Facebook(const std::string& connections);
    std::vector<std::string> GetSub(const std::string& str, char delimiter);
    void DisplayOut();



    private:
    //used to read in file data
    std::vector<std::vector<std::string>> adj_vect_;

};

#endif