#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define INF 0x3f3f3f3f
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

const int MAXN = 1005, mod = 998244353;
int N, a[MAXN], ans, x, y;
int hd[MAXN], nxt[MAXN << 1], to[MAXN << 1], tot;
inline void addedge( int x, int y ){
	nxt[++tot] = hd[x], hd[x] = tot, to[tot] = y,
	nxt[++tot] = hd[y], hd[y] = tot, to[tot] = x;
}

void DFS( int u, int fa, int mx, int mn ){
	cmin( mn, a[u] ), cmax( mx, a[u] ); if ( x <= u ) ans = ( ans + (i64)mx * mn ) % mod;
	go( i, hd[u] ) if ( v != fa ) DFS( v, u, mx, mn );
}

signed main(){
	read(N); fp( i, 1, N ) read(a[i]);
	fp( i, 2, N ) read(x), read(y), addedge( x, y );
	fp( i, 1, N ) x = i, DFS(i, 0, -INF, INF);
	printf( "%d\n", ans );
	return 0;
}
