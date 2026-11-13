class Solution {
public:
    string convert(string s, int numRows) {
        
        if(numRows == 1 || numRows > s.size()) {
            return s;
        }

        vector<string> ans(numRows);
        int currentRow = 0, direction = 1;

        for(char ch: s) {
            ans[currentRow] += ch;

            if(currentRow == 0 ) {
                direction = 1;
            }
            if(currentRow == numRows-1) {
                direction = -1;
            }

            currentRow += direction;
        }

        string ANS = "";
        for(auto it: ans) {
            ANS += it;
        }

        return ANS;

        
    }
};