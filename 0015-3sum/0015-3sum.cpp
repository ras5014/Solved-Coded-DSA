class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();

        // Sort the array
        sort(nums.begin(), nums.end());


        // Finding Pairs for each array element
        for(int i = 0; i < n; i++) {

            // Skipping if we have already found pairs for an element [-1, -1, 2, 4]
            if(i > 0 && nums[i] == nums[i-1]) continue;

            // Two Sum Algorithm
            int s = i+1, e = n-1, target = 0 - nums[i];
            
            while(s < e) {
                if(nums[s] + nums[e] < target) {
                    s++;
                } else if (nums[s] + nums[e] > target) {
                    e--;
                } else {
                    vector<int> temp = {nums[i], nums[s], nums[e]};
                    ans.push_back(temp);
                    
                    s++;
                    e--;
                    // We dont want same triplets so move s++ untill element are same, same for e--
                    while((s < e) && (nums[s] == nums[s-1])) s++;
                    while((s < e) && (nums[e] == nums[e+1])) e--;
                }
            }
        }
        return ans;
    }
};