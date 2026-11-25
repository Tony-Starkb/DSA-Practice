class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int first = 0, last = n-1;
        int maxWater = 0;

        while(first < last) {

            int water = min(height[first], height[last]) * (last-first);
            maxWater = max(maxWater, water);

            if(height[first] < height[last]) {
                first++;
            }else {
                last--;
            }
        }

        return maxWater;
    }
};