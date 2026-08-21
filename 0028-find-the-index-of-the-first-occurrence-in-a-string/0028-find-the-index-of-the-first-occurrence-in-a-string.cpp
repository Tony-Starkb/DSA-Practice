// we have to work with the contiguous string
// sliding window of fixed size

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = needle.size(), h = haystack.size();
        if(n > h) return -1;

        for (int start = 0; start <= h - n; start++) {

        int j = 0;

            while (j < n && haystack[start + j] == needle[j]) {
                j++;
            }

            if (j == n) {
                return start;
            }
        }

        return -1;
    }
};