#include<bits/stdc++.h>
using namespace std;
template<class T> inline bool cmax( T &x, T y ){ return x < y ? x = y, 1 : 0; }
#define open(s) freopen( s".in", "r", stdin ), freopen( s".out", "w", stdout )
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[b]); i; v = to[i = nxt[i]] )

const int MAXN = 5e5 + 15;
int N, M;
int hd[MAXN], nxt[MAXN<<1], to[MAXN<<1], tot; char val[MAXN<<1];
char s[MAXN];
int l1[MAXN], f1[MAXN], l2[MAXN], f2[MAXN];
inline void addedge( int x, int y, char z ){
	nxt[++tot] = hd[x], hd[x] = tot, to[tot] = y, val[tot] = z;
}

void DFS( int u, int fa ){
	l1[u] = l2[u] = 0, f1[u] = f2[u] = u;
	go( i, hd[u] ) if ( v != fa ){
		DFS(v, u);
		const int t1(l1[v] + (s[l1[v] + 1] == val[i])), t2(l2[v] + (s[M - l2[v]] == val[i]));
		if ( t1 + l2[u] >= M ) printf( "%d %d\n", f1[v], f2[u] ), exit(0);
		if ( t2 + l1[u] >= M ) printf( "%d %d\n", f1[u], f2[v] ), exit(0);
		if ( cmax(l1[u], t1) ) f1[u] = f1[v];
		if ( cmax(l2[u], t2) ) f2[u] = f2[v];
	}
}

int main(){
	scanf( "%d %d", &N, &M ); int x, y; char z;
	fp( i, 1, N - 1 ) scanf( "%d %d %c", &x, &y, &z ), addedge( x, y, z ), addedge( y, x, z );
	scanf( "%s", s + 1 ), DFS(1, 0), printf( "-1 -1\n" );
	return 0;
}
