#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int uniquePathsWithObstacles(vector<vector<int>>& obs) {
        int m = obs.size();
        int n = obs[0].size();
        int dp[101][101];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i>=0 && j>=0 && obs[i][j]==1){
                    dp[i][j]=0;
                    continue;
                    
                } 
                else if(i==0 && j==0) {
                    dp[i][j]=1;
                    continue;
                }
                else{
                    int up=0;
                int left=0;
                
                if(i>0) up = dp[i-1][j];
                if(j>0) left = dp[i][j-1];
                dp[i][j]=up+left;
                    
                }
                
                
            }
        }
        return dp[m-1][n-1];
        
    }
};