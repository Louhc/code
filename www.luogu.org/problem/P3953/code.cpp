#include<bits/stdc++.h>
using namespace std;
#if __cplusplus >= 201103L
template<class ...Args> inline int err( Args ...args ){ return fprintf( stderr, args... ); }
#else  
#define err(...) 1
#endif
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

int T, N, M, K, P;
const int MAXN = 100005, MAXM = 400005;
int hd1[MAXN], hdn[MAXN], nxt[MAXM], to[MAXM], val[MAXM], tot;
queue<int> Q; int d[MAXN]; bool vis[MAXN];
inline void addedge( int x, int y, int z ){
	nxt[++tot] = hd1[x], hd1[x] = tot, to[tot] = y, val[tot] = z;
	nxt[++tot] = hdn[y], hdn[y] = tot, to[tot] = x, val[tot] = z;
} inline int dec( int x ){ return x >= P ? x - P : x; }
int f[MAXN][55]; char v[MAXN][55];
int DP( int u, int r ){
	if ( r < 0 ) return 0;
	if ( v[u][r] ) return -1;
	if ( f[u][r] >= 0 ) return f[u][r];
	v[u][r] = 1, f[u][r] = u == N;
	go( i, hd1[u] ){
		int t = DP( v, r - ( d[v] + val[i] - d[u] ) );
		if ( t < 0 ) return -1;
		f[u][r] = dec( f[u][r] + t );
	} v[u][r] = 0;
	return f[u][r];
}

signed main(){
	read(T);
	while( T-- ){
		read(N), read(M), read(K), read(P);
		memset( hd1, 0, sizeof hd1 ), memset( hdn, 0, sizeof hdn ), tot = 0;
		int x, y, z;
		while( M-- ) read(x), read(y), read(z), addedge( x, y, z );
		Q.push(N), vis[N] = 1, memset( d, 0x3f, (N+1)<<2 ), d[N] = 0;
		while( !Q.empty() ){
			int u(Q.front()); Q.pop(); vis[u] = 0;
			go( i, hdn[u] ) if ( d[v] > d[u] + val[i] ){
				d[v] = d[u] + val[i]; if ( !vis[v] ) Q.push(v), vis[v] = 1;
			}
		} memset( f, -1, (N+1)*220 ), memset( v, 0, (N+1)*55 ), printf( "%d\n", DP( 1, K ) );	
	} 
	return 0;
}

