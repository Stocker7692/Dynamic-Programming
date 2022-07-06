// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    int knapSack(int N, int W, int val[], int wt[])
    {
        
        vector<vector<int>>dp(N+1,vector<int>(W+1,0));
        
        for(int i=wt[0]; i<=W; i++){
        dp[0][i] = ((int) i/wt[0]) * val[0];
    }
        
        for(int i=1;i<N;i++){
            for(int w=0;w<=W;w++){
                int notTake = dp[i-1][w];
                int take=0;
                if(wt[i]<=w){
                    take = val[i]+dp[i][w-wt[i]];
                }
                dp[i][w]=max(take,notTake);
            }
        }
        return dp[N-1][W];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}  // } Driver Code Ends