#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
inline LL read(){
    LL x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
    return x*f;
}
const int MAXN=100005;
struct Node{
    LL sum,hix,stag,htag;
    Node(){
        sum=hix=stag=htag=0;
    }
    friend Node operator + (Node lf,Node rt){
        Node res;
        res.sum=max(lf.sum,rt.sum);
        res.hix=max(lf.hix,rt.hix);
        return res;
    }
}b[MAXN*4];
struct Qst{
    int l,r,id;
}q[MAXN];
bool cmp(Qst x,Qst y){
    return x.r<y.r;
}
int n,m,cur[MAXN*2],pre[MAXN],ql,qr;LL a[MAXN],ans[MAXN],k;
#define mid ((l+r)>>1)
#define lc (o<<1)
#define rc ((o<<1)|1)
void pushup(int o){
    b[o]=b[lc]+b[rc];
}
void pushdown(int o){//注意更新先后顺序 
    b[lc].hix=max(b[lc].hix,b[lc].sum+b[o].htag);
    b[rc].hix=max(b[rc].hix,b[rc].sum+b[o].htag);
    b[lc].sum+=b[o].stag;
    b[rc].sum+=b[o].stag;
    b[lc].htag=max(b[lc].htag,b[lc].stag+b[o].htag);
    b[rc].htag=max(b[rc].htag,b[rc].stag+b[o].htag);
    b[lc].stag+=b[o].stag;
    b[rc].stag+=b[o].stag;
    b[o].stag=b[o].htag=0;
}
void upd(int o,int l,int r){
    if(ql<=l&&r<=qr){
        b[o].sum+=k;
        b[o].hix=max(b[o].hix,b[o].sum);
        b[o].stag+=k;
        b[o].htag=max(b[o].htag,b[o].stag);
        return;
    }
    pushdown(o);
    if(mid>=ql) upd(lc,l,mid);
    if(mid<qr) upd(rc,mid+1,r);
    pushup(o);
}
Node query(int o,int l,int r){
    if(ql<=l&&r<=qr) return b[o];
    pushdown(o);
    if(mid<ql) return query(rc,mid+1,r);
    else if(mid>=qr) return query(lc,l,mid);
    else return query(lc,l,mid)+query(rc,mid+1,r);
}
int main(){
    n=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
        pre[i]=cur[a[i]+(int)1e5];
        cur[a[i]+(int)1e5]=i;
    }
    m=read();
    for(int i=1;i<=m;i++){
        q[i].l=read(),q[i].r=read();
        q[i].id=i;
    }
    sort(q+1,q+m+1,cmp);
    int j=1;
    for(int i=1;i<=n;i++){
        ql=pre[i]+1,qr=i,k=a[i];
        upd(1,1,n);
        for(;j<=m&&q[j].r<=i;j++){
            ql=q[j].l,qr=q[j].r;
            ans[q[j].id]=query(1,1,n).hix;
        }
    }
    for(int i=1;i<=m;i++)
        printf("%lld\n",ans[i]);
    return 0;
}
