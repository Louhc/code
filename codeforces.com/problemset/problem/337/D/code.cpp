#include<bits/stdc++.h>
using namespace std;
#define i64 long long
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
int N, M, D; bool vis[MAXN];
int hd[MAXN], nxt[MAXN<<1], to[MAXN<<1], tot;
inline void addegde( int x, int y ){
	nxt[++tot] = hd[x], hd[x] = tot, to[tot] = y,
	nxt[++tot] = hd[y], hd[y] = tot, to[tot] = x;
}
int w, s, A, B, d1[MAXN], d2[MAXN];
void DFS1( int u, int fa, int d ){
	if ( vis[u] && d > s ) s = d, w = u;
	go( i, hd[u] ) if ( v != fa ) DFS1(v, u, d + 1);
}
void DFS2( int u, int fa, int *d ){
	go( i, hd[u] ) if ( v != fa )
		d[v] = d[u] + 1, DFS2(v, u, d);
}

signed main(){
	read(N), read(M), read(D); int x, y;
	while( M-- ){ read(x), vis[x] = 1; }
	fp( i, 2, N ) read(x), read(y), addegde( x, y );
	DFS1(1, 0, 0), A = w, w = s = 0, DFS1(A, 0, 0), B = w;
	DFS2(A, 0, d1), DFS2(B, 0, d2); int ans(0);
	fp( i, 1, N ) ans += d1[i] <= D && d2[i] <= D;
	printf( "%d\n", ans );
	return 0;
}

