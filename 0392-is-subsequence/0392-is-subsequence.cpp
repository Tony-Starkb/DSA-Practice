class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size(), m = t.size();
        int pt1 = 0, pt2 = 0;
        int count = 0;

        while(pt1 < n && pt2 < m) {
            if(t[pt2] == s[pt1]) {
                pt1++;
                count++;
            }

            pt2++;
        }

        if(count == n) {
            return true;
        }

        return false;
    }
};