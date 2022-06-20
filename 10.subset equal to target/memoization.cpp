//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:

    bool solve(vector<int>&arr,int sum,int i,vector<vector<int>>&dp){
        if(sum==0) return true;
        if(i==0) return arr[0]==sum;
        if(dp[i][sum]!=-1) return dp[i][sum];
        bool notTake = solve(arr,sum,i-1,dp);
        bool take=false;
        if(sum>=arr[i]){
            take = solve(arr,sum-arr[i],i-1,dp);
        }
        return dp[i][sum]=take||notTake;
    }
    bool isSubsetSum(vector<int>arr, int k){
        
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int>(k+1,-1));
        return solve(arr,k,arr.size()-1,dp);
        
    
    // return subsetSumUtil(n-1,k,arr,dp);
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends