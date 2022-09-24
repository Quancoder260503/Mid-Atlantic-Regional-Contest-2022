#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
typedef long long ll;
typedef long double ld;
const int sz=2e5+1;
int n,q,m,cnt2,cnt1,cnt0,l,r,ans;
int d[sz];
bool use[sz];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
bool p[sz];
string num;
int a[4][sz];
int main(){   
    cin>>n>>m;
    int tank=m;
    for(int i=1;i<=n;i++){
         string ord; cin>>ord;
         if(ord.length()>=2){
             if(tank>=1+(ord[0]-'0')) tank-=(ord[0]-'0')+1;
             else{
                
                 tank=m-(ord[0]-'0'+1); 
                 ans++;
             }
         }
         else{
             if(tank>=(ord[0]-'0')) tank-=(ord[0]-'0');
             else {
                 tank=m-(ord[0]-'0');
                 ans++;
             }
         }
    }
    cout<<ans<<endl;
} 
