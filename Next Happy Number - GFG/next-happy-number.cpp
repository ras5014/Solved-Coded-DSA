//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int digitSquareSum(int num) {
        int sum = 0;
        while(num) {
            int digit = num % 10;
            sum += digit*digit;
            num = num / 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow = n, fast = n;
        do {
            slow = digitSquareSum(slow);
            fast = digitSquareSum(digitSquareSum(fast));
        } while(fast != slow);
        if(slow == 1) return true;
        return false;
    }
    int nextHappy(int N){
        // code here
        N++;
        while(true) {
            if(isHappy(N)) return N;
            N++;
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.nextHappy(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends