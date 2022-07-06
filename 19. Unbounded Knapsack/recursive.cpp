// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int ind,int W,int val[],int wt[]){
        if(ind==0){
            return ((W/wt[0]))*val[0];
        }
        
        int notTake = 0+solve(ind-1,W,val,wt);
        int take = INT_MIN;
        if(wt[ind]<=W){
            take = val[ind]+solve(ind,W-wt[ind],val,wt);
        }
        return max(take,notTake);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        return solve(N-1,W,val,wt);
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