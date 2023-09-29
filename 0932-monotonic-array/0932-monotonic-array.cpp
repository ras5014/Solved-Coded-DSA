class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        bool increasing = true, decreasing = true;
        for(int i = 0; i < n-1; i++) {
            if(increasing && nums[i] > nums[i+1]) increasing = false;
            if(decreasing && nums[i] < nums[i+1]) decreasing = false;
        }
        if(increasing || decreasing) return true;
        else return false;
    }
};