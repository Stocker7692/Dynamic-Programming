#include<bits/stdc++.h>
using namespace std;


int solve(vector<int>&nums,int target,int i,vector<vector<int>>&dp){
        if(target==0) return 1;
        if(i==0){
            return nums[0]==target;
        }
        if(dp[i][target]!=-1) return dp[i][target];
        int np=solve(nums,target,i-1,dp);
        int p=0;
        if(nums[i]<=target){
            p=solve(nums,target-nums[i],i-1,dp);
        }
       return dp[i][target]=p+np;
    }

int findWays(vector<int> &nums, int sum)
{
    // Write your code here.
    int n = nums.size();
    vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return solve(nums,sum,n-1,dp);
}