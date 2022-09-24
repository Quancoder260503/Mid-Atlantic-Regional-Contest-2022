#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
typedef long long ll;
typedef long double ld;
const int sz1=5e6+1;
const int sz=2e5+1;
int n,q,m,cnt2,cnt1,cnt0;
int d[sz];
bool use[sz];
int a[65][65];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int main(){   
     cin>>n>>m;
     int tx,ty;
     for(int i=1;i<=n;i++){
         for(int j=1;j<=m;j++){
             cin>>a[i][j];
             if(a[i][j]==2) cnt2++;
             if(a[i][j]==1) cnt1++;
             if(a[i][j]==0) cnt0++;
             if(a[i][j]==0){
                 tx=i;ty=j;
             }
         }
    }
    if(cnt0>0){
       if(cnt0>1){
           cout<<0<<endl;
           return 0;
       }
       if(cnt0==1 and n<=1 or m<=1){
           if(a[1][1]==0){
               if(n==1) cout<<a[1][m]<<endl;
               else if(m==1) cout<<a[n][1]<<endl;
               return 0;
           }
           else{
               if(n==1) cout<<min(a[1][1],a[1][m]);
               else if(m==1) cout<<min(a[n][1],a[1][1]);
               return 0;
           }
       }
       if(cnt1>0){
           cout<<1<<endl;
           return 0;
       }
       else if(cnt1==0 and cnt2>0){
           cout<<2<<endl;
           return 0;
       }
    }
    else{
        if(cnt2>0){
          int div=cnt2/2;
          ll ans=0;
          if(cnt2%2==1){
              ans=(ll) (1<<div);
              if(ans<0) ans=-ans;
          }
          cout<<ans<<endl;
          return 0;
        }
        cout<<0<<endl;
    }
} 
