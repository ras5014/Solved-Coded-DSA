class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int break_point = -1;
        // Finding Breaking Point
        for(int i = n-2; i >= 0; i--) {
            if(nums[i] < nums[i+1]) {
                break_point = i;
                break;
            }
        }
        // If No break point found (ex: 54321 -> return 12345)
        if(break_point == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        // if break point found -> find smallest greater than breaking point from right side and swap with a[i]
        for(int i = n-1; i > break_point; i--) {
            if(nums[i] > nums[break_point]) {
                swap(nums[i], nums[break_point]);
                break;
            }
        }
        // reverse from i+1 to n-1
        reverse(nums.begin()+break_point+1, nums.end());
    }
};