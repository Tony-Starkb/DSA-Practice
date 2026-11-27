
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> hash(256, 0);
        int left = 0, right = 0;
        int minLen = INT_MAX, sIdx = -1, cnt = 0;

        for(int i = 0; i < t.size(); i++) {
            hash[t[i]]++;
        }

        while(right < s.size()) {

            if(hash[s[right]] > 0) {
                cnt++;
            }

            hash[s[right]]--;

            while(cnt == t.size()) {

                if(right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    sIdx = left;
                }

                hash[s[left]]++;

                if(hash[s[left]] > 0) {
                    cnt--;
                }

                left++;
            }

            right++;
        }

        return sIdx == -1 ? "" : s.substr(sIdx, minLen);
    }
};
