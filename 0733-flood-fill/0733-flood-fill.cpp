class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size(), m = image[0].size();

        queue<pair<int, int>> q;
        q.push({sr, sc});
        int refer = image[sr][sc];

        if (refer == color) {
            return image;
        }
        
        image[sr][sc] = color;

        while(!q.empty()) {
            int row = q.front().first, col = q.front().second;
            q.pop();

            int drow[] = {-1, 0, 1, 0};
            int dcol[] = {0, 1, 0, -1};

            for (int k = 0; k < 4; k++) {
                int nrow = row + drow[k];
                int ncol = col + dcol[k];

                if (nrow >= 0 && nrow < n &&
                    ncol >= 0 && ncol < m &&
                    image[nrow][ncol] == refer) {

                    image[nrow][ncol] = color;
                    q.push({nrow, ncol});
                }
            }
        }
        return image;
    }
};