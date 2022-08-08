#include<bits/stdc++.h>
using namespace std;

string shortestSupersequence(string a, string b)
{
	// Write your code here.
    int n = a.size();
    int m = b.size();
    
    int dp[n+1][m+1];
    memset(dp,0,sizeof(dp));
    
    for(int i=0;i<=n;i++) dp[i][0]=0;
    for(int i=0;i<=m;i++) dp[0][i]=0;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    
    int len = dp[n][m];
    int i=n,j=m;
    int index=len-1;
    string ans="";
    
    while(i>0 && j>0){
        if(a[i-1]==b[j-1]){
            ans += a[i-1];
            index--;
            i--;
            j--;
        }
        else if(dp[i-1][j]>dp[i][j-1]){
            ans+=a[i-1];
            i--;
        }
        else{
            ans+=b[j-1];
            j--;
        }
    }
    
    while(i>0) {
        ans += a[i-1];
        i--;
    }
    
    while(j>0){
        ans+=b[j-1];
        j--;
    }
    
    reverse(ans.begin(),ans.end());
    
    return ans;
}