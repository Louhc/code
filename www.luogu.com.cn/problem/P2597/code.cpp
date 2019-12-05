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

const int MAXN = 7e4, MAXM = MAXN<<2;
int N, in[MAXN], dep[MAXN];
int h1[MAXN], h2[MAXN], h3[MAXN], nxt[MAXM], to[MAXM], tot;
int q[MAXN], h, t, f[MAXN][16], sz[MAXN];
inline void addedge( int *hd, int x, int y ){
	nxt[++tot] = hd[x], hd[x] = tot, to[tot] = y;
}

int LCA( int x, int y ){
	if ( dep[x] < dep[y] ) swap( x, y );
	fd( i, 15, 0 ) if ( dep[f[x][i]] > dep[y] ) x = f[x][i];
	if ( dep[x] > dep[y] ) x = f[x][0];
	fd( i, 15, 0 ) if ( f[x][i] != f[y][i] ) x = f[x][i], y = f[y][i];
	return x == y ? x : f[x][0];
} void DFS( int u ){ sz[u] = 1; go( i, h3[u] ) DFS(v), sz[u] += sz[v]; }

signed main(){
	read(N); int x, y;
	fp( i, 1, N ) while((read(x), x)) addedge( h1, x, i ), addedge( h2, i, x ), ++in[i];
	h = 1; fp( i, 1, N ) if ( !in[i] ) q[++t] = i;
	while( h <= t ){
		x = q[h++], y = to[h2[x]];
		go( i, nxt[h2[x]] ) y = LCA( y, v );
		f[x][0] = y, dep[x] = dep[y] + 1, addedge( h3, y, x );
		fp( i, 1, 15 ) f[x][i] = f[f[x][i - 1]][i - 1];
		go( i, h1[x] ) if ( !--in[v] ) q[++t] = v;
	} DFS(0); fp( i, 1, N ) printf( "%d\n", sz[i] - 1 );
	return 0;
}
