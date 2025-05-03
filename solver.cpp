#include "solver.h"
#include <queue>
#include <stack>

using namespace std;

const vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

bool bfs(const vector<vector<char>>& maze, pair<int, int> start, pair<int, int> end, vector<vector<char>>& solution) {
    int rows = maze.size(), cols = maze[0].size();
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    vector<vector<pair<int, int>>> parent(rows, vector<pair<int, int>>(cols, {-1, -1}));

    q.push(start);
    visited[start.first][start.second] = true;

    while (!q.empty()) {
        auto current = q.front(); q.pop();
        if (current == end) {
            pair<int, int> step = end;
            while (step != start) {
                solution[step.first][step.second] = '*';
                step = parent[step.first][step.second];
            }
            solution[start.first][start.second] = 'S';
            solution[end.first][end.second] = 'E';
            return true;
        }

        for (const auto& dir : directions) {
            int r = current.first + dir.first, c = current.second + dir.second;
            if (r >= 0 && r < rows && c >= 0 && c < cols &&
                maze[r][c] != '1' && !visited[r][c]) {
                visited[r][c] = true;
                q.push({r, c});
                parent[r][c] = current;
            }
        }
    }
    return false;
}

bool dfs(const vector<vector<char>>& maze, pair<int, int> start, pair<int, int> end, vector<vector<char>>& solution) {
    int rows = maze.size(), cols = maze[0].size();
    stack<pair<int, int>> s;
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    vector<vector<pair<int, int>>> parent(rows, vector<pair<int, int>>(cols, {-1, -1}));

    s.push(start);
    visited[start.first][start.second] = true;

    while (!s.empty()) {
        auto current = s.top(); s.pop();
        if (current == end) {
            pair<int, int> step = end;
            while (step != start) {
                solution[step.first][step.second] = '*';
                step = parent[step.first][step.second];
            }
            solution[start.first][start.second] = 'S';
            solution[end.first][end.second] = 'E';
            return true;
        }

        for (const auto& dir : directions) {
            int r = current.first + dir.first, c = current.second + dir.second;
            if (r >= 0 && r < rows && c >= 0 && c < cols &&
                maze[r][c] != '1' && !visited[r][c]) {
                visited[r][c] = true;
                s.push({r, c});
                parent[r][c] = current;
            }
        }
    }
    return false;
}
