#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    bool isAllStars(string &s1,int i){
        while(i>=0){
            if(s1[i]!='*') return false;
            i--;
        }
        return true;
    }
    
    bool solve(int i,int j,string &s,string &p,vector<vector<int>>&dp){
        
        if(i<0 && j<0) return true;
        if(i<0 && j>=0) return false;
        if(j<0 && i>=0) return isAllStars(s,i);
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==p[j] || s[i]=='?') return dp[i][j]=solve(i-1,j-1,s,p,dp);
       
        if(s[i]=='*') return dp[i][j]=solve(i-1,j,s,p,dp)|| solve(i,j-1,s,p,dp);
       return false;
      
        
        
    }

    bool isMatch(string s, string p) {
        int n = p.size();
        int m = s.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(n-1,m-1,p,s,dp);
    }
};