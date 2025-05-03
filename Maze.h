#ifndef MAZE_H
#define MAZE_H

#include <vector>
#include <string>
#include <utility>

std::vector<std::vector<char>> readMazeFromFile(const std::string& filename, std::pair<int, int>& start, std::pair<int, int>& end);
void printMaze(const std::vector<std::vector<char>>& maze);
void saveMazeToFile(const std::string& filename, const std::vector<std::vector<char>>& maze);
int countPathSteps(const std::vector<std::vector<char>>& maze);

#endif
