class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        set<int> s;
        sort(nums2.begin(), nums2.end());

        for(int i=0; i<nums1.size(); i++) {
            int low = 0, high = nums2.size()-1;
            while(low <= high) {
                int mid = low + (high - low) / 2;
                if(nums2[mid] == nums1[i]) {
                    s.insert(nums1[i]);
                    break;
                }else if(nums2[mid]>nums1[i]) {
                    high = mid-1;
                }else {
                    low = mid+1;
                }
            }
        }

        for(auto it: s) {
            ans.push_back(it);
        }

        return ans;
    }
};