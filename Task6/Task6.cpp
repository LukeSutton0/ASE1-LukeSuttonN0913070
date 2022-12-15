#include "../headers/Task6.h"

// A brick is represented as a pair of symbol names, one on the north side and
// one on the south side

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

void addToTape(std::string& filePath, std::list<std::pair<std::string, std::string>>&tapeA, std::list<std::pair<std::string, std::string>>& tapeB) {
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
            auto pair = std::make_pair (firstString, secondString);
            tapeA.push_back(pair);
            tapeB.push_back(pair);
        }
    }
}

void sortTapeA(std::list<std::pair<std::string, std::string>>& tapeA) {
    tapeA.sort();
}




int main(int argc, char* argv[]) {
    std::string filePath = "../src/20/input-pairs-20.txt";
    //std::string filePath = checkIfInput(argc, argv);
    if (filePath == "Error invalid File") {
        return 1;
    }
    std::list<std::pair<std::string, std::string>> tapeA;
    std::list<std::pair<std::string, std::string>> tapeB;
    addToTape(filePath, tapeA,tapeB);
    sortTapeA(tapeA);


    for (auto line : tapeA) {
        std::cout << line.first << " "<< line.second << "\n";
    }

}