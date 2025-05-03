#include "maze.h"
#include <fstream>
#include <iostream>

using namespace std;

vector<vector<char>> readMazeFromFile(const string& filename, pair<int, int>& start, pair<int, int>& end) {
    ifstream file(filename);
    vector<vector<char>> maze;
    string line;
    int row = 0;
    int expectedWidth = -1;
    bool foundStart = false, foundEnd = false;

    while (getline(file, line)) {
        if (!line.empty() && line.back() == '\r') {
            line.pop_back();
        }

        if (expectedWidth == -1) {
            expectedWidth = static_cast<int>(line.length());
        } else if (line.length() != static_cast<size_t>(expectedWidth)) {
            cerr << "Error: Inconsistent row length at row " << row << ".\n";
            exit(1);
        }

        vector<char> mazeRow;
        for (int col = 0; col < static_cast<int>(line.length()); ++col) {
            char c = line[col];
            if (c != '0' && c != '1' && c != 'S' && c != 'E') {
                cerr << "Error: Invalid character '" << c << "' at row " << row << ", col " << col << ".\n";
                exit(1);
            }

            if (c == 'S') {
                if (foundStart) {
                    cerr << "Error: Multiple start points 'S' found.\n";
                    exit(1);
                }
                start = make_pair(row, col);
                foundStart = true;
            }

            if (c == 'E') {
                if (foundEnd) {
                    cerr << "Error: Multiple end points 'E' found.\n";
                    exit(1);
                }
                end = make_pair(row, col);
                foundEnd = true;
            }

            mazeRow.push_back(c);
        }

        maze.push_back(mazeRow);
        row++;
    }

    if (!foundStart || !foundEnd) {
        cerr << "Error: Maze must contain exactly one 'S' and one 'E'.\n";
        exit(1);
    }

    return maze;
}

void printMaze(const vector<vector<char>>& maze) {
    for (const auto& row : maze) {
        for (char cell : row) {
            cout << cell;
        }
        cout << '\n';
    }
}

void saveMazeToFile(const string& filename, const vector<vector<char>>& maze) {
    ofstream out(filename);
    for (const auto& row : maze) {
        for (char cell : row) {
            out << cell;
        }
        out << '\n';
    }
}

int countPathSteps(const vector<vector<char>>& maze) {
    int count = 0;
    for (const auto& row : maze) {
        for (char cell : row) {
            if (cell == '*') {
                count++;
            }
        }
    }
    return count;
}
