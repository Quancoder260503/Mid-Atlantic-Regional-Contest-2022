#include <bits/stdc++.h>
#include <iostream>
#include<queue>
#include<vector>
#include<utility>
using namespace std;
typedef long long ll;
const int sz=1001;
ll dp[sz][sz];
vector<array<int,2>>a;
int n;
std::string s;
int main(){
      cin>>n;
      for(int i=1;i<=n;i++){
          int u,v;cin>>u>>v;
          a.push_back({v,u});
      }
      int ans=0;
      int cur=0;
      sort(a.begin(),a.end());
      for(int i=0;i<n;i++){
          ans+=max(0,a[i][1]-cur);
          cur=max(cur,a[i][1])+1;
      }
      ans--;
      cout<<ans<<endl;
}   
