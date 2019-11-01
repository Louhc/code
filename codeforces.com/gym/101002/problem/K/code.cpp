#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define INF 0x3f3f3f3f
#define open(s) freopen( s".in", "r", stdin ), freopen( s".out", "w", stdout )
#define fp( i, b, e ) for ( int i(b), i##end(e); i <= i##end; ++i )
#define fd( i, b, e ) for ( int i(b), i##end(e); i >= i##end; --i )
#define go( i, b ) for ( int i(b), v(to[b]); i; v = to[i = nxt[i]] )
template<class T> inline bool cmin( T &x, T y ){ return x > y ? x = y, 1 : 0; }
template<class T> inline bool cmax( T &x, T y ){ return x < y ? x = y, 1 : 0; }
#define getchar() ( p1 == p2 && ( p1 = bf, p2 = bf + fread( bf, 1, 1 << 21, stdin ), p1 == p2 ) ? EOF : *p1++ )
char bf[1 << 21], *p1, *p2;
template<class T> inline void read( T &x ){
	x = 0; char t(getchar()), flg(0);
	while( t < 48 || t > 57 ) flg = t == '-', t = getchar();
	while( t > 47 && t < 58 ) x = x * 10 + ( t & 15 ), t = getchar();
	flg ? x = -x : x;
}

const int MAXN = 2e5 + 5;
int N; i64 ans[MAXN];
int a[MAXN], hd[MAXN], nxt[MAXN << 1], to[MAXN << 1], val[MAXN << 1], tot;
inline void addedge( int x, int y, int z ){ nxt[++tot] = hd[x], hd[x] = tot, to[tot] = y, val[tot] = z; }
int stk[MAXN], tp, size, sz[MAXN], mxp, rt, b[MAXN], n; i64 d[MAXN]; bool vis[MAXN];
inline bool cmp( int x, int y ){ return a[x] == a[y] ? d[x] < d[y] : a[x] < a[y]; }
inline i64 calc( int x, int y ){ return 1ll * a[x] * a[y] + d[x] + d[y]; }

void FindRoot( int u, int fa ){
	sz[u] = 1; int t(0);
	go( i, hd[u] ) if ( !vis[v] && v != fa ) FindRoot(v, u), sz[u] += sz[v], cmax( t, sz[v] );
	cmax( t, size - sz[u] ); if ( t < mxp ) mxp = t, rt = u;
}
void DFS1( int u, int fa ){
	sz[u] = 1;
	stk[++tp] = u; go( i, hd[u] ) if ( !vis[v] && v != fa ) d[v] = d[u] + val[i], DFS1(v, u), sz[u] += sz[v];
}
int q[MAXN], _t;
inline void Push( int x ){
	while( _t > 1 && (d[x]-d[q[_t]])*(a[x]-a[q[_t-1]]) <= (d[x]-d[q[_t-1]])*(a[x]-a[q[_t]]) ) --_t;
	q[++_t] = x;
}
inline void Find( int x ){
	cmin( ans[x], calc(x, q[_t]) );
	int l(1), r(_t - 1), mid; i64 A, B;
	while( l <= r ){
		mid = ( l + r ) >> 1;
		A = calc( x, q[mid] ), B = calc( x, q[mid + 1] );
		if ( A < B ) r = mid - 1, cmin( ans[x], A );
		else l = mid + 1, cmin( ans[x], B );
	}
}

void Solve( int u ){
	vis[u] = 1; stk[tp = 1] = u, d[u] = 0;
	go( i, hd[u] ) if ( !vis[v] ) d[v] = val[i], DFS1(v, u);
	 sort( stk + 1, stk + tp + 1, cmp ); _t = 0;
	 fp( i, 1, tp ) Push(stk[i]);
	 fp( i, 1, tp ) Find(stk[i]);
	go( i, hd[u] ) if ( !vis[v] )
		mxp = INF, size = sz[v], FindRoot(v, u), Solve(rt);
}

int main(){
	read(N); int x, y, z;
	fp( i, 1, N ) read(a[i]);
	fp( i, 1, N - 1 ) read(x), read(y), read(z), addedge( x, y, z ), addedge( y, x, z );
	memset( ans, 0x3f, sizeof ans ), size = N, mxp = INF, FindRoot(1, 0), Solve(rt);
	i64 r(0); fp( i, 1, N ) r += ans[i];
	printf( "%lld\n", r );
	return 0;
}
