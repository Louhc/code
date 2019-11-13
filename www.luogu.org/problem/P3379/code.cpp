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

const int MAXN = 5e5 + 15, MAXM = MAXN<<1;
int N, M, Q, S, p[MAXN];
int hd[MAXN], nxt[MAXM], to[MAXM], tot;
inline void addedge( int x, int y ){
	nxt[++tot] = hd[x], hd[x] = tot, to[tot] = y;
}
int f[MAXM][20], lg[MAXM], dep[MAXN];
void DFS( int u, int fa ){
	f[p[u] = ++M][0] = u, dep[u] = dep[fa] + 1;
	go( i, hd[u] ) if ( v != fa )
		DFS(v, u), f[++M][0] = u;
} inline int Max( int x, int y ){ return dep[x] > dep[y] ? y : x; }

signed main(){
	read(N), read(Q), read(S); int x, y, z;
	fp( i, 2, N ) read(x), read(y), addedge(x, y), addedge(y, x);
	DFS(S, 0); fp( i, 2, M ) lg[i] = lg[i >> 1] + 1;
	fp( i, 1, lg[M] ) fp( j, 1, M - (1 << i) + 1 )
		f[j][i] = Max( f[j][i - 1], f[j + (1 << (i - 1))][i - 1] );
	while( Q-- ){
		read(x), read(y), x = p[x], y = p[y], x > y ? x^=y^=x^=y : x, z = lg[y - x + 1];
		printf( "%d\n", Max(f[x][z], f[y - (1 << z) + 1][z]) );
	}
	return 0;
}

