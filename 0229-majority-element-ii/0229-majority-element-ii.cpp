class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int, int> ump;

        // Storing count of each element in hash map
        for(int i = 0; i < n; i++)
            ump[nums[i]]++;
        
        // Checking if element count is more that floor(n/3) or not
        for(auto it : ump) {
            if(it.second > floor(n/3)) 
                ans.push_back(it.first);
        }
        return ans;
    }
};