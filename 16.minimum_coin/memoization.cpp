#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int solve(int coins[],int V,int ind,vector<vector<int>>&dp){
	    if(ind==0){
	        if(V%coins[ind]==0) return V/coins[ind];
	        return 1e9;
	    }
	    if(dp[ind][V]!=-1) return dp[ind][V];
	    int notTake = 0 + solve(coins,V,ind-1,dp);
	    int take = 1e9;
	    if(V>=coins[ind]){
	        take = 1+solve(coins,V-coins[ind],ind,dp);
	    }
	    
	    return dp[ind][V]=min(take,notTake);
	}
	int minCoins(int coins[], int M, int V) 
	{ 
	    // Your code goes here
	    vector<vector<int>>dp(M,vector<int>(V+1,-1));
	    int ans= solve(coins,V,M-1,dp);
	    if(ans>=1e9) return -1;
	    return ans;
	} 
	  
};

// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends