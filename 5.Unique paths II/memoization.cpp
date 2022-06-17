#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[102][102];
    int solve(vector<vector<int>>&mat,int i,int j,int &ans){
        if(i==mat.size()-1 && j==mat[0].size()-1 ){
            return 1;
        }
        if(i<0 || j<0 || i>=mat.size() || j>=mat[0].size() || mat[i][j]==1) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int l = solve(mat,i+1,j,ans);
        int m = solve(mat,i,j+1,ans);
        return dp[i][j]=l+m;
        
        
    }
    int uniquePathsWithObstacles(vector<vector<int>>& mat) {
        if(mat[mat.size()-1][mat[0].size()-1]==1 || mat[0][0]==1) return 0;
        int ans=0;
        memset(dp,-1,sizeof(dp));
        return solve(mat,0,0,ans);
        // return dp[mat.size()][mat[0].size()];
        
    }
};