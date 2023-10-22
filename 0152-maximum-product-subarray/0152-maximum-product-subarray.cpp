class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();


        /*
        case-1: if all element +ve then ans = product of all elements
        case-2: if even no. of -ve then ans = product of all elements
        case-3: if odd no. of -ve nos then we need to take one negetive
                num. this splits the array into prefix and suffix. Now max
                of prefix & suffix is the result
        */

        int pre = 1, suf = 1;
        int ans = INT_MIN;

        // Here we are calculating all possible prefix and suffix and comparing
        for(int i = 0; i < n; i++) {
            if(pre == 0) pre = 1;
            if(suf == 0) suf = 1;

            pre *= nums[i];
            suf *= nums[n-1-i];

            ans = max(ans, max(pre, suf));
        }
        return ans;
    }
};