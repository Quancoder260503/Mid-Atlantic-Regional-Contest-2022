#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
typedef long long ll;
typedef long double ld;
const int sz=2e6+1;
int n,q,m,cnt2,cnt1,cnt0,l,r,ans;
int d[sz];
bool use[sz];
int a[sz];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
bool p[sz];
string num;
int main(){   
     cin>>l>>r;
     cin>>num;
     n=1300000;
     int cnt=0;
     memset(p,true,sizeof(p));
     for(int i=2;i<=n;i++){
         if(!p[i]) continue;
         a[++cnt]=i;
         for(ll j=(ll) i*i;j<=n;j+=i) p[j]=false;   
     }
     for(int i=l;i<=r;i++){
          if(a[i]<stoi(num)) continue;
          string pstr=to_string(a[i]);
          int itr=0;
          while(itr<pstr.length()){
              bool valid=true;
              if(itr+num.length()>pstr.length()) break;
              for(int j=0;j<num.length();j++){
                  if(num[j]!=pstr[itr+j]) valid=false;
              }
              if(valid){
                 // cout<<a[i]<<" "<<num<<" "<<i<<endl;
                  ans++;
                  break;
              }
              itr++;
          }
     }
     cout<<ans<<endl;
} 
