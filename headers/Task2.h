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


//2
std::string checkIfInput(int argc, char* argv[]);

//2a

int fileToUnMap(std::string& filePath, std::unordered_map<std::string, std::string>& bricks, std::unordered_map<std::string, std::string>& bricksBack);
void twoASouth(std::string startBrick, std::unordered_map<std::string, std::string>& bricks, std::unordered_map<std::string, std::string>& result);
std::string twoANorth(std::string startBrick, std::unordered_map<std::string, std::string>& bricksBack, std::unordered_map<std::string, std::string>& result);
void outputResult(std::unordered_map<std::string, std::string>& bricks, std::string lastAdded);


//2b
std::string fileToList(std::string& filePath, std::list<std::string>& bricks);
void listToOMap(std::list<std::string>& bricks, std::map<std::string, std::string>& mapForSearching);
void twoBSouth(std::list<std::string>& bricks, std::map<std::string, std::string>& mapForSearching, std::list<std::string>& result, std::string nextBrick);
void twoBNorth(std::list<std::string>& bricks, std::map<std::string, std::string>& mapForSearching, std::list<std::string>& result, std::string nextBrick, std::string lastBrick);

#endif