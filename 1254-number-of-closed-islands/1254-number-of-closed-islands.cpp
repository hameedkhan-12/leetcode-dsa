class Solution {
public:
    int m, n;
    void dfs(int r, int c, vector<vector<int>>& grid) {
        if (r < 0 || c < 0 || r >= m || c >= n)
            return;

        if (grid[r][c] == 1)
            return;

        grid[r][c] = 1;

        dfs(r - 1, c, grid);
        dfs(r + 1, c, grid);
        dfs(r, c - 1, grid);
        dfs(r, c + 1, grid);
    }

    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        for (int j = 0; j < n; j++) {
            if (grid[0][j] == 0)
                dfs(0, j, grid);

            if (grid[m - 1][j] == 0)
                dfs(m - 1, j, grid);
        }

        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 0)
                dfs(i, 0, grid);

            if (grid[i][n - 1] == 0)
                dfs(i, n - 1, grid);
        }

        int ans = 0;

        for (int i = 1; i < m - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                if (grid[i][j] == 0) {
                    ans++;
                    dfs(i, j, grid);
                }
            }
        }
        return ans;
    }
};