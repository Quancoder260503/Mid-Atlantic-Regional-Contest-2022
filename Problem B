#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
typedef long long ll;
typedef long double ld;
const int sz=2e5+1;
int q,m,cnt2,cnt1,cnt0,l,r,ans;
int d[sz];
bool use[sz];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
bool p[sz];
string num;
int a[4][sz];
int main(){   
     cin>>num;
     for(int i=0;i<num.length();i++){
         int j=num[i]-'0';
         int cnt=0;
         while(j){
             a[cnt++][i]=j%2;
             j/=2;
         }
     }
     for(int i=3;i>=0;i--){
         for(int j=0;j<num.length();j++){
             if(a[i][j]) cout<<"*"<<" ";
             else cout<<"."<<" ";
             if(j==1){
                 cout<<"  ";
             }
         }
         cout<<endl;
     }
} 
