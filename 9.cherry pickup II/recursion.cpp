#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<vector<int>>& grid,int i,int j1,int j2,int n,int m){
        if(j1<0 || j1>=m || j2<0 || j2>=m) return -1e9;
        if(i==n-1) {
            if(j1==j2) return grid[i][j1];
            else return grid[i][j1]+grid[i][j2];
        }
        int maxi = INT_MIN;
        for(int x=-1;x<=1;x++){
            for(int y=-1;y<=1;y++){
                int ans;
                if(j1==j2) ans = grid[i][j1]+solve(grid,i+1,j1+x,j2+y,n,m);
                else ans = grid[i][j1]+grid[i][j2]+solve(grid,i+1,j1+x,j2+y,n,m);
                maxi=max(ans,maxi);
            }
        }
        return maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m=grid[0].size();
        return solve(grid,0,0,m-1,n,m);
        
    }
};