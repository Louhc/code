#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define INF 0x3f3f3f3f
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline void cmax( T &x, T y ){ x < y ? x = y : x; }
template<typename T> inline void cmin( T &x, T y ){ y < x ? x = y : x; }
#define getchar() ( p1 == p2 && ( p1 = bf, p2 = bf + fread( bf, 1, 1 << 21, stdin ), p1 == p2 ) ? EOF : *p1++ )
char bf[1 << 21], *p1(bf), *p2(bf);
template<typename T>
inline void read( T &x ){ char t(getchar()), flg(0); x = 0;
	for ( ; !isdigit(t); t = getchar() ) flg = t == '-';
	for ( ; isdigit(t); t = getchar() ) x = x * 10 + ( t & 15 );
	flg ? x = -x : x;
}

const int MAXN = 1e5 + 5;
int N, c[MAXN];
int hd[MAXN], nxt[MAXN<<1], to[MAXN<<1], tot;
i64 sum[MAXN]; int cs[MAXN], r[MAXN];
int sz[MAXN], size, rt, mpt; bool vis[MAXN];
inline void addedge( int x, int y ){ nxt[++tot] = hd[x], hd[x] = tot, to[tot] = y; }
void findrt( int u, int fa ){
	sz[u] = 1; int t(0);
	go( i, hd[u] ) if ( !vis[v] && v != fa )
		findrt(v, u), sz[u] += sz[v], cmax( t, sz[v] );
	cmax( t, size - sz[u] );
	if ( t < mpt ) mpt = t, rt = u;
}

// cs[i]表示颜色i能得到的所有贡献,算根的颜色
i64 s; int rsp;
void DFS( int u, int fa ){ // 初始化数组,顺便计算子树大小 
	r[c[u]] = 0, sz[u] = 1;
	go( i, hd[u] ) if ( v != fa && !vis[v] ) DFS(v, u), sz[u] += sz[v];
}
void DFS1( int u, int fa ){ // 计算贡献 
	if ( !cs[c[u]] ) r[c[u]] += sz[u], s += sz[u];
	++cs[c[u]];
	go( i, hd[u] ) if ( v != fa && !vis[v] ) DFS1( v, u );
	--cs[c[u]];
}
void DFS2( int u, int fa, i64 s, int ct ){ // 计算最终结果 
	if ( !cs[c[u]] ) s -= r[c[u]], ++ct;
	++cs[c[u]];
	go( i, hd[u] ) if ( v != fa && !vis[v] ) DFS2(v, u, s, ct);
	sum[u] += 1ll * ct * rsp + s;
	--cs[c[u]];
}
void change( int u, int fa, bool flg ){
	if ( !cs[c[u]] ) flg ? ( r[c[u]] += sz[u], s += sz[u] ) : ( r[c[u]] -= sz[u], s -= sz[u] );
	++cs[c[u]];
	go( i, hd[u] ) if ( v != fa && !vis[v] ) change( v, u, flg );
	--cs[c[u]];
}
void trd( int u ){
	vis[u] = 1, DFS(u, 0), s = 0, DFS1(u, 0), ++cs[c[u]];
	go( i, hd[u] ) if ( !vis[v] )
		rsp = sz[u] - sz[v], change( v, u, 0 ),
		DFS2( v, u, s - r[c[u]], 1 ), change( v, u, 1 );
	--cs[c[u]], sum[u] += s;
	go( i, hd[u] ) if ( !vis[v] )
		size = sz[v], mpt = INF, findrt(v, u), trd(rt);
}

signed main(){
	read(N); int x, y;
	fp( i, 1, N ) read(c[i]);
	fp( i, 2, N ) read(x), read(y), addedge(x, y), addedge(y, x);
	mpt = INF, size = N, findrt(1, 0), trd(rt);
	fp( i, 1, N ) printf( "%lld\n", sum[i] );
	return 0;
}

