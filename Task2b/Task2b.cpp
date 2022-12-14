#include "../headers/Task2.h"
int main(int argc, char* argv[]) {   
    //std::string filePath = checkIfInput(argc, argv);
    std::string filePath = "input-pairs-3M.txt";
    if (filePath == "Error invalid File") {
        return 1;
    }
    std::list<std::string> bricks;
    fileToList(filePath, bricks);
    std::string startBrick = bricks.front();
    std::map<std::string, std::string> mapForSearchingSouth;
    std::map<std::string, std::string> mapForSearchingNorth;
    listToOMap(bricks,mapForSearchingSouth,mapForSearchingNorth);
    std::list<std::string> result;
    std::string nextBrick = startBrick;
    result.push_back(nextBrick);
    twoBSouth(bricks,mapForSearchingSouth,result,nextBrick);
    std::string lastBrick = "";
    twoBNorth(bricks, mapForSearchingNorth, result, nextBrick, lastBrick);
    
    for (const auto& resultIter : result) {
        std::cout << resultIter;
    }
    return 0;
}

void fileToList(std::string& filePath, std::list<std::string>& bricks) {
    std::ifstream testFile{ filePath };
    std::string line;
    if (!testFile.is_open()) { //if not open
        std::cerr << "File not open" << "\n"; //output char error
    }
    else {
        while (std::getline(testFile, line)) {
            //split string
            std::string delimiter = ",";
            std::string firstString = line.substr(0, line.find(delimiter));
            std::string secondString = line.substr(line.find(delimiter) + 1, line.back());
            bricks.push_back(firstString);
            bricks.push_back(secondString);
        }
    }
}
void listToOMap(std::list<std::string>& bricks, std::map<std::string, std::string>& mapForSearchingSouth, std::map<std::string, std::string > & mapForSearchingNorth) {
    int countingListEntries = 0;
    std::string mapValue1 = " ";
    for (std::list<std::string>::const_iterator itToListCurrentBrick = bricks.begin(); itToListCurrentBrick != bricks.end(); ++itToListCurrentBrick) { //add list contents to map
        if (countingListEntries % 2 == 1) {
            std::string mapValue2 = *itToListCurrentBrick;
            mapForSearchingSouth[mapValue1] = mapValue2;
            mapForSearchingNorth[mapValue2] = mapValue1;
        }
        else {
            mapValue1 = *itToListCurrentBrick;
        }
        ++countingListEntries;
    }
}
void twoBSouth(std::list<std::string>& bricks, std::map<std::string, std::string>& mapForSearchingSouth, std::list<std::string>& result, std::string nextBrick) {
    bool finishedSouth = false;
    while (!finishedSouth) {
        if (mapForSearchingSouth.find(nextBrick) != mapForSearchingSouth.end()) {
            result.push_back("\n" + mapForSearchingSouth[nextBrick]);
            nextBrick = mapForSearchingSouth[nextBrick]; //[startbrick] = brick.second
        }
        else {
            finishedSouth = true;
        }
    }
}
void twoBNorth(std::list<std::string>& bricks, std::map<std::string, std::string>& mapForSearchingNorth, std::list<std::string>& result, std::string nextBrick, std::string lastBrick) {
    bool finishedNorth = false;
    while (!finishedNorth) {
        if (mapForSearchingNorth.find(nextBrick) != mapForSearchingNorth.end() && mapForSearchingNorth.find(nextBrick)->second == nextBrick) { //tried using string but took ages to push front
            result.push_front(nextBrick + "\n");
            nextBrick = mapForSearchingNorth[nextBrick];
        }
        else {
            finishedNorth = true;
            result.push_front(mapForSearchingNorth[nextBrick] + "\n");
        }
    }
}
std::string checkIfInput(int argc, char* argv[]) {
    try {
        if (argc != 1) { //make sure filepath entered
            std::string filePath = argv[1];
            return filePath;
        }
    }
    catch (...) {
        std::cerr << "Error establishing filepath";
    }
    return "Error invalid File";

}


//code graveyard
//circle star square rectangle diamond octagon
//    task2b("input-pairs-1K.txt");
//    result = nextBrick + result;
//            result = result + "," + mapForSearching[nextBrick];
//std::stringstream stream(result);
//    std::string resultString;
//    while (std::getline(stream, resultString, ',')) {
//        std::cout << resultString <<"\n";
//    }
    //testFile.clear(); //make getline back to start so it can read lines again
//testFile.seekg(0, testFile.beg);
    //std::getline(testFile, startBrick, ','); //get string from line 1 / can change to whatever if need