class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans;
        int first = 0, last = n-1;

        while(first < last) {
            int sum = nums[first] + nums[last];

            if(sum == target) {
                ans.push_back(first+1);
                ans.push_back(last+1);
                break;
            }else if(sum > target) {
                last--;
            }else {
                first++;
            }
        }

        return ans;
    }
};