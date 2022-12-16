#include "../headers/Task2.h"

int main(int argc, char* argv[]) {
    std::chrono::steady_clock::time_point startTime = std::chrono::steady_clock::now();
    std::string filePath = checkIfInput(argc, argv);
    if (filePath == "Error invalid File") {
        return 1;
    }
    std::unordered_map<std::string, std::string> bricks;
    std::unordered_map<std::string, std::string> bricksBack; //making a 2nd map copy is faster than iterating through 1
    std::unordered_map<std::string, std::string> result; //create map for results
    bool fileOpen = fileToUnMap(filePath, bricks, bricksBack);
    if (fileOpen == false) {
        return 1;
    }
    std::string startBrick = bricks.begin()->first; //can just start with the first one in the map
    std::string lastAdded; //tracks last added brick into results
    twoASouth(startBrick, bricks, result);
    lastAdded = twoANorth(startBrick, bricksBack, result);
    //timing tests
    std::chrono::steady_clock::time_point finishTime = std::chrono::steady_clock::now();
    std::chrono::nanoseconds timeTaken = std::chrono::duration_cast<std::chrono::nanoseconds>(finishTime - startTime);
    std::ofstream afile;
    afile.open("result.txt", std::ios::app);
    afile << timeTaken.count() << "\n";
    afile.close();
    //outputResult(bricks, lastAdded);


    return 0;
}

int fileToUnMap(std::string& filePath, std::unordered_map<std::string, std::string>& bricks, std::unordered_map<std::string, std::string>& bricksBack) {
    std::ifstream testFile{ filePath };
    std::string line;
    if (!testFile.is_open()) { //if not open
        std::cerr << "File not open" << "\n"; //output char error
        return false;
    }
    while (std::getline(testFile, line)) {
        std::string delimiter = ","; //split string
        std::string firstString = line.substr(0, line.find(delimiter));
        std::string secondString = line.substr(line.find(delimiter) + 1, line.back());
        bricks[firstString] = secondString;
        bricksBack[secondString] = firstString;  //allows us to use find on values by making another map
    }
    return true;
}
void twoASouth(std::string startBrick, std::unordered_map<std::string, std::string>& bricks, std::unordered_map<std::string, std::string>& result) {
    std::string nextBrick = bricks[startBrick];
    result[startBrick] = nextBrick;
    bool finishedSouth = false;
    std::string lastAdded = "";
    while (!finishedSouth) { //check all south of start brick
        if (bricks.find(nextBrick) != bricks.end() && bricks.find(nextBrick)->first == nextBrick) {
            result[nextBrick] = bricks[nextBrick];
            lastAdded = nextBrick;
            nextBrick = bricks[nextBrick];
        }
        if (nextBrick.empty() || bricks[nextBrick] == bricks[lastAdded]) {  // If no match
            finishedSouth = true;
        }
    }
}
std::string twoANorth(std::string startBrick, std::unordered_map<std::string, std::string>& bricksBack, std::unordered_map<std::string, std::string>& result) {
    std::string nextBrick = bricksBack.find(startBrick)->second;
    bool finishedNorth = false;
    std::string lastAdded = "";
    while (!finishedNorth) {        //check north of start brick
        lastAdded = nextBrick;
        if (bricksBack.find(nextBrick) != bricksBack.end() && bricksBack.find(nextBrick)->first == nextBrick) {
            result[nextBrick] = bricksBack[nextBrick];
            nextBrick = bricksBack[nextBrick];
        }
        if (nextBrick == "" || nextBrick == lastAdded) {  // If no match
            finishedNorth = true;
        }
    }
    return lastAdded;
}
void outputResult(std::unordered_map<std::string, std::string>& bricks, std::string lastAdded) {
    std::unordered_map<std::string, std::string>::iterator resultIter = bricks.find(lastAdded);
    for (auto& resultIter : bricks) {
        std::cout << lastAdded << "\n"; //check line endings for linux
        lastAdded = bricks[lastAdded];
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
////std::string startbrick = "rectangle";
//result = brick.first + result;
//result = startbrick + result;
//std::unordered_map<std::string, std::string>::const_iterator iterator = bricks.find(nextbrick);
//size_t found = result.find("star");
//result += bricks[nextBrick];
//std::string result = bricks[startBrick];  //shows result of searching
//resultIter = bricks[resultIter->first];
//while not done
//print out first 
//then print map[iter.second] 
//std::cout << resultIter.first << " " << resultIter.second << "\n";
//std::cout << result << std::endl; // Output the result
///if (bricks.find(nextBrick) != bricks.begin() && bricks.find(nextBrick)->second == nextBrick) 
//result[nextBrick] = bricks[nextBrick];
//lastAdded = nextBrick;
//nextBrick = bricks[nextBrick];
//}*/
//std::unordered_map<std::string, std::string>::iterator resultIter = bricks.begin();
//
//lastAdded = nextBrick;
//for (const auto& brick : bricks) { //iterating as cant index u_map or use find as no key
//if (brick.second == nextBrick) { //really slow
//result[brick.first] = brick.second;
//nextBrick = brick.first;
//break;
//}
//}
//if (nextBrick.empty() || lastAdded == nextBrick) { // If no match
//finishedNorth = true;
//}
//}
//for (const auto& brick : bricks) {  //pass value by reference, const because cant change brick values
////same as creating iterator
//if (brick.first == nextBrick) {
//result[brick.first] = brick.second;
//nextBrick = brick.second;
//lastAdded = brick.first;
//break;
//}
//}
//northern = southern testing
///*bricks["star"] = "square";
//bricks["circle"] = "star";
//bricks["diamond"] = "octagon";
//bricks["square"] = "rectangle";
//bricks["rectangle"] = "diamond";
//
//bricksBack["square"] = "star";
//bricksBack["star"] = "circle";
//bricksBack["octagon"] = "diamond";
//bricksBack["rectangle"] = "square";
//bricksBack["diamond"] = "rectangle";*/
//for (const auto& brick : bricks) {  //pass value by reference, const because cant change brick values
////same as creating iterator
//if (brick.first == nextBrick) {
//result[brick.first] = brick.second;
//nextBrick = brick.second;
//lastAdded = brick.first;
//break;
//}
//}