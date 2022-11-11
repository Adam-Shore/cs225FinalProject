#ifndef FACEBOOK_HPP
#define FACEBOOK_HPP

#include <fstream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

class Facebook
{   
    public:
    //constructor 
    Facebook(const std::string& connections);
    std::vector<std::string> Breakln(const std::string& str, char delimiter);



    private:
    //used to read in file data
    std::vector<std::vector<std::string>> adj_vect_;

};

#endif