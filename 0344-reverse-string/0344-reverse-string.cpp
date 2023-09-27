class Solution {
private:
    void helper(vector<char> &s, int start, int end) {
        if(start > end) return;
        swap(s[start++], s[end--]);
        helper(s, start, end);
    }
public:
    void reverseString(vector<char>& s) {
        helper(s, 0, s.size()-1);
    }
};