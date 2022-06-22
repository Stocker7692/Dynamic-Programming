#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool solve(vector<int>&nums,int i,int target,vector<vector<int>>&dp){
        
        if(target==0) return true;
        if(i==0){
            return nums[0]==target;
        }
        if(dp[i][target]!=-1) return dp[i][target];
        bool notTake = solve(nums,i-1,target,dp);
        bool take=false;
        if(nums[i]<=target){
            take = solve(nums,i-1,target-nums[i],dp);
        }
        return dp[i][target]=take||notTake;
    }

    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n = nums.size();
        for(int i=0;i<n;i++) sum+=nums[i];
        if(sum%2==1) return false;
        sum=sum/2;
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return solve(nums,n-1,sum,dp);        
    }
};