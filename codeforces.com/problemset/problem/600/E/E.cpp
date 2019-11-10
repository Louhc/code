#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define rgt register
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
#define getchar() ( p1 == p2 && ( p1 = bf, p2 = bf + fread( bf, 1, 1 << 21, stdin ), p1 == p2 ) ? EOF : *p1++ )
char bf[1 << 21], *p1(bf), *p2(bf);
template<typename T>
inline void read( T &x ){ char t(getchar()), flg(0); x = 0;
	for ( ; !isdigit(t); t = getchar() ) flg = t == '-';
	for ( ; isdigit(t); t = getchar() ) x = x * 10 + ( t & 15 );
	flg ? x = -x : x;
}

const int MAXN = 1e5 + 15;
int N, a[MAXN], x, y, dfn[MAXN], num, rev[MAXN], sz[MAXN];
int hd[MAXN], nxt[MAXN<<1], to[MAXN<<1], tot; i64 ans[MAXN];
inline void addedge( int x, int y ){ nxt[++tot] = hd[x], hd[x] = tot, to[tot] = y; }
void DFS( int u, int fa ){
	sz[u] = 1, rev[dfn[u] = ++num] = u;
	go( i, hd[u] ) if ( v != fa ) DFS(v, u), sz[u] += sz[v];
}
int c[MAXN], mx; i64 res;
inline void Ins( int x ){ ++c[x], mx < c[x] ? mx = c[x], res = 0 : 0, mx == c[x] ? res += x : 0; }
void DSU( int u, int fa, bool kp ){
	int son(0); go( i, hd[u] ) if ( v != fa && sz[v] > sz[son] ) son = v;
	go( i, hd[u] ) if ( v != fa && v != son ) DSU( v, u, 0 );
	if ( son ) DSU(son, u, 1); Ins(a[u]);
	go( i, hd[u] ) if ( v != fa && v != son ) fp( j, dfn[v], dfn[v] + sz[v] - 1 ) Ins(a[rev[j]]);
	ans[u] = res; if ( !kp ){ mx = res = 0; fp( i, dfn[u], dfn[u] + sz[u] - 1 ) c[a[rev[i]]] = 0; }
}

signed main(){
	read(N); fp( i, 1, N ) read(a[i]);
	fp( i, 2, N ) read(x), read(y), addedge( x, y ), addedge( y, x );
	DFS(1, 0), DSU(1, 0, 1); fp( i, 1, N ) printf( "%lld%c", ans[i], "\n "[i < N] );
	return 0;
}
