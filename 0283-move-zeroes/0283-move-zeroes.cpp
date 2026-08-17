class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int p = 0;
        for(int num: nums) {
            if(num != 0) {
                nums[p++] = num;
            }
        }

        while(p < nums.size()) {
            nums[p++] = 0;
        }
    }
};