#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int>prev(n,0);
        for(int i=0;i<m;i++){
            vector<int>temp(n,0);
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    temp[j]=grid[i][j];      
                }
                else{
                    long long int up=grid[i][j]%1000000007;
                    long long int left=grid[i][j]%1000000007;
                    if(i>0) up +=prev[j]%1000000007;
                    else up=INT_MAX;
                    if(j>0) left +=temp[j-1]%1000000007;
                    else left=INT_MAX;
                    temp[j]=min(up,left);
                }  
            }
            prev=temp;
        }
        return prev[n-1];
        
    }
};