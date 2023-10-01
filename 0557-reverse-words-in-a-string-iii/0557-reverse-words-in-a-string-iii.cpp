class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int start = 0, end = 0;
        while(end < n) {
            while(end < n && s[end] == ' ') end++;
            start = end;
            while(end < n && s[end] != ' ') end++;
            reverse(s.begin()+start, s.begin()+end);
        }
        return s;
    }
};