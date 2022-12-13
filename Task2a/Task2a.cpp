#include "../headers/Task2.h"
#include <unordered_map>

int task2a(std::string filePath) {
    std::unordered_map<std::string, std::string> bricks;
    // northern = southern testing
    /*bricks["star"] = "square";
    bricks["circle"] = "star";
    bricks["diamond"] = "octagon";
    bricks["square"] = "rectangle";
    bricks["rectangle"] = "diamond";*/


    std::ifstream testFile{ filePath };
    std::string line;
    if (!testFile.is_open()) { //if not open
        std::cerr << "File not open" << "\n"; //output char error
        return 1;
    }
    while (std::getline(testFile, line)) {
        std::string delimiter = ","; //split string
        std::string firstString = line.substr(0, line.find(delimiter));
        std::string secondString = line.substr(line.find(delimiter) + 1, line.back());
        bricks[firstString] = secondString;
        
    }
    std::string startBrick = bricks.begin()->first; //can just start with the first one in the map
    std::string nextBrick = bricks[startBrick];

    std::unordered_map<std::string,std::string> result; //create map for results
    bool finishedNorth = false;
    bool finishedSouth = false;
    std::string lastAdded = "";
    result[startBrick] = nextBrick;


    while (!finishedSouth) { //check all south of start brick
        if (bricks.find(nextBrick) != bricks.end() && bricks.find(nextBrick)->first == nextBrick){
            result[nextBrick] = bricks[nextBrick]; 
            lastAdded = nextBrick;
            nextBrick = bricks[nextBrick];
        }
        //for (const auto& brick : bricks) {  //pass value by reference, const because cant change brick values
        //    //same as creating iterator
        //    if (brick.first == nextBrick) {
        //        result[brick.first] = brick.second;
        //        nextBrick = brick.second;
        //        lastAdded = brick.first;
        //        break;
        //    }
        //}
        if (nextBrick.empty() || bricks[nextBrick] == bricks[lastAdded]) {  // If no match
            finishedSouth = true;
        }
    }
    nextBrick = startBrick; //reset next brick to be back at start point

    while (!finishedNorth) {        //check north of start brick
        lastAdded = nextBrick;
        for (const auto& brick : bricks) { //iterating as cant index u_map or use find as no key
            if (brick.second == nextBrick) { //really slow
                result[brick.first] = brick.second;
                nextBrick = brick.first;
                break;
            }
        }
        if (nextBrick.empty() || lastAdded == nextBrick) { // If no match
            finishedNorth = true;
        }
    }
    std::unordered_map<std::string, std::string>::iterator resultIter = bricks.find(lastAdded);
    for (auto resultIter : bricks) {
        std::cout << lastAdded << "\n";
        lastAdded = bricks[lastAdded];
    }
    return 0;
}

int main(int argc, char* argv[]) {
    std::string filePath = "input-pairs-1K.txt";
    task2a(filePath);
    if (argc != 1) { //make sure filepath entered
        try {
            std::string filePath = argv[1];
            task2a(filePath);
        }
        catch (...) {
            std::cerr << "Error establishing filepath";
        }
    }
}

//code graveyard
//result = brick.first + result;
//result = startBrick + result;
//std::unordered_map<std::string, std::string>::const_iterator iterator = bricks.find(nextBrick);
//size_t found = result.find("star");
//result += bricks[nextBrick];
//std::string result = bricks[startBrick];  //shows result of searching
///resultIter = bricks[resultIter->first];
//while not done
//print out first 
// then print map[iter.second] 
//std::cout << resultIter.first << " " << resultIter.second << "\n";
 //std::cout << result << std::endl; // Output the result
/*if (bricks.find(nextBrick) != bricks.begin() && bricks.find(nextBrick)->second == nextBrick) {
            result[nextBrick] = bricks[nextBrick];
            lastAdded = nextBrick;
            nextBrick = bricks[nextBrick];
        }*/
        //std::unordered_map<std::string, std::string>::iterator resultIter = bricks.begin();