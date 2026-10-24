class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> temp(n+1, 0);

        for(int i=0; i<n; i++) {
            if(citations[i] > n) {
                temp[temp.size()-1]++;
            }else {
                temp[citations[i]]++;
            }
        }

        int count = 0, ans = 0;
        for(int i=temp.size()-1; i>=0; i--) {
            count += temp[i];
            if(count >= i) {
                ans = max(i, ans);
            }
        }

        return ans;
    }
};