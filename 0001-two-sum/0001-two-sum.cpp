class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int n = nums.size();

        // Storing value and it's index
        map<int, int> mpp;

        // Looping through the array and checking if target-nums[i] present in map
        for(int i = 0; i < n; i++) {
            if(mpp.find(target-nums[i]) != mpp.end()) {
                ans.push_back(i);
                ans.push_back(mpp[target-nums[i]]);
            } else {
                mpp[nums[i]] = i; // Storing the index
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};