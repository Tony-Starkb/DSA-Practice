class Solution {
private:
    void dfs(int row, int col, vector<vector<int>> &visited, vector<vector<char>>& board, int delrow[], int delcol[]) {
        visited[row][col] = 1;
        int m = board.size(), n = board[0].size();

        for(int i=0; i<4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !visited[nrow][ncol] && board[nrow][ncol]=='O') {
                dfs(nrow, ncol, visited, board, delrow, delcol);
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        int delrow[] = {0, -1, 0, 1};
        int delcol[] = {-1, 0, 1, 0};

        for(int j=0; j<n; j++) {
            if(board[0][j] == 'O' && !visited[0][j]) {
                dfs(0, j, visited, board, delrow, delcol);
            }
            if(board[m-1][j] == 'O' && !visited[m-1][j]) {
                dfs(m-1, j, visited, board, delrow, delcol);
            }
        }

        for(int i=0; i<m; i++) {
            if(board[i][0] == 'O' && !visited[i][0]) {
                dfs(i, 0, visited, board, delrow, delcol);
            }

            if(board[i][n-1] == 'O' && !visited[i][n-1]) {
                dfs(i, n-1, visited, board, delrow, delcol);
            }
        }

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(!visited[i][j] && board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
        
    }
};