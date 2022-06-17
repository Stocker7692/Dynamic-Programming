#include<bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>>&triangle,vector<vector<int>>&dp,int i,int j){
    if(dp[i][j]!=-1) return dp[i][j];
    
    // at last row minimum value will be value itself
    if(i==triangle.size()-1) return triangle[i][j]; 

    // value going down
    int down = triangle[i][j]+solve(triangle,dp,i+1,j);
    
    // value going diagonally
    int diagonal = triangle[i][j]+solve(triangle,dp,i+1,j+1);

    return dp[i][j]=min(down,diagonal);
}

int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    vector<vector<int>>dp(n,vector<int>(n,-1));
    return solve(triangle,dp,0,0);

}
