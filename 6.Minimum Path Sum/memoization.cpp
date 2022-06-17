#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[201][201];
    int solve(int i,int j,vector<vector<int>>&grid){
        if(i==0 && j==0){
            return grid[i][j];
        }
        if(i<0 || j<0) return INT_MAX;
        if(dp[i][j]!=-1) return dp[i][j];
        long long int up = (grid[i][j])%1000000007+solve(i-1,j,grid)%1000000007;
        long long int left = grid[i][j]%1000000007+solve(i,j-1,grid)%1000000007;
        return dp[i][j]=min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        return solve(grid.size()-1,grid[0].size()-1,grid);
        
    }
};