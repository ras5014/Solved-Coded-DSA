//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
        // code here
        // Basic Structue
        int wstart = 0;
        long subSum = 0, maxi = LONG_MIN;
        // Looping Starts
        for(int i = 0; i < N; i++) {
            subSum += Arr[i];
            if(i >= K-1) {
                maxi = max(subSum, maxi);
                subSum -= Arr[wstart++];
            }
        }
        return maxi;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends