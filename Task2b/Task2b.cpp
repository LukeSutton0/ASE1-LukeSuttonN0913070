#include "../Task2a/mainHeader.h"
#include <list>
#include <map>


void Task2Algo::task2b() {
    std::list<std::string> bricks;
    bricks.push_back("star");
    bricks.push_back("square");
    bricks.push_back("circle");
    bricks.push_back("star");
    bricks.push_back("octagon");
    bricks.push_back("rectangle");
    bricks.push_back("diamond");

    std::string startBrick = "square";
    std::string result = startBrick;
    bool finishedNorth = false;
    bool finishedSouth = false;

    // map <firstvaluetype,secondvaluetype<specifylisttype>::iterator to start search;
    std::map<std::string, std::list<std::string>::iterator> mapForSearching;

    for (std::list<std::string>::iterator it = bricks.begin(); it != bricks.end(); ++it) { //add list contents to map
        mapForSearching[*it] = it;
    }

    while (!finishedSouth) {
        
    }

    std::string mysearch = "star";
    /*if (mapforsearching.find(mysearch) != mapforsearching.end()){
        std::cout << "found";
    }*/
}
