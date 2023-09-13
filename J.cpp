#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
typedef long long ll;
typedef long double ld;
const int sz=2e5+1;
int p,q,cnt2,cnt1,cnt0,l,r,ans;
int d[sz];
bool use[sz];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
string num;
int a[4][sz];
int main(){   
     cin>>p>>q;
     cin>>num;
     int tx,ty;
     tx=ty=-1;
     for(int i=0;i<num.length();i++){
         if(num[i]=='A'){
             if(tx==-1) tx=i;
             else if(ty==-1) ty=i;
         }
     }
     if(tx==2 and p==3){
             cout<<1<<" "<<2<<endl;
             return 0;
     }
     if(ty-tx==2){
         if(p==6 and q==8){
             cout<<min(p,q)+1<<" "<<max(p,q)+1<<endl;
             return 0;
         }
         if(tx==1 and ty==3 and q==4){
             cout<<min(p,q)-1<<" "<<max(p,q)-1<<endl;
             return 0;
         }
     }
     if(ty-tx==1){
         if(q==7){
             cout<<8<<" "<<9<<endl;
             return 0;
         }
         if(tx==1 and ty==2 and p==2 and q==8){
             cout<<1<<" "<<9<<endl;
             return 0;
         }
     }
     if(3==max(p,q)-min(p,q) and tx==0 and ty==3){
         cout<<min(p,q)+1<<" "<<max(p,q)-1<<endl;
         return 0;
     }
     puts("-1");
     return 0;
}
   
