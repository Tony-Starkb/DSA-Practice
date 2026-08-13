class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));
        vector<vector<int>> distance(m, vector<int>(n, 0));
        queue<pair<pair<int, int>, int>> q;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(mat[i][j] == 0) {
                    visited[i][j] = 1;
                    q.push({{i, j}, 0});
                }else {
                    visited[i][j] = 0;
                }
            }
        }

        while(!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int step = q.front().second;
            q.pop();
            distance[row][col] = step;

            int delrow[] = {0, -1, 0, 1};
            int delcol[] = {-1, 0, 1, 0};

            for(int i=0; i<4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if(nrow >=0 && nrow < m && ncol >= 0 && ncol < n && visited[nrow][ncol]==0) {
                    visited[nrow][ncol] = 1;
                    q.push({{nrow, ncol}, step+1});
                }
            }
        }

        return distance;
    }
};