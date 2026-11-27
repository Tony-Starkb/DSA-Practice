class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0;
        int maxLen = 0;
        unordered_map<char, int> visited;

        while(j < s.size()) {
            if(visited.find(s[j]) != visited.end()) {
                i = max(i, visited[s[j]]+1);
            }

            visited[s[j]] = j;
            maxLen = max(maxLen, j-i+1);
            j++;
        }

        return maxLen;
    } 
};