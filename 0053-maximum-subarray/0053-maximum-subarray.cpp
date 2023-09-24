class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN, curSum = 0;
        for(int i = 0; i < nums.size(); i++) {
            curSum += nums[i];
            maxi = max(maxi, curSum);
            if(curSum < 0) curSum = 0;
        }
        return maxi;
    }
};