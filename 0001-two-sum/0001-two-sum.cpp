class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mpp;
        vector<int> ans = {2, -1};

        for(int i=0; i<nums.size(); i++) {
            int b = target-nums[i];
            if(mpp.find(b) != mpp.end()) {
                ans[0] = mpp[target-nums[i]];
                ans[1] = i;
            }

            mpp[nums[i]] = i;
        }

        return ans;
    }
};