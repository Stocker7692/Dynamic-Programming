#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int dp[201][201];
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    dp[i][j]=grid[i][j];
                    
                }
                else{
                    long long int up=grid[i][j]%1000000007;
                    long long int left=grid[i][j]%1000000007;
                    if(i>0) up +=dp[i-1][j]%1000000007;
                    else up=INT_MAX;
                    if(j>0) left +=dp[i][j-1]%1000000007;
                    else left=INT_MAX;
                    dp[i][j]=min(up,left);
                }
                
            }
        }
        return dp[m-1][n-1];
        
    }
};