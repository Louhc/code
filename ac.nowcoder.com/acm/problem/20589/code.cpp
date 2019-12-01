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

const int _ = 500015, __ = _ << 1;
int N, hd[_], nxt[__], to[__], tot(1); double val[__];
double q[_], f[_], g[_];

inline void addedge( int x, int y, double z ){
	nxt[++tot] = hd[x], hd[x] = tot, to[tot] = y, val[tot] = z,
	nxt[++tot] = hd[y], hd[y] = tot, to[tot] = x, val[tot] = z;
}

void DFS1( int u, int ls ){
	f[u] = 1 - q[u];
	go( i, hd[u] ) if ( i != ls )
		DFS1(v, i ^ 1), f[u] *= (1 + (f[v] - 1) * val[i]);
}

void DFS2( int u, int ls ){
	g[u] = u > 1 && abs(1 + (f[u] - 1) * val[ls]) > 1e-10 ? f[u] * (1 + (g[to[ls]] / (1 + (f[u] - 1) * val[ls]) - 1) * val[ls]) : f[u];
	go( i, hd[u] ) if ( i != ls ) DFS2(v, i ^ 1);
}

signed main(){
	read(N); int x, y, z;
	fp( i, 2, N ) read(x), read(y), read(z), addedge(x, y, .01 * z);
	fp( i, 1, N ) read(z), q[i] = z * .01;
	DFS1(1, 0), DFS2(1, 0);
	double ans(0); fp( i, 1, N ) ans += 1 - g[i];
	printf( "%.6lf\n", ans );
	return 0;
}