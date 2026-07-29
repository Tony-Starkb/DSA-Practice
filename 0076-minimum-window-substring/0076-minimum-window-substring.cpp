class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> need(128, 0);
        vector<int> window(128, 0);

        int to_find = 0;
        for(char c : t) {
            if(need[c] == 0)
                to_find++;
            need[c]++;
        }
        int found = 0, left = 0, ansleft = 0, anslen = INT_MAX;

        for(int right=0; right<s.size(); right++) {
            char c = s[right];
            window[c]++;

            if(need[c]>0 && window[c] == need[c]) {
                found++;
            }

            while(to_find == found) {
                if(right-left+1 < anslen) {
                    anslen = right-left+1;
                    ansleft = left;
                }

                char l = s[left];
                window[l]--;

                if(need[l]>0 && window[l] < need[l]) {
                    found--;
                }

                left++;
            }
        }

        if(anslen == INT_MAX) return "";
        return s.substr(ansleft, anslen);
    }
};