class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int n = nums.size();
        int maxi = INT_MIN, curSum = 0;

        // Looping through the array & adding elements to curSum
        for(int i = 0; i < n; i++) {

            // Keep adding element nums[i] to curSum
            curSum += nums[i];

            // update maxi
            maxi = max(maxi, curSum);

            // If curSum is less than 0, then we can't find max with it
            if(curSum < 0) curSum = 0;
        }

        return maxi;
    }
};