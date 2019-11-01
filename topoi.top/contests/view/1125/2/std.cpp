#include<cstdio>
#include<cstring>
#include<utility>
#include<algorithm>
#include<iostream>
#include<queue>
#include<stack>
#include<cmath>
#include<cstdlib>
#include<ctime>
#define INF 0x3f3f3f
using namespace std;
inline int read()
{
    char ch='*';
    int f=1;
    while(!isdigit(ch=getchar())) if(ch=='-') f=-1;
    int num=ch-'0';
    while(isdigit(ch=getchar())) num=num*10+ch-'0';
    return num*f;
}
typedef long long ll;
const int maxn = 2000005;
struct edge{
    int next,to;
    bool ban;
}e[maxn<<1];
int cnt,h[maxn],v[maxn];
int g[maxn],f[maxn],ans;
int a[maxn],n,m,U,V,E;
int p;
int control;
inline void add(int from,int to)
{
    e[++cnt].next=h[from];
    e[cnt].to=to;
    h[from]=cnt;
}

void dfs(int x)
{
    v[x]=1;
    if(v[a[x]]) {
        p=x;
        return ;
    }
    dfs(a[x]);
}
void dp(int x,int fa,int ban)
{
    f[x]=1;
    g[x]=INF;
    v[x]=1;
    if(x==control) g[x]=0;
    for(register int i=h[x];i;i=e[i].next)
    {
        if(i==ban||e[i].to==fa) continue;
    //  if((i^1)==from) continue ;
        dp(e[i].to,x,ban);
        g[x]+=min(f[e[i].to],g[e[i].to]);
        g[x]=min(g[x],f[x]+f[e[i].to]-1);
        f[x]+=min(g[e[i].to],f[e[i].to]);
    //  g[x]+=f[e[i].to];
    }
}       
int main()
{
    n=read();
    int u,vv;
    for(register int i=1;i<=n;i++)
    {
        a[i]=read();
        //add(u,i);
        add(a[i],i);
    }
    for(register int i=1;i<=n;i++)
    {
        if(!v[i])       
        {
            dfs(i);
            //printf("%d %d %d \n",U,V,E);          
            e[p].ban=1;
            control=a[p];
            dp(p,0,p);
            control=0;
            int temp=f[p];
            dp(p,0,p);
            ans+=min(temp,g[p]);
        }
    }
    cout<<n-ans<<endl;
    return 0;
}
