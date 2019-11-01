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
//#define getchar() ( p1 == p2 && ( p1 = bf, p2 = bf + fread( bf, 1, 1 << 21, stdin ), p1 == p2 ) ? EOF : *p1++ )
char bf[1 << 21], *p1(bf), *p2(bf);
template<typename T>
inline void read( T &x ){ char t(getchar()), flg(0); x = 0;
	for ( ; !isdigit(t); t = getchar() ) flg = t == '-';
	for ( ; isdigit(t); t = getchar() ) x = x * 10 + ( t & 15 );
	flg ? x = -x : x;
}

int testcase;
int N, M, T, n, fa[MAXN], a[MAXN], b[MAXN], f[MAXN][18];
int hd[MAXN], nxt[MAXN<<1], to[MAXN<<1], tot;
int ls[MAXM], rs[MAXM], s[MAXM], pl[MAXM], tp, sum; bool d[MAXM];
inline int New(){ const int t = tp ? pl[tp--] : ++sum; d[t] = 1; return t; }
inline void Del( int c ){ pl[++tp] = c, d[c] = 0, ls[c] = rs[c] = s[c] = 0; }
inline void addedge( int x, int y ){
	nxt[++tot] = hd[x], hd[x] = tot, to[tot] = y,
	nxt[++tot] = hd[y], hd[y] = tot, to[tot] = x;
}
int Find( int x ){ return fa[x] > 0 ? fa[x] = find(fa[x]) : x; }
void Merge( int x, int y ){
	x = Find(x), y = Find(y),
	fa[x] > fa[y] ? x^=y^=x^=y : x,
	fa[x] += fa[y], fa[y] = x;
}
void DFS( int u ){
	fp( i, 1, 16 ) f[u][i] = f[f[u][i - 1]][i - 1];
	go( i, hd[u] ) if ( v != f[u][0] )
		f[v][0] = u, DFS(v);
}
void Clear( int c ){
	if ( !d[c] ) return;
	if ( ls[c] ) Clear(ls[c]), ls[c] = 0;
	if ( rs[c] ) Clear(rs[c]), rs[c] = 0;
}
void merge( int x, int y ){
	fa[find(x)] < fa[find(y)] x^=y^=x^=y : x;
	f[x][0] = y, addegde( x, y ), DFS(x);
}

signed main(){
	read(testcase);
	while( testcase-- ){
		read(N), read(M), read(T);
		memset( fa, -1, sizeof fa );
		fp( i, 1, N ) read(a[i]), b[i] = a[i];
		sort( b + 1, b + N + 1 ), n = unique( b + 1, b + N + 1 ) - b - 1;
		fp( i, 1, N ) a[i] = lower_bound( b + 1, b + N + 1, a[i] ) - b;
		
	}
	return 0;
}


