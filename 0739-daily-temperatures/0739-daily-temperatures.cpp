class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);
        stack<int> temp;
        
        for(int i=0; i<nums.size(); i++) {
            while(!temp.empty() && nums[temp.top()] < nums[i]) {
                ans[temp.top()] = i - temp.top();
                temp.pop();
            }

            temp.push(i);
        }

        return ans;
    }
};