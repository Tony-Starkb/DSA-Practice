class Solution {
private:
    void bfs(int node, vector<int>& visited,
             vector<vector<int>>& isConnected) {

        queue<int> q;

        q.push(node);
        visited[node] = 1;

        while (!q.empty()) {

            int current = q.front();
            q.pop();

            for (int neighbor = 0;
                 neighbor < isConnected.size();
                 neighbor++) {

                if (isConnected[current][neighbor] == 1 &&
                    visited[neighbor] == 0) {

                    visited[neighbor] = 1;
                    q.push(neighbor);
                }
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {

        int n = isConnected.size();

        vector<int> visited(n, 0);

        int provinces = 0;

        for (int i = 0; i < n; i++) {

            if (visited[i] == 0) {

                provinces++;
                bfs(i, visited, isConnected);
            }
        }

        return provinces;
    }
};