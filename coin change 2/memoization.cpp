#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int i,int target,vector<int>&coins,vector<vector<int>>&dp){
        if(i==0){
            return (target%coins[0]==0);
        }
        if(dp[i][target]!=-1) return dp[i][target];
        int notTake = solve(i-1,target,coins,dp);
        int take =0;
        if(coins[i]<=target){
            take=solve(i,target-coins[i],coins,dp);
        }
        return dp[i][target]=notTake+take;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        return solve(coins.size()-1,amount,coins,dp);
        
    }
};