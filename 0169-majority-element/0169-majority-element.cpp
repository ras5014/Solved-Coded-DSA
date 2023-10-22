class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();

        // Moore's Voting Algorithm
        // Step-1 Take element & count
        int el, cnt = 0;

        // Step-2 check with this [2, 2, 1, 1, 1, 2, 2]
        for(int i = 0; i < n; i++) {

            // If count is 0 or becomes 0
            if(cnt == 0) {
                el = nums[i];
                cnt++;
            } else if (nums[i] == el) cnt++; // If element == nums[i]
            else cnt--; // If not equal
        }

        // Here we don't have to check cause majority element always exists
        // Or else we would have to check if element appears more than n/2 times
        return el;
    }
};