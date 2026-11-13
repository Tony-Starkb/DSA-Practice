class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string prefix = strs[0];

        for(int i=1; i<n; i++) {
            string compWith = strs[i];
            int j = 0;
            int size = min(prefix.size(), compWith.size());

            while(prefix[j] == compWith[j] && j < size) {
                j++;
            }

            prefix = prefix.substr(0, j);
        }

        return prefix;
    }
};



// || prefix[j] > size || compWith[j] > size