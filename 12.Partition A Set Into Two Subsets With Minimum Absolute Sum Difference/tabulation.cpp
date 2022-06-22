#include<bits/stdc++.h>
using namespace std;

int minSubsetSumDifference(vector<int>& nums, int n)
{
	int sum=0;
//         int n = nums.size();
        if(n==2) return abs(nums[0]-nums[1]);
        for(int i=0;i<n;i++) sum+=nums[i];
        vector<vector<bool>> dp(n,vector<bool>(abs(sum)+1,false));
        for(int i=0;i<n;i++) dp[i][0]=1;
        if(nums[0]<=sum) dp[0][nums[0]]=1;
        
        for(int i=1;i<n;i++){
            for(int j=1;j<=abs(sum);j++){
                bool notTake = dp[i-1][j];
                bool take=false;
                if(j>=nums[i]){
                    take=dp[i-1][j-nums[i]];
                }
                dp[i][j]=take||notTake;
            }
        }
        int res = 1e9;
        for(int i=0;i<sum+1;i++){
            if(dp[n-1][i]==true){
                int s1=i;
                int s2=sum-i;
                res=min(res,abs(s1-s2));
            }
        }
//        if(res==INT_MAX)return 0;
        return res;
}