#include <vector>

class Solution {
private:
    long long dfs(std::vector<std::vector<int>>& grid, int r, int c) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Base case
        if (r < 0 || c < 0 || r >= m || c >= n || grid[r][c] == 0) {
            return 0;
        }
                long long current_val = grid[r][c];
        grid[r][c] = 0;
        
        current_val += dfs(grid, r + 1, c);
        current_val += dfs(grid, r - 1, c);
        current_val += dfs(grid, r, c + 1);
        current_val += dfs(grid, r, c - 1);
        
        return current_val;
    }

public:
    int countIslands(std::vector<std::vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int valid_islands = 0;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] > 0) {
                    long long island_sum = dfs(grid, i, j);
                                        if (island_sum % k == 0) {
                        valid_islands++;
                    }
                }
            }
        }
        
        return valid_islands;
    }
};