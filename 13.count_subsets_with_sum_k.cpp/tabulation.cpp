#include<bits/stdc++.h>
using namespace std;

int findWays(vector<int> &nums, int target)
{
    int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(target+1,0));
        for(int i=0;i<n;i++){
            dp[i][0]=1;
        }
        if(nums[0]<=target) dp[0][nums[0]]=1;
        
        for(int i=1;i<n;i++){
            for(int j=1;j<=target;j++){
                int notTake=dp[i-1][j];
                int take=0;
                if(nums[i]<=j){
                    take=dp[i-1][j-nums[i]];
                }
                dp[i][j]=take+notTake;
            }
        }
        return dp[n-1][target];
  
}