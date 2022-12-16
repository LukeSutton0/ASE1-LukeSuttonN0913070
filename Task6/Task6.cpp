#include "../headers/Task2.h"

int main(int argc, char* argv[]) {
    std::string filePath = "../src/20/input-pairs-20.txt";
    //std::string filePath = checkIfInput(argc, argv);
    if (filePath == "Error invalid File") {
        return 1;
    }
    std::list<std::pair<std::string, std::string>> tapeA;
    std::list<std::pair<std::string, std::string>> tapeB;
    std::list<std::pair<std::string, std::string>> tapeC;
    std::list<std::pair<std::string, int>> tapeP;
    int N = addToTape(filePath, tapeA, tapeB);
    sortTapeSecond(tapeA);
    sortTapeFirst(tapeB);
    compareAB(tapeA, tapeB, tapeC, tapeP);
    int d = 2;
    std::list<std::pair<std::string, int>> tapeF;
    while (d < N) {
        tapeA = tapeC;
        tapeB = tapeC;
        tapeC.clear();
        sortTapeSecond(tapeA);
        sortTapeFirst(tapeB);
        tapeManipulation(tapeA, tapeB, tapeC, tapeP, tapeF, d);
        sortTapeFirst(tapeF);
        tapeP.merge(tapeF);
        tapeF.clear();
        d = d * 2;
    }
    sortTapeSecond(tapeP);
    std::list<std::string> tapeResult;
    for (auto pair : tapeP) {
        tapeResult.push_back(pair.first);
    }
    for (auto brick : tapeResult) {
        std::cout << brick << "\n";
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

int addToTape(std::string& filePath, std::list<std::pair<std::string, std::string>>& tapeA, std::list<std::pair<std::string, std::string>>& tapeB) {
    std::ifstream testFile{ filePath };
    std::string line;
    int N = 0;
    if (!testFile.is_open()) { //if not open
        std::cerr << "File not open" << "\n"; //output char error
    }
    else {
        while (std::getline(testFile, line)) {
            //split string
            N = N + 2;
            std::string delimiter = ",";
            std::string firstString = line.substr(0, line.find(delimiter));
            std::string secondString = line.substr(line.find(delimiter) + 1, line.back());
            auto pair = std::make_pair(firstString, secondString);
            tapeA.push_back(pair);
            tapeB.push_back(pair);
        }
    }
    return N;
}

void sortTapeSecond(std::list<std::pair<std::string, std::string>>& tape) {
    tape.sort([](const std::pair<std::string, std::string>& pair1, const std::pair<std::string, std::string>& pair2) {  //lambda function
        return pair1.second < pair2.second; //a = smallest char  Z= biggest
        }
    );

}
void sortTapeSecond(std::list<std::pair<std::string, int>>& tape) { //overload for int
    tape.sort([](const std::pair<std::string, int>& pair1, const std::pair<std::string, int>& pair2) {  //lambda function
        return pair1.second < pair2.second; //a = smallest char  Z= biggest
        }
    );

}

void sortTapeFirst(std::list<std::pair<std::string, std::string>>& tape) {
    tape.sort([](const std::pair<std::string, std::string>& pair1, const std::pair<std::string, std::string>& pair2) {  //lambda function
        return pair1.first < pair2.first; //a = smallest char  Z= biggest
        }
    );
}

void sortTapeFirst(std::list<std::pair<std::string, int>>& tape) { //overload for string int pair
    tape.sort([](const std::pair<std::string, int>& pair1, const std::pair<std::string, int>& pair2) {  //lambda function
        return pair1.first < pair2.first; //a = smallest char  Z= biggest
        }
    );
}

void compareAB(std::list<std::pair<std::string, std::string>>& tapeA, std::list<std::pair<std::string, std::string>>& tapeB,
    std::list<std::pair<std::string, std::string>>& tapeC, std::list<std::pair<std::string, int>>& tapeP) {
    auto tapeAit = tapeA.begin();
    auto tapeBit = tapeB.begin();
    while (tapeAit != tapeA.end()) {
        if (tapeAit->second == tapeBit->first) {
            auto pair = std::make_pair(tapeAit->first, tapeBit->second);
            tapeC.push_back(pair);
            tapeAit++;
            tapeBit++;
        }
        else if (tapeAit->second < tapeBit->first) {
            int pos = std::distance(tapeA.begin(), tapeAit);
            auto pair = std::make_pair(tapeAit->first, (pos - 1));
            auto pair2 = std::make_pair(tapeAit->second, pos);
            tapeP.push_back(pair);
            tapeP.push_back(pair2);
            tapeAit++;
        }
        else if (tapeAit->second > tapeBit->first) {
            tapeBit++;
        }
        else {
            std::cout << "error";
        }

    }
    sortTapeFirst(tapeP);
}

void tapeManipulation(std::list<std::pair<std::string, std::string>>& tapeA, std::list<std::pair<std::string, std::string>>& tapeB,
    std::list<std::pair<std::string, std::string>>& tapeC, std::list<std::pair<std::string, int>>& tapeP, std::list<std::pair<std::string, int>>& tapeF, int& d) {
    auto tapeAit = tapeA.begin();
    auto tapeBit = tapeB.begin();
    auto tapePit = tapeP.begin();
    bool tapePEnd = false;
    bool tapeBEnd = false;
    while (tapeAit != tapeA.end()) {
        if (tapePit == tapeP.end()) {
            tapePit--;
            tapePEnd = true;
        }
        if (tapeBit == tapeB.end()) {
            tapeBit--;
            tapeBEnd = true;
        }
        if (tapeAit->second == tapeBit->first) {
            auto pair = std::make_pair(tapeAit->first, tapeBit->second);
            tapeC.push_back(pair);
            tapeAit++;
            tapeBit++;
        }
        else if (tapeAit->second == tapePit->first) {
            auto pair = std::make_pair(tapeAit->first, tapePit->second - d);
            tapeF.push_back(pair);
            tapeAit++;
            tapePit++;
        }
        else if (tapeAit->second > tapePit->first && tapePEnd == false) {
            tapePit++;
        }
        else if (tapeAit->second > tapeBit->first && tapeBEnd == false) {
            tapeBit++;
        }
        else {
            tapeAit++;
        }
    }
}

void mergeTapes(std::list<std::pair<std::string, int>>& tapeP, std::list<std::pair<std::string, int>>& tapeF) { //f into p preserving alphabetical ordering of first components);
    auto tapePit = tapeP.begin();
    auto tapeFit = tapeF.begin();
    tapeP.merge(tapeF);
}

void copyToResult(std::list<std::pair<std::string, int>>& tapeP, std::list<std::string> tapeResult) {
    for (auto pair : tapeP) {
        tapeResult.push_back(pair.first);
    }
}