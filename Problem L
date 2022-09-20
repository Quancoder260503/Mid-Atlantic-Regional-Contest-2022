#include <bits/stdc++.h>
#include <iostream> 
typedef long long ll;
const int sz=2e3+1;
int n,x,k,i,j,w,m,mod;
int dx[8]={2,2,-2,-2,1,1,-1,-1};
int dy[8]={-1,1,1,-1,2,-2,2,-2};
int startx,starty;
int sx,sy,kx,ky;
int endx,endy;
std::vector<std::array<int,2>>west;
std::vector<std::array<int,2>>east;
std::vector<std::array<int,2>>south;
std::vector<std::array<int,2>>north;
std::queue<std::array<int,2>>q;
char a[sz][sz];
int dp_cnt[sz][sz];
bool c[sz][sz];
bool vis[sz][sz];
char b[sz][sz];
void valid_point(std::vector<std::array<int,2>>&dir,int t){
    for(int i=0;i<dir.size();i++){
        int px=kx+dir[i][0];
        int py=ky+dir[i][1];
        if(px<1 or px>n or py<1 or py>m) continue;
        if(a[px][py]=='K'){
            if(vis[px][py]==1){
                q.push({px,py});
                return;
            }
            else return;
        }
        if(vis[px][py]){
            q.push({px,py});
            return;
        }
    }
}
void un_attacked(int i,int j){
    for(int k=0;k<8;k++){
          int px=i+dx[k];
          int py=j+dy[k];
          if(px<1 or px>n or py<1 or py>m) continue;
          dp_cnt[px][py]--;
          if(dp_cnt[px][py]==0){
              c[px][py]=1; kx=px;ky=py;
              valid_point(west,1);
              valid_point(east,2);
              valid_point(north,3);
              valid_point(south,4);
              ///if(valid) q.push({px,py});
          }
    }
     a[i][j]='.';
     c[i][j]=1;
}
void bfs_execute(std::vector<std::array<int,2>>&dir,int t){
     bool stop=0;
     for(int i=0;i<dir.size();i++){
             int px=sx+dir[i][0];
             int py=sy+dir[i][1];
             if(px<1 or px>n or py<1 or py>m) continue;
             if(a[px][py]=='K'){
                 stop=1;
                 if(!c[px][py]) break;
                 un_attacked(px,py);
             }
             if(!c[px][py] or vis[px][py]) continue;
             vis[px][py]=1;
             if(px==endx and py==endy){
                 std::cout<<"yes"<<std::endl;
                 exit(0);
             }
             q.push({px,py});
             if(stop) break;
     }
}
void bfs(int x,int y){
    q.push({x,y});
    vis[x][y]=1;
    while(q.size()){
         std::array<int,2>t=q.front();
         q.pop();
         sx=t[0]; sy=t[1];
         bfs_execute(east,1);
         bfs_execute(west,2);
         bfs_execute(north,3);
         bfs_execute(south,4);
    }
}
int main(){
     std::cin>>n>>m;
     for(int i=1;i<=n;i++){
         for(int j=1;j<=m;j++){
             std::cin>>a[i][j];
             b[i][j]=a[i][j];
             if(a[i][j]=='R'){
                 startx=i; starty=j;
                 a[i][j]='.';
             }
             if(a[i][j]=='T'){
                 endx=i; endy=j;
                 a[i][j]='.';
             }
             c[i][j]=1;
         }
     }
     for(int i=1;i<=n;i++){
         for(int j=1;j<=m;j++){
             if(a[i][j]=='K'){
               for(int k=0;k<8;k++){
                     int px=i+dx[k];
                     int py=j+dy[k];
                     if(px<1 or px>n or py<1 or py>m) continue;
                     dp_cnt[px][py]++;
                     c[px][py]=0; 
                 }
             }
         }
     }
     for(int i=1;i<=m;i++){
           east.push_back({0,i});
           west.push_back({0,-i});
     }
      for(int i=1;i<=n;i++){
          north.push_back({-i,0});
          south.push_back({i,0});
     }
     bfs(startx,starty);
     std::cout<<"no"<<std::endl;
}
