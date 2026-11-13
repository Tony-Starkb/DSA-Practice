class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        // Fix the first string as the reference string
        string referenceStr = strs[0];

        // Compare this reference string with the other strings one by one
        for (int i = 1; i < strs.size(); i++) {
            int j = 0;
            
            // Find characters that match in both strings
            while (j < referenceStr.length() && j < strs[i].length() && referenceStr[j] == strs[i][j]) {
                j++;
            }

            // Update the reference string with the common part
            referenceStr = referenceStr.substr(0, j);

            // If there is nothing in common, return an empty string
            if (referenceStr.empty()) {
                return "";
            }
        }

        // In the end, return the reference string
        return referenceStr;
    }
};