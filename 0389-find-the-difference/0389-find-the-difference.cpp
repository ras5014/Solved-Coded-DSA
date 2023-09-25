class Solution {
public:
    char findTheDifference(string s, string t) {
        char ans;
        unordered_map<char, int> ump;
        for(int i = 0; i < s.size(); i++) ump[s[i]]++;
        for(int i = 0; i < t.size(); i++) {
            if(ump[t[i]] == 0) {
                ans = t[i];
                break;
            }
            ump[t[i]]--;
        }
        return ans;
    }
};