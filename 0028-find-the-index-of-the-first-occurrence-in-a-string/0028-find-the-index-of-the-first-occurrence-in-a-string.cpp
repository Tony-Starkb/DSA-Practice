// we have to work with the contiguous string
// sliding window of fixed size

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = needle.size(), h = haystack.size();
        if(n > h) return -1;

        for (int start = 0; start <= haystack.size() - needle.size(); start++) {

        int j = 0;

            while (j < needle.size() &&
                haystack[start + j] == needle[j]) {
                j++;
            }

            if (j == needle.size()) {
                return start;
            }
        }

        return -1;
    }
};