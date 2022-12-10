#include <iostream>
#include <unordered_map>
#include <string>

void task2a() {
    std::unordered_map<std::string, std::string> bricks;

    // northern = southern
    bricks["star"] = "square";
    bricks["circle"] = "star";
    bricks["diamond"] = "octagon";
    bricks["square"] = "rectangle";
    bricks["rectangle"] = "diamond";
    
    std::string startBrick = "square";
    std::string nextBrick = bricks[startBrick];
    std::string result = bricks[startBrick];  //shows result of searching
    bool finishedNorth = false;
    bool finishedSouth = false;
    std::string lastAdded = "";
    while (!finishedSouth) { //check all south
        for (const auto& brick : bricks) {  //pass value by reference, const because cant change brick values
            //same as for(int i = 0; i< bricks.size() ; i++)
            if (brick.first == nextBrick) {
                result += bricks[nextBrick]yb ;
                nextBrick = brick.second;
                lastAdded = brick.first;
                break;
            }
        }
        if (nextBrick.empty() || bricks[nextBrick] == bricks[lastAdded]) {  // If no match
            finishedSouth = true;
        }
    }
    nextBrick = startBrick; //reset next brick to be back at start point
    result = startBrick + result;
    while (!finishedNorth) {        //check north
        lastAdded = nextBrick;
        for (const auto& brick : bricks) { //iterating faster than []
            if (brick.second == nextBrick) {
                result = brick.first + result;
                nextBrick = brick.first;
                break;
            }
        }
        //std::unordered_map<std::string, std::string>::const_iterator iterator = bricks.find(nextBrick);
        //size_t found = result.find("star");
        if (nextBrick.empty() || lastAdded == nextBrick) { // If no match
            finishedNorth = true;
        }
    }
    // Output the result
    std::cout << result << std::endl;
}