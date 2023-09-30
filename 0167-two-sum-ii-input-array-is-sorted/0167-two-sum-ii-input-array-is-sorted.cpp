class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        vector<int> ans;

        // Basic Two Pointer Approach from start ans end of the array
        int s = 0, e = n-1;
        while(s < e) {
            if(numbers[s] + numbers[e] == target) {
                ans.push_back(s+1); // Since index starts from 1
                ans.push_back(e+1);
                break;
            } else if(numbers[s] + numbers[e] < target) s++;
            else e--;
        }
        return ans;
    }
};