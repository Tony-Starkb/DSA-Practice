class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);

        // prefix
        int prefix = 1;
        for(int i=1; i<n; i++) {
            //cout << "prefix: " << prefix << endl;
            prefix *= nums[i-1];
            ans[i] *= prefix;
        }

        // suffix
        int suffix = 1;
        for(int i=n-2; i>=0; i--) {
            //cout << "suffix: " << suffix << endl;
            suffix *= nums[i+1];
            ans[i] *= suffix;
        }

        return ans;
    }
};