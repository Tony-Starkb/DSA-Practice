class Solution {
private:
    void bfs(int node, vector<int> &visited, unordered_map<int, list<int>> adj) {
        queue<int> q;
        q.push(node);
        visited[node] = 1;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(auto it: adj[node]) {
                if(visited[it] == 0) {
                    q.push(it);
                    visited[it] = 1;
                }
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int, list<int>> adj;
        
        for (int i = 0; i < isConnected.size(); i++) {
            for (int j = 0; j < isConnected[i].size(); j++) {

                if (isConnected[i][j] == 1) {
                    adj[i].push_back(j);
                }
            }
        }

        vector<int> visited(isConnected.size(), 0);

        int count = 0;
        for(int i=0; i<isConnected.size(); i++) {
            if(visited[i] == 0) {
                count++;
                bfs(i, visited, adj);
            }
        }

        return count;
    }
};