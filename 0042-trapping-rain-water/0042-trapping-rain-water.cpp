class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int lmax = 0, rmax = 0;
        int l = 0, r = n-1;
        int ans = 0;
        
        while(l < r) {
            lmax = max(height[l], lmax);
            rmax = max(height[r], rmax);

            if(lmax > rmax) {
                ans += rmax - height[r];
                r--;
            }else {
                ans += lmax - height[l];
                l++;
            }
        }

        return ans;
    }
};