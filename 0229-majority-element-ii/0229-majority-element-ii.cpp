class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();

        // Before doing this do the majority element for n/2

        /* In an "n" size array there can be maximum 2 elements 
        which appear more than n/3 times */

        // Moore's Voting Algorithm
        // Step-1 Taking two elements and their counts
        int el1, el2, cnt1 = 0, cnt2 = 0;

        // Step-2
        for(int i = 0; i < n; i++) {

            /* If cnt1 is 0 and the current element is not el2 then store the current element 
            of the array as el1 along with increasing the cnt1 value by 1.*/
            if(cnt1 == 0 && nums[i] != el2)
            {
                el1 = nums[i];
                cnt1 = 1;
            } 

            /*If cnt2 is 0 and the current element is not el1 then store the current element 
            of the array as el2 along with increasing the cnt2 value by 1.*/
            else if (cnt2 == 0 && nums[i] != el1) 
            {
                el2 = nums[i];
                cnt2 = 1;
            }

            // if current element is el1 -> cnt1++
            else if (nums[i] == el1) cnt1++;
            // if current element is l2 -> cnt2++
            else if (nums[i] == el2) cnt2++;
            // Or else decrease cnt1 & cnt2
            else 
            {
                cnt1--;
                cnt2--;
            }
        }

        // Since It's not given if majority element always exists or not so we have to check
        /* The integers present in el1 & el2 should be the result we are expecting. 
        So, using another loop, we will manually check their counts if they are greater than the floor(N/3) */

        cnt1 = 0; 
        cnt2 = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == el1) cnt1++;
            else if(nums[i] == el2) cnt2++;
        }
        if(cnt1 > floor(n/3)) ans.push_back(el1);
        if(cnt2 > floor(n/3)) ans.push_back(el2);
        return ans;
    }
};