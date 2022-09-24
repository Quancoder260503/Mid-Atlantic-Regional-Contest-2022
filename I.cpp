#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
typedef long long ll;
typedef long double ld;
const int sz=2e5+1;
string t,s;
int n,m;
int d[sz];
bool use[sz];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
string a[51];
ll dp[50][sz];
ll ans=0;
ll mod=1e9+7;
map<string,int>mp;
int main(){   
      cin>>s>>t;
      a[0]=t;
      mp[t]=1;
      int cnt=0;
      for(int i=1;i<t.length();i++){
          string rt="";
          for(int j=i;j<i+t.length();j++){
              rt=rt+t[(j%t.length())];
          }
          if(mp[rt]>0) continue;
          a[++cnt]=rt;
          mp[rt]=1;
      }
      //cout<<cnt<<endl;
      for(int k=0;k<=cnt;k++){
          for(int i=0;i<a[k].length();i++){
              for(int j=i;j<s.length();j++){
                  if(i==0 and j==0 and a[k][0]==s[0]) dp[0][0]=1;
                  if(i==0 and j>0){
                     if(a[k][i]==s[j]) dp[i][j]=(dp[i][j-1]+1)%mod;
                     else dp[i][j]=dp[i][j-1];
                  }
                  if(i>0 and j>0){
                      if(a[k][i]==s[j]) dp[i][j]=(dp[i][j-1]+dp[i-1][j-1])%mod;
                      else dp[i][j]=dp[i][j-1];
                  }
              }
          }
          ans= (ans+(ll) dp[t.length()-1][s.length()-1])%mod;
          for(int i=0;i<t.length();i++){
              for(int j=0;j<s.length();j++){
                      dp[i][j]=0;
              }
          }
     }
     cout<<ans<<endl;
} 
