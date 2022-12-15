#include "Task2b.h"
int main(int argc, char* argv[]) {
    std::chrono::steady_clock::time_point startTime = std::chrono::steady_clock::now();
    std::string filePath = checkIfInput(argc, argv);
    if (filePath == "Error invalid File") {
        return 1;
    }
    std::map<std::string, std::string> mapForSearchingSouth;
    std::map<std::string, std::string> mapForSearchingNorth;
    std::string startBrick = fileToMap(filePath, mapForSearchingSouth, mapForSearchingNorth);
    std::list<std::string> result;
    std::string nextBrick = startBrick;
    result.push_back(nextBrick);
    twoBSouth(mapForSearchingSouth, result, nextBrick);
    twoBNorth(mapForSearchingNorth, result, nextBrick);
    std::chrono::steady_clock::time_point finishTime = std::chrono::steady_clock::now();
    std::chrono::nanoseconds timeTaken = std::chrono::duration_cast<std::chrono::nanoseconds>(finishTime - startTime);
    std::cout << timeTaken.count() << "\n";
    std::ofstream afile;
    afile.open("testResult.txt", std::ios::app);
    afile << timeTaken.count() << "\n";
    afile.close();
    //outputResult(result);
    return 0;
}

std::string fileToMap(std::string& filePath, std::map<std::string, std::string>& mapForSearchingSouth, std::map<std::string, std::string >& mapForSearchingNorth) {
    std::ifstream testFile{ filePath };
    std::string line;
    bool first = true;
    std::string startBrick = "";
    if (!testFile.is_open()) { //if not open
        std::cerr << "File not open" << "\n"; //output char error
    }
    else {
        while (std::getline(testFile, line)) {            //split string
            std::string delimiter = ",";
            std::string firstString = line.substr(0, line.find(delimiter));
            std::string secondString = line.substr(line.find(delimiter) + 1, line.back());
            mapForSearchingSouth[firstString] = secondString;
            mapForSearchingNorth[secondString] = firstString;
            if (first == true) {
                startBrick = firstString;
                first = false;
            }
        }
    }
    return startBrick;
}
void twoBSouth(std::map<std::string, std::string>& mapForSearchingSouth, std::list<std::string>& result, std::string nextBrick) {
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
void twoBNorth(std::map<std::string, std::string>& mapForSearchingNorth, std::list<std::string>& result, std::string nextBrick) {
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
void outputResult(std::list<std::string> result) {
    for (const auto& resultIter : result) {
        std::cout << resultIter;
    }
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