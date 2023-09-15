//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  private:
    int helper(int arr[], int start, int end, int k) {
        if(start > end) return -1;
        int mid = start + (end-start)/2;
        if(k == arr[mid]) return mid;
        else if(k > arr[mid]) return helper(arr, mid+1, end, k);
        else return helper(arr, start, mid-1, k);
    }
  public:
    int binarysearch(int arr[], int n, int k) {
        // code here
        return helper(arr, 0, n-1, k);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];
        int key;
        cin >> key;
        Solution ob;
        int found = ob.binarysearch(arr, N, key);
        cout << found << endl;
    }
}

// } Driver Code Ends