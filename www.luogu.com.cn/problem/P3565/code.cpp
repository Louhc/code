#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define f80 long double
#define rgt register
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline bool cmax( T &x, T y ){ return x < y ? x = y, 1 : 0; }
template<typename T> inline bool cmin( T &x, T y ){ return y < x ? x = y, 1 : 0; }
#define getchar() ( p1 == p2 && ( p1 = bf, p2 = bf + fread( bf, 1, 1 << 21, stdin ), p1 == p2 ) ? EOF : *p1++ )
char bf[1 << 21], *p1(bf), *p2(bf);
template<typename T>
inline void read( T &x ){ char t(getchar()), flg(0); x = 0;
	for ( ; !isdigit(t); t = getchar() ) flg = t == '-';
	for ( ; isdigit(t); t = getchar() ) x = x * 10 + ( t & 15 );
	flg ? x = -x : x;
}

const int MAXN = 5005;
int N, hd[MAXN], nxt[MAXN << 1], to[MAXN << 1], tot;
inline void addedge( int x, int y ){ nxt[++tot] = hd[x], hd[x] = tot, to[tot] = y; }
int son[MAXN], len[MAXN];
i64 pool[MAXN<<2], *id = pool, *f[MAXN], *g[MAXN], ans;

void DFS( int u, int fa ){ len[u] = 1;
	go( i, hd[u] ) if ( v != fa )
		DFS(v, u), cmax( len[u], len[v] + 1 ) ? son[u] = v : v;
}

void DP( int u, int fa ){
	if ( son[u] ) f[son[u]] = f[u] + 1, g[son[u]] = g[u] - 1, DP(son[u], u);
	f[u][0] = 1, ans += g[u][0];
	go( i, hd[u] ) if ( v != fa && v != son[u] ){
		f[v] = id, id += len[v] << 1, g[v] = id, id += len[v] << 1, DP(v, u);
		fp( j, 0, len[v] - 1 ){
			if ( j ) ans += f[u][j - 1] * g[v][j];
			ans += g[u][j + 1] * f[v][j];
		}
		fp( j, 0, len[v] - 1 ){
			g[u][j + 1] += f[u][j + 1] * f[v][j];
			if ( j ) g[u][j - 1] += g[v][j];
			f[u][j + 1] += f[v][j];
		}
	}
}

signed main(){
	read(N); int x, y;
	fp( i, 2, N ) read(x), read(y), addedge( x, y ), addedge( y, x );
	DFS(1, 0), f[1] = id, id += len[1] << 1, g[1] = id, id += len[1] << 1,
	DP(1, 0), printf( "%lld\n", ans );
	return 0;
}

