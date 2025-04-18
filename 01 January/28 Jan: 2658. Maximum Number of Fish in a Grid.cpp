class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int res = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] > 0) {  
                    res = max(res, bfs(grid, i, j));
                }
            }
        }
        return res;
    }

private:
    int bfs(vector<vector<int>>& grid, int i, int j) {
        int res = 0;
        queue<pair<int, int>> q;
        q.push({i, j});
        while (!q.empty()) {
            auto [r, c] = q.front(); q.pop();
            if (grid[r][c] == 0) continue;
            res += grid[r][c];
            grid[r][c] = 0;  // Mark cell as visited
            
            vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
            for (auto [dr, dc] : directions) {
                int nr = r + dr, nc = c + dc;
                if (nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size() && grid[nr][nc] > 0) {
                    q.push({nr, nc});
                }
            }
        }
        return res;
    }
};
