#pragma once
#ifndef mainHeader_H
#define mainHeader_H
#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include <list>
#include <map>
#include <sstream>
#include <chrono>
#include <algorithm>
#include <utility>
#include <vector>
#include <fstream>
#include <string>

//declare all function definitions

//
std::string checkIfInput(int argc, char* argv[]);

//2a

int fileToUnMap(std::string& filePath, std::unordered_map<std::string, std::string>& bricks, std::unordered_map<std::string, std::string>& bricksBack);
void twoASouth(std::string startBrick, std::unordered_map<std::string, std::string>& bricks, std::unordered_map<std::string, std::string>& result);
std::string twoANorth(std::string startBrick, std::unordered_map<std::string, std::string>& bricksBack, std::unordered_map<std::string, std::string>& result);
void outputResult(std::unordered_map<std::string, std::string>& bricks, std::string lastAdded);

//2b
void fileToList(std::string& filePath, std::list<std::string>& bricks);
void listToOMap(std::list<std::string>& bricks, std::map<std::string, std::string>& mapForSearchingSouth, std::map<std::string, std::string >& mapForSearchingNorth);
void twoBSouth(std::list<std::string>& bricks, std::map<std::string, std::string>& mapForSearchingSouth, std::list<std::string>& result, std::string nextBrick);
void twoBNorth(std::list<std::string>& bricks, std::map<std::string, std::string>& mapForSearchingNorth, std::list<std::string>& result, std::string nextBrick, std::string lastBrick);
void outputResult(std::list<std::string> result);

//2b Attempt 2
std::string fileToMap(std::string& filePath, std::map<std::string, std::string>& mapForSearchingSouth, std::map<std::string, std::string >& mapForSearchingNorth);
void twoBSouth(std::map<std::string, std::string>& mapForSearchingSouth, std::list<std::string>& result, std::string nextBrick);
void twoBNorth(std::map<std::string, std::string>& mapForSearchingNorth, std::list<std::string>& result, std::string nextBrick);
void outputResult(std::list<std::string> result);


//6
int addToTape(std::string& filePath, std::list<std::pair<std::string, std::string>>& tapeA, std::list<std::pair<std::string, std::string>>& tapeB);
void sortTapeSecond(std::list<std::pair<std::string, std::string>>& tape);
void sortTapeSecond(std::list<std::pair<std::string, int>>& tape); //overload for int
void sortTapeFirst(std::list<std::pair<std::string, std::string>>& tape);
void sortTapeFirst(std::list<std::pair<std::string, int>>& tape); //overload for string int pair
void compareAB(std::list<std::pair<std::string, std::string>>& tapeA, std::list<std::pair<std::string, std::string>>& tapeB,
    std::list<std::pair<std::string, std::string>>& tapeC, std::list<std::pair<std::string, int>>& tapeP);
void tapeManipulation(std::list<std::pair<std::string, std::string>>& tapeA, std::list<std::pair<std::string, std::string>>& tapeB,
    std::list<std::pair<std::string, std::string>>& tapeC, std::list<std::pair<std::string, int>>& tapeP, std::list<std::pair<std::string, int>>& tapeF, int& d);
void mergeTapes(std::list<std::pair<std::string, int>>& tapeP, std::list<std::pair<std::string, int>>& tapeF);//f into p preserving alphabetical ordering of first components);
void copyToResult(std::list<std::pair<std::string, int>>& tapeP, std::list<std::string> tapeResult);
#endif

