
#ifndef CATCH_CONFIG_MAIN
#define CATCH_CONFIG_MAIN
#endif
#include "catch.hpp"

#include "facebook.hpp"
#include "AdjacencyMatrix.hpp"
#include <string>

TEST_CASE("A test case", "[case-1-data]") {  //correct size means data is read in correctly to correctly build a n*2 vector(shape of file)
    string connections = "tests/TestData.txt";
    Facebook fb(connections);
    REQUIRE(fb.getAV().size() == 15);
    REQUIRE(fb.getAV().at(1).size() == 2);   
}


TEST_CASE("A test case 2", "[case-2-data]") {  //correctly parsing file and reading in data into array
    string connections = "tests/TestData.txt";
    Facebook fb(connections);
    REQUIRE(fb.getAV().at(5).at(0) == 0);  
    REQUIRE(fb.getAV().at(3).at(1) == 4); 
    REQUIRE(fb.getAV().at(1).at(0) == 0); 
}


TEST_CASE("A test case 3", "[case-3-data]") {  //vector in each row is properly being filled
    string connections = "tests/TestData.txt";
    Facebook fb(connections);
    REQUIRE(fb.GetSub("2 4", ' ').at(0) == 2);  
    REQUIRE(fb.GetSub("2 4", ' ').at(1) == 4);  
}

TEST_CASE("Test dijkstras", "[case-3-data]") {  //vector has correct distance from source 

    vector<int> correct;
    AdjacencyMatrix::Vertex src;
    src.v = 0;

    AdjacencyMatrix AM("tests/TestData.txt");

    vector<int> output = AM.dijkstras(AM.getGraph(), src);

    REQUIRE(output.at(0) == 0);
    REQUIRE(output.at(1) == 1);
    REQUIRE(output.at(2) == 1);
    REQUIRE(output.at(3) == 1);
    REQUIRE(output.at(4) == 1);
    REQUIRE(output.at(5) == 2);
    REQUIRE(output.at(6) == 3);
 

}

TEST_CASE("Test pagerank", "[case-4-data]") {  //vector of ranks is created and most conected node is returned
    vector<double> correct;
    AdjacencyMatrix AM("tests/TestData.txt");



    correct = AM.pageRank(100, 0.85);
    double highest = 0;
    double highest_idx = 0;

    for (unsigned i = 0; i < correct.size(); i++) {
        if (correct.at(i) > highest) {
            highest = correct.at(i);
            highest_idx = i;
        }
    }

    REQUIRE(highest_idx == 0);


 

}
