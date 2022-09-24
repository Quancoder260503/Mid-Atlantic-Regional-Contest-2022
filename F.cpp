#include <bits/stdc++.h>
#include <iostream>
#include<queue>
#include<vector>
#include<utility>
using namespace std;
typedef long long ll;
const int sz=21;
int a[sz][sz];
ll dp[sz][sz];
int n;
std::string s;
int main(){
      cin>>s;
      n=s.length();
      for(int i=0;i<n;i++){
          for(int j=i+1;j<n;j++){
              if(s[i]=='?'){
                  if(s[j]==']' or s[j]==')' or s[j]=='}' or s[j]=='>') a[i][j]=1;
              }
              if(s[j]=='?'){
                   if(s[i]=='[' or s[i]=='(' or s[i]=='{'  or s[i]=='<') a[i][j]=1;
              }
              if(s[i]=='?' and s[j]=='?') a[i][j]=4;
              if(s[i]=='<' and s[j]=='>') a[i][j]=1;
              if(s[i]=='(' and s[j]==')') a[i][j]=1;
              if(s[i]=='{' and s[j]=='}') a[i][j]=1;
              if(s[i]=='[' and s[j]==']') a[i][j]=1;
          }
      }
      for(int i=1;i<=n;i++) dp[n][i]=1;
      for(int i=n-1;i>=0;i--){
          for(int j=i+1;j<n;j++){
              if(j==i+1) dp[i][j]=a[i][j];
              else{
                for(int k=i+1;k<=j;k++){
                     /// if(i==0 and j==n-1) cout<<i<<" "<<j<<" "<<k<<" "<<dp[i][j]<<endl;
                      if(k>=i+2 and k+1<j) dp[i][j]+=dp[i+1][k-1]*dp[k+1][j]*a[i][k];
                      else if(k==j) dp[i][j]+=dp[i+1][k-1]*a[i][k];
                      else if(k<i+2) dp[i][j]+=dp[i][k]*dp[k+1][j];
                  } 
              }
          }
      }
       cout<<dp[0][n-1]<<endl;
}    
