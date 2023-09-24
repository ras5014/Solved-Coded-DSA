class Solution {
private:
    int digitSquareSum(int num) {
        int sum = 0;
        while(num) {
            int digit = num % 10;
            sum += digit*digit;
            num = num / 10;
        }
        return sum;
    }
public:
    bool isHappy(int n) {
        int slow = n, fast = n;
        do {
            slow = digitSquareSum(slow);
            fast = digitSquareSum(digitSquareSum(fast));
        } while(fast != slow);
        if(slow == 1) return true;
        return false;
    }
};