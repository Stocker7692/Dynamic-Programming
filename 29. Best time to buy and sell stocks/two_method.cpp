#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        // TC--> O(N2)
            
        int ans=0;
        int n = prices.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                ans=max(ans,prices[j]-prices[i]);
            }
        }
        return ans;
        
        
        // TC--> O(N)
        
        int mini = INT_MAX;
        int profit = INT_MIN;
        for(int i=0;i<prices.size();i++){
            mini = min(mini,prices[i]);
            profit=max(profit,prices[i]-mini);
        }
        return profit;
    }
};