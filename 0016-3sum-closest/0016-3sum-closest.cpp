class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int md = abs(nums[0]+nums[1]+nums[2]-target), current;

        if(nums.size() == 3) {
            return nums[0]+nums[1]+nums[2];
        }

        for(int i=0; i<nums.size()-2; i++) {
            if(i>0 && nums[i]==nums[i-1]) continue;

            int j = i+1, k = nums.size()-1;

            while(j < k) {
                int sum = nums[i]+nums[j]+nums[k];

                if(sum == target) {
                    return target;
                }else if(abs(target-sum) < md) {
                    md = abs(target-sum);
                    current = sum;
                }
                if(sum>target) {
                    k--;
                }else {
                    j++;
                }
                
            }
        }

        return current;
    }
};