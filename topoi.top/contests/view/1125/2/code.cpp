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
int N, fa[MAXN];
int hd[MAXN], nxt[MAXN], to[MAXN], tot;
int f[MAXN][2]; bool vis[MAXN];

inline void addedge( int x, int y ){
	nxt[++tot] = hd[x], hd[x] = tot, to[tot] = y;
}

int bv, bu; bool o;

void DFS( int u ){
	vis[u] = 1, f[u][1] = f[u][0] = 0;
	if ( o && u == bu ) f[u][1] = 1;
	go( i, hd[u] ) if ( u != bu || v != bv ){
		DFS(v);
		f[u][1] = max( f[u][1] + max( f[v][0], f[v][1] ), f[u][0] + f[v][0] + 1 );
		f[u][0] += max( f[v][0], f[v][1] );
	}
}

signed main(){
	read(N); int ans(0);
	fp( i, 1, N ) read(fa[i]), addedge(fa[i], i);
	
	fp( i, 1, N ) if ( !vis[i] ){
		vis[bv = i] = 1;
		while( !vis[fa[bv]] ) vis[bv = fa[bv]] = 1;
		bu = fa[bv];
		
		int t = -INF;
		o = 1, DFS(bv);
		cmax( t, f[bv][0] );
		o = 0, DFS(bv);
		cmax( t, f[bv][1] );
		ans += t;
	} printf( "%d\n", ans );
	return 0;
}

