class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> leftSmaller(heights.size()), rightSmaller(heights.size());
        stack<int> index;

        for(int i=0; i<heights.size(); i++) {
            while(!index.empty() && heights[index.top()] >= heights[i]) {
                index.pop();
            }
            if(index.empty()) leftSmaller[i] = 0;
            else leftSmaller[i] = index.top()+1;
            index.push(i);
        }

        while(!index.empty()) index.pop();

        for(int i=heights.size()-1; i>=0; i--) {
            while(!index.empty() && heights[index.top()] >= heights[i]) {
                index.pop();
            }
            if(index.empty()) rightSmaller[i] = heights.size()-1;
            else rightSmaller[i] = index.top()-1;
            index.push(i);
        }

        int maxArea = 0;
        for(int i=0; i<heights.size(); i++) {
            int area = (rightSmaller[i]-leftSmaller[i]+1) * heights[i];
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};