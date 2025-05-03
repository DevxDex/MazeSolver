#Maze Solver (BFS and DFS)
=========================
Checkout our projects portfolio:
https://sites.google.com/effat.edu.sa/maze-solver/home?authuser=1

This project implements a maze-solving program using two classic graph traversal algorithms:
- Breadth-First Search (BFS)
- Depth-First Search (DFS)

The program reads a maze from a text file, solves it using both algorithms, displays the results in the console, and saves the solved mazes to output files.

---

How to Use
----------

1. Place your maze file (e.g., maze.txt) in the same directory as the executable, or provide the correct path when prompted.
2. Run the program.
3. When prompted, type the maze file name (example: maze.txt or input/maze.txt).
4. The program will:
   - Read and validate the maze
   - Solve it using BFS and DFS
   - Print the number of steps and the path to the console
   - Save results to output/solved_bfs.txt and output/solved_dfs.txt

---

Maze Format
-----------

The maze must be rectangular and contain only the following characters:
- S = Start point (only one allowed)
- E = End point (only one allowed)
- 0 = Open path
- 1 = Wall

Example:

S000100  
1001010  
1001010  
1011010  
1000000  
100000E  

---

File Structure
--------------

- main.cpp          → Program entry point, user input, runs algorithms
- maze.h / maze.cpp → Handles reading, validating, printing, and saving mazes
- solver.h / solver.cpp → Implements BFS and DFS pathfinding
- CMakeLists.txt    → Build configuration (for CLion/CMake)
- maze.txt          → Example maze input file
- output/           → Folder where solved mazes are saved
- README.md         → This file

---

Features
--------

- Fully modular and separated into .h and .cpp files
- Input validation (structure, characters, start/end points)
- Solves the maze using both algorithms
- Tracks and displays number of steps in each solution
- Outputs results to separate files for comparison

---

How to Compile and Run
-----------------------

Using g++ (example):
  g++ main.cpp maze.cpp solver.cpp -o MazeSolver
  ./MazeSolver

Or use CLion / Visual Studio / Code::Blocks to open and run the project.
