//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    
    
    int solve(int ind,int sum,vector<int>arr,vector<vector<int>>&dp){
        if(ind==arr.size()){
            if(sum==0){
              return 1;;
                
            }
            else return 0;
        }
        if(dp[ind][sum]!=-1) return dp[ind][sum];
        return solve(ind+1,sum-arr[ind],arr,dp) || solve(ind+1,sum,arr,dp);
        
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n=arr.size();
        vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
        if(solve(0,sum,arr,dp)) return 1;
        return 0;
    
        
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