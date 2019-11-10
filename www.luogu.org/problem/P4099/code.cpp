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

const int mod = 1e9 + 7, MAXN = 1005;
int T, N, n, h1[MAXN], h2[MAXN], nxt[MAXN<<1], to[MAXN<<1], tot;
int sz[MAXN], f[MAXN][MAXN], g[MAXN], C[MAXN][MAXN];
inline void addedge( int *hd, int x, int y ){ nxt[++tot] = hd[x], hd[x] = tot, to[tot] = y; }
inline int dec( int x ){ return x >= mod ? x - mod : x; }
inline int rec( int x ){ return x < 0 ? x + mod : x; }

void DFS( int u, int fa ){
	memset( f[u] + 1, 0, N<<2 ), sz[u] = 1, f[u][1] = 1;
	go( e, h1[u] ) if ( v != fa ){ // in dfn, u is before v
		DFS(v, u), memcpy( g + 1, f[u] + 1, sz[u] << 2 ), memset( f[u] + 1, 0, sz[u] << 2 );
		fp( j, 1, sz[u] ) fp( i, j, sz[v] + j - 1 )
			f[u][i] = ( f[u][i] + 1ll * g[j] * C[i - 1][j - 1] % mod * C[sz[u] + sz[v] - i][sz[u] - j] % mod * rec(f[v][sz[v]] - f[v][i - j]) ) % mod;
		sz[u] += sz[v];
	}
	go( e, h2[u] ) if ( v != fa ){ // in dfn, u is after v
		DFS(v, u), memcpy( g + 1, f[u] + 1, sz[u] << 2 ), memset( f[u] + 1, 0, sz[u] << 2 );
		fp( j, 1, sz[u] ) fp( i, j + 1, sz[v] + j )
			f[u][i] = ( f[u][i] + 1ll * g[j] * C[i - 1][j - 1] % mod * C[sz[u] + sz[v] - i][sz[u] - j] % mod * f[v][i - j] ) % mod;
		sz[u] += sz[v];
	} fp( i, 1, sz[u] ) f[u][i] = dec( f[u][i - 1] + f[u][i] );
}

signed main(){
	read(T), C[0][0] = 1;
	fp( i, 1, 1000 ){ C[i][0] = 1; fp( j, 1, i ) C[i][j] = dec(C[i - 1][j - 1] + C[i - 1][j]); }
	while( T-- ){
		read(N), memset( h1+1, 0, N<<2 ), memset( h2+1, 0, N<<2 ), tot = 0;
		char t; int x, y;
		fp( i, 2, N ){
			read(x), t = getchar(), read(y), ++x, ++y;
			if ( t == '<' ) addedge( h1, x, y ), addedge( h2, y, x );
			else addedge( h1, y, x ), addedge( h2, x, y );
		} DFS(1, 0), printf( "%d\n", f[1][N] );
	}
	return 0;
}
