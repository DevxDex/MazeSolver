#ifndef SOLVER_H
#define SOLVER_H

#include <vector>
#include <utility>

bool bfs(const std::vector<std::vector<char>>&, std::pair<int, int>, std::pair<int, int>, std::vector<std::vector<char>>&);
bool dfs(const std::vector<std::vector<char>>&, std::pair<int, int>, std::pair<int, int>, std::vector<std::vector<char>>&);

#endif
