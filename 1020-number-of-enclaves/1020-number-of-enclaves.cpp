class Solution {
private:
    void dfs(int row, int col, vector<vector<int>> &visited, vector<vector<int>>& grid, int delrow[], int delcol[]) {
        visited[row][col] = 1;
        int m = grid.size(), n = grid[0].size();

        for(int i=0; i<4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !visited[nrow][ncol] && grid[nrow][ncol] == 1) {
                dfs(nrow, ncol, visited, grid, delrow, delcol);
            }
        }
    }

public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        int delrow[] = {0, -1, 0, 1};
        int delcol[] = {-1, 0, 1, 0};

        for(int j=0; j<n; j++) {
            if(!visited[0][j] && grid[0][j] == 1) {
                dfs(0, j, visited, grid, delrow, delcol);
            }
            if(!visited[m-1][j] && grid[m-1][j] == 1) {
                dfs(m-1, j, visited, grid, delrow, delcol);
            }
        }

        for(int i=0; i<m; i++) {
            if(!visited[i][0] && grid[i][0] == 1) {
                dfs(i, 0, visited, grid, delrow, delcol);
            }
            if(!visited[i][n-1] && grid[i][n-1] == 1) {
                dfs(i, n-1, visited, grid, delrow, delcol);
            }
        }

        int count = 0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(!visited[i][j] && grid[i][j] == 1) {
                    count++;
                }
            }
        }

        return count;
    }
};