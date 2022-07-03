#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int solve(int i,int target,vector<int>&coins){
        if(i==0){
            return (target%coins[0]==0);
        }
        int notTake = solve(i-1,target,coins);
        int take =0;
        if(coins[i]<=target){
            take=solve(i,target-coins[i],coins);
        }
        return notTake+take;
    }
    int change(int amount, vector<int>& coins) {
        return solve(coins.size()-1,amount,coins);
        
    }
};