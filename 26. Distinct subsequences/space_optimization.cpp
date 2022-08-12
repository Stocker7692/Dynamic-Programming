#include <bits/stdc++.h>

using namespace std;

int prime = 1e9+7;


int subsequenceCounting(string &s1, string &s2, int n, int m) {
    // Write your code here.
    
    vector<int> prev(m+1,0);
    
    prev[0]=1;
    
    for(int i=1;i<n+1;i++){
        for(int j=m;j>=1;j--){ // Reverse direction
            
            if(s1[i-1]==s2[j-1])
                prev[j] = (prev[j-1] + prev[j])%prime;
            else
                prev[j] = prev[j]; //can omit this statemwnt
        }
    }
    
    
    return prev[m];
} 

int main() {

  string s1 = "babgbag";
  string s2 = "bag";

  cout << "The Count of Distinct Subsequences is "<<
  subsequenceCounting(s1,s2,s1.size(),s2.size());
}