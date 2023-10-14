class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int curSum = 0, maxi = INT_MIN;
        // Loop through array
        for(int i = 0; i < n; i++) {
            // Update curSum
            curSum += nums[i];
            // Update maxi
            maxi = max(maxi, curSum);
            // Updae curSum = 0, if curSum is -ve
            if(curSum < 0) curSum = 0;
        }
        return maxi;
    }
};