#include "../Task2a/mainHeader.h"
#include <list>
#include <map>

//circle star square rectangle diamond octagon


void Task2Algo::task2b() {
    std::list<std::string> bricks;
    bricks.push_back("star");
    bricks.push_back("square");
    bricks.push_back("circle");
    bricks.push_back("star");
    bricks.push_back("diamond");
    bricks.push_back("octagon");
    bricks.push_back("square");
    bricks.push_back("rectangle");
    bricks.push_back("rectangle");
    bricks.push_back("diamond");
    std::string startBrick = "square";

    // map <firstvaluetype,secondvaluetype<specifylisttype>::iterator to start search;
    std::map<std::string,std::string> mapForSearching;
    int countingListEntries = 0;
    std::string mapValue1 = " ";

    for (std::list<std::string>::const_iterator itToListCurrentBrick = bricks.begin(); itToListCurrentBrick != bricks.end(); ++itToListCurrentBrick) { //add list contents to map
        if(countingListEntries %2 == 1){
            std::string mapValue2 = *itToListCurrentBrick;
            mapForSearching[mapValue1] = mapValue2;
        }
        else {
            mapValue1 = *itToListCurrentBrick;
        }
        ++countingListEntries;
    }

    std::string result;
    bool finishedNorth = false;
    bool finishedSouth = false;
    std::string nextBrick = startBrick;
    std::string lastBrick = "";

    while (!finishedSouth) {
        if (mapForSearching.find(nextBrick) != mapForSearching.end()) {
            result += mapForSearching[nextBrick];
            nextBrick = mapForSearching[nextBrick]; //[startbrick] = brick.second
        }
        else {
            finishedSouth = true;
        }
    }
    nextBrick = startBrick;
    result = nextBrick + result;

    while (!finishedNorth) {
        for (const auto& mapIter: mapForSearching) {
            if (mapIter.second == nextBrick) {
                result = mapIter.first + result;
                nextBrick = mapIter.first;
                break;
            }
            lastBrick = nextBrick;

        }
        if (nextBrick == lastBrick){
            finishedNorth = true;
        }
    }

    std::cout << result;
}
