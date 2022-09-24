#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
typedef long long ll;
typedef long double ld;
const int sz=2e5+1;
const ld inf=1e7+1;
string t,s;
int n,m;
char  a[54][54];
ld dp[sz];
int d[sz];
bool use[sz];
vector<pair<int,ld>>adj[sz];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int par[sz];
ld dis[sz];
void joint_edge(int i,int j){
    int ya=(i-1)/(m+1); int yb=(j-1)/(m+1);
    int xa=i%(m+1); int xb=j%(m+1);
    if(xa==0) xa=m+1;
    if(xb==0) xb=m+1;
    int px=abs(xa-xb); int py=abs(ya-yb);
    ld dis=hypot(px,py);
    //cout<<i<<" "<<j<<" "<<dis<<" "<<endl;
    adj[i].push_back({j,dis});
    adj[j].push_back({i,dis});
}
void valid_edge(int i,int j){
    if(i==j) return;
    int ya=-((i-1)/(m+1)); int yb=-(j-1)/(m+1);
    int xa=(i%(m+1)); int xb=(j%(m+1));
    if(xa==0) xa=m+1;
    if(xb==0) xb=m+1;
    int px=ya-yb; int py=xb-xa;
    if(px==0 or py==0) return;
    int c=-px*xa-py*ya;
    int lb=min(xa,xb)+1;
    int rb=max(xa,xb)-1;
    if(abs(px)==1 and abs(py)==1){
         if(a[abs(min(yb,ya))][lb-1]=='#') return;
         joint_edge(i,j);
         return;
    }
    for(int k=lb;k<=rb;k++){
        ld y=(-c-px*k);
        y=y/(ld) py;
        int pos=ceil(abs(y));
        ld ylb=floor(abs(y));
        ld yrb=ceil(abs(y));
        if(ylb<abs(y) and abs(y)<yrb){
            if(a[pos][k]=='#') return;
            if(a[pos][k-1]=='#') return;
       }
       if(ylb==abs(y) and a[pos+1][k]=='#') return;
       if(yrb==abs(y) and a[pos+1][k]=='#') return;
    }
    lb=min(ya,yb)+1;
    rb=max(ya,yb)-1;
    for(int k=lb;k<=rb;k++){
        ld x=(-c-py*k);
        x=x/(ld) px;
        int pos=floor(abs(x));
        ld xlb=floor(abs(x));
        ld xrb=ceil(abs(x));
        //if(i==2 and j==9) cout<<xlb<<" "<<abs(k)<<" "<<pos<<endl;
        if(xlb<abs(x) and abs(x)<xrb){
            if(a[abs(k)][pos]=='#') return;
            if(a[abs(k)+1][pos]=='#') return;
        }
        if(xlb==abs(x) and a[abs(k)][pos-1]=='#') return;
        if(xlb==abs(x) and a[abs(k)+1][pos+1]=='#') return;
    }
    joint_edge(i,j);
    return;
}
void dijisktra(){
    using T=pair<ld,int>;
    priority_queue<T,vector<T>,greater<T>>pq;
    pq.push({0,1});
    for(int i=2;i<=(n+1)*(m+1);i++) dp[i]=inf;
    while(pq.size()){
        int u; ld val;
        tie(val,u)=pq.top();
        pq.pop();
        if(dp[u]!=val) continue; 
        for(auto v:adj[u]){
            int x=v.first;
            ld dist=v.second;
            ///if(dp[x]==dp[u]+dist) continue;
            if(dp[x]>dp[u]+dist){
                dp[x]=dp[u]+dist;
                par[x]=u;
                dis[x]=dist;
                pq.push({dp[x],x});
            }
        } 
    }
}
int main(){   
     cin>>n>>m;
     for(int i=1;i<=n;i++){
         for(int j=1;j<=m;j++){
             cin>>a[i][j];
         }
     }
     for(int i=1;i<(n+1)*(m+1);i++){
          if(i%(m+1)==0){
              adj[i].push_back({i+m+1,1});
              adj[i+m+1].push_back({i,1});
          }
          else if(i/(m+1)==n+1){
             adj[i].push_back({i+m+1,1});
             adj[i+m+1].push_back({i,1});
          }
          else{
                adj[i].push_back({i+1,1});
                adj[i+1].push_back({i,1});
                adj[i].push_back({i+m+1,1});
                adj[i+m+1].push_back({i,1});
          }
          if(i%(m+1)!=0 and i<=n*(m+1)){
              for(int k=(i+m+1)/(m+1);k<(n+1);k++){
                  for(int j=i%(m+1);j<=(m+1);j++){
                      int to=k*(m+1)+j;
                     // if(i==1) cout<<i<<" "<<k<<" "<<j<<endl;
                      valid_edge(i,to);
                  }
              }
          }
     }
     dijisktra();
     cout<<setprecision(10)<<dp[(n+1)*(m+1)]<<endl;
}
