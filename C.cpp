#include <bits/stdc++.h>
#include <iostream> 
typedef long long ll;
const int sz=2e5+1;
ll p,k,n;
ll b[sz<<1];
ll pf[sz<<1];
ll dp[sz];
ll oc[sz];
ll a[sz];
int binary_search(int i,int c){
   int low=i;
   int high=(n<<1);
   while(high>=low){
       int mid=(low+high)>>1;
       if(pf[mid]-pf[i-1]<=c) low=mid+1;
       else high=mid-1;
   }
   if(low>n) return low-n;
   else return low;
}
int main(){
     std::cin>>n>>p>>k;
     for(int i=1;i<=n;i++) std::cin>>b[i];
     for(int i=1;i<=n;i++) b[n+i]=b[i];
     for(int i=1;i<=2*n;i++) pf[i]=pf[i-1]+b[i];
     ll x=p/pf[n];
     ll c=p%pf[n];
     for(int i=1;i<=n;i++){
         dp[i]=binary_search(i,c);
         //cout<<i<<" "<<dp[i]<<endl;
     }
     bool rep=0;
     int day=1;
     int cur_day=1;
     ll ans=0;
     while(k){
         if(oc[cur_day] and !rep){
             ll team_rep=a[day-1]-a[oc[cur_day]-1];
             ll day_rep=day-oc[cur_day];
             ans+=(k/day_rep)*team_rep;
             k%=day_rep;
             rep=1;
             if(k==0) break;
         }  
         oc[cur_day]=day;
         ans+=x;
         if(cur_day>dp[cur_day]) ans++;
         cur_day=dp[cur_day];
         if(!rep) a[day++]=ans;
         k--;
     }
     std::cout<<ans<<std::endl;
}
