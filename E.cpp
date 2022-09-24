#include <bits/stdc++.h>
#include <iostream> 
typedef long long ll;
const int sz=2e5+1;
const int bitsz=(1<<6);
int n,x,k,i,q,j,w,m,mod;
ll dpval[sz][6];
ll tree[sz<<2][1<<6];
ll treelz[sz<<2];
std::string s;
std::array<int,bitsz>dp[sz<<2];
std::array<int,bitsz>null;
void update(int val, int L, int R,int l=0,int r=n,int p=1){
    if(L>r or R<l) return;
    if(l==r){
        dp[p][val]++;
        return;
    }
    int mid=(l+r)>>1;
    update(val,L,R,l,mid,2*p);
    update(val,L,R,mid+1,r,2*p+1);
    dp[p][val]=dp[2*p][val]+dp[2*p+1][val];
}
void push_down(int p,int l,int mid,int r){
    if(treelz[p]!=0){
        int val=treelz[p];
        std::vector<int>tempvc1(bitsz);
        for(int i=0;i<1<<6;i++) tempvc1[val^i]+=dp[2*p][i];
        for(int i=0;i<1<<6;i++) dp[2*p][i]=tempvc1[i];
        std::vector<int>tempvc2(bitsz);
        for(int i=0;i<1<<6;i++) tempvc2[val^i]+=dp[2*p+1][i];
        for(int i=0;i<1<<6;i++) dp[2*p+1][i]=tempvc2[i];
        treelz[2*p]^=val; treelz[2*p+1]^=val;
        treelz[p]=0;
    }
}
void rupd(int val,int L,int R,int l=0,int r=n,int p=1){
    if(L>r or R<l) return;
    if(L<=l and r<=R){
        std::vector<int>tempvc(bitsz);
        for(int i=0;i<1<<6;i++) tempvc[i^val]+=dp[p][i];            
        for(int i=0;i<1<<6;i++) dp[p][i]=tempvc[i];
        ///cout<<dp[p][3]<<" "<<l<<" "<<r<<" "<<tree[p][0]<<endl;
        treelz[p]^=val;
        return;
    }
    int mid=(l+r)>>1;
    push_down(p,l,mid,r);
    rupd(val,L,R,l,mid,2*p);
    rupd(val,L,R,mid+1,r,2*p+1);
    for(int i=0;i<(1<<6);i++) dp[p][i]=dp[2*p][i]+dp[2*p+1][i];
}
std::array<int,bitsz>query(int L,int R,int l=0,int r=n,int p=1){
    if(L>r or R<l) return null;
    if(L<=l and r<=R) return dp[p];
    int mid=(l+r)>>1;
    push_down(p,l,mid,r);
    std::array<int,bitsz>left=query(L,R,l,mid,2*p);
    std::array<int,bitsz>right=query(L,R,mid+1,r,2*p+1);
    for(int i=0;i<(1<<6);i++) left[i]+=right[i];
    return left;
}
int main(){
    std::cin>>s>>q;
    n=s.length();
    update(0,0,0);
     for(int i=0;i<s.length();i++){
        for(int j=0;j<6;j++){
            dpval[i+1][j]=dpval[i][j];
        }
        dpval[i+1][s[i]-'a']++;
        int bit_val=0;
        for(int j=0;j<6;j++){
            if(dpval[i+1][j]%2==1) bit_val+=(1<<j);
        }
        update(bit_val,i+1,i+1);
    }
    for(int i=0;i<q;i++){
        int t;
        std::cin>>t;
        if(t==1){
            int l,r;
            std::cin>>l>>r;
            ll ans=0;
            std::array<int,bitsz>re=query(l-1,r);
            for(int j=0;j<(1<<6);j++){
                 ans+=((ll) re[j]*(re[j]-1))/2;
            }
            ///cout<<l<<" "<<r<<endl;
            ///cout<<query(0,l-1,r)<<endl;
           std::cout<<ans<<std::endl;
        }
        else{
            int pos; char p;
            std::cin>>pos>>p;
            ll bit_val=(ll) 1<<(p-'a');
            ll bit_pos=((ll) 1<<(s[pos-1]-'a'));
            rupd(bit_pos^bit_val,pos,n);
            ///rupd(bit_val,pos,n);
            s[pos-1]=p;
        }
    }
}
