#include "../headers/Task2.h"
#include <list>
#include <map>
#include <sstream>

//circle star square rectangle diamond octagon


int task2b(std::string filepath) {
    std::ifstream testFile {filepath};
    std::string line;
    std::list<std::string> bricks;

    if (!testFile.is_open()) { //if not open
        std::cerr << "File not open" << "\n"; //output char error
        return 1;
    }

    while (std::getline(testFile,line)) {
        //split string
        std::string delimiter = ",";
        std::string firstString = line.substr(0, line.find(delimiter));
        std::string secondString = line.substr(line.find(delimiter)+1,line.back());
        bricks.push_back(firstString);
        bricks.push_back(secondString);
    }
    testFile.clear(); //make getline back to start so it can read lines again
    testFile.seekg(0, testFile.beg);
    std::string startBrick;
    std::getline(testFile, startBrick, ','); //get string from line 1 / can change to whatever if need

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
            result = result + "," + mapForSearching[nextBrick];
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
                result = mapIter.first + "," + result;
                nextBrick = mapIter.first;
                break;
            }
            lastBrick = nextBrick;

        }
        if (nextBrick == lastBrick){
            finishedNorth = true;
        }
    }
    std::stringstream stream(result);
    std::string resultString;
    while (std::getline(stream, resultString, ',')) {
        std::cout << resultString <<"\n";
    }
}


int main(int argc, char* argv[]) {
    if (argc != 1) { //make sure filepath entered
        try {
            std::string filePath = argv[1];
            task2b(filePath);
        }
        catch(...) {
            std::cerr << "Error establishing filepath";
        }
    }
    //task2b("input-pairs-1K.txt");ab
}