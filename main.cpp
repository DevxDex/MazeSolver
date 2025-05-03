#include "maze.h"
#include "solver.h"
#include <iostream>
#include <fstream>
#include <filesystem>


using namespace std;

int main() {
 
    std::filesystem::create_directory("output");

    pair<int, int> start, end;
    string filename;

    cout << "Enter maze file name (e.g., input/maze.txt): ";
    cin >> filename;

    ifstream testfile(filename);
    if (!testfile.is_open()) {
        cerr << "Error: Could not open file '" << filename << "'\n";
        return 1;
    }
    testfile.close();

    vector<vector<char>> maze = readMazeFromFile(filename, start, end);

    cout << "\nOriginal Maze:\n";
    printMaze(maze);

    cout << "\nStart: (" << start.first << ", " << start.second << ")\n";
    cout << "End:   (" << end.first << ", " << end.second << ")\n";

    vector<vector<char>> bfsSol = maze;
    if (bfs(maze, start, end, bfsSol)) {
        cout << "\nSolved by BFS:\n";
        printMaze(bfsSol);
        saveMazeToFile("output/solved_bfs.txt", bfsSol);
        cout << "BFS Path Steps: " << countPathSteps(bfsSol) << "\n";
    } else {
        cout << "\nNo path found by BFS.\n";
    }

    vector<vector<char>> dfsSol = maze;
    if (dfs(maze, start, end, dfsSol)) {
        cout << "\nSolved by DFS:\n";
        printMaze(dfsSol);
        saveMazeToFile("output/solved_dfs.txt", dfsSol);
        cout << "DFS Path Steps: " << countPathSteps(dfsSol) << "\n";
    } else {
        cout << "\nNo path found by DFS.\n";
    }

    return 0;
}
