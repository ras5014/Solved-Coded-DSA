//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:

    int smallestSubWithSum(int arr[], int n, int x)
    {
        // Your code goes here 
        int wstart = 0, subSum = 0, mini = INT_MAX;
        for(int i = 0; i < n; i++) {
            subSum += arr[i];
            while(subSum > x) {
                mini = min(mini, i-wstart+1);
                subSum -= arr[wstart++];
            }
        }
        int ans = (mini == INT_MAX) ? 0 : mini;
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution obj;
		cout<<obj.smallestSubWithSum(a,n,x)<<endl;
	}
	return 0;
}
// } Driver Code Ends