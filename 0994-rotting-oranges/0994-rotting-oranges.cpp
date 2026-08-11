class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // first put all the rotten oranges in the queue
        //keep track of the no. of fresh oranges
        // perforn bfs on the grid, slowly rottening the oranges and counting the minutes
        // if(fresh != 0) return -1 else return min.

        int n = grid.size(), m = grid[0].size();

        queue<pair<int, int>> q;
        int fresh = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 2) {
                    q.push({i, j});
                }else if(grid[i][j] == 1) {
                    fresh++;
                }
            }
        } 

        int min = 0;

        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1}; 
        
        while(!q.empty() && fresh>0) {
            int size = q.size();
            while(size--) {
                auto [row, col] = q.front();
                q.pop();

                for(int k=0; k<4; k++) {
                    int nrow = row + dr[k];
                    int ncol = col + dc[k];

                    if (nrow >= 0 && nrow < n &&
                        ncol >= 0 && ncol < m &&
                        grid[nrow][ncol] == 1) {

                        grid[nrow][ncol] = 2;
                        fresh--;

                        q.push({nrow, ncol});
                    }
                }

            }
            min++;
        }

        return fresh == 0? min: -1;
    }
};