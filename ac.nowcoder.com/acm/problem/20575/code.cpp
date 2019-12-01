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
//#define getchar() ( p1 == p2 && ( p1 = bf, p2 = bf + fread( bf, 1, 1 << 21, stdin ), p1 == p2 ) ? EOF : *p1++ )
char bf[1 << 21], *p1(bf), *p2(bf);
template<typename T>
inline void read( T &x ){ char t(getchar()), flg(0); x = 0;
	for ( ; !isdigit(t); t = getchar() ) flg = t == '-';
	for ( ; isdigit(t); t = getchar() ) x = x * 10 + ( t & 15 );
	flg ? x = -x : x;
}

const int _ = 1e4 + 15, __ = 1e6 + 15;
int N, M, S, T, d[_], h[_];
int hd[_], nxt[__], to[__], tot;
int dfn[_], low[_], s[_], c[_], tp, num, cnt;
vector<int> vec[_];
double a[105][105], f[_];

inline void addedge( int x, int y ){
	nxt[++tot] = hd[x], hd[x] = tot, to[tot] = y;
}


void Tarjan( int u ){
	dfn[u] = low[u] = ++num, s[++tp] = u;
	go( i, hd[u] ) if ( !dfn[v] ) Tarjan(v), cmin( low[u], low[v] );
	else if ( !c[v] ) cmin( low[u], dfn[v] );
	if ( dfn[u] == low[u] ){ ++cnt; while( s[tp + 1] != u ) c[s[tp--]] = cnt; }
}

void Gauss( int n ){
	fp( i, 1, n ){
		int o(-1); fp( j, i, n ) if ( abs(a[j][i]) > 1e-10 ){ o = j; break; }
		if ( o == -1 ){ printf("INF\n"); exit(0); }
		if ( o != i ) fp( j, i, n ) swap( a[i][j], a[o][j] );
		double t(a[i][i]); fp( j, i, n + 1 ) a[i][j] /= t;
		fp( j, 1, n ) if ( i != j ){ t = a[j][i]; fp( k, i, n + 1 ) a[j][k] -= t * a[i][k]; }
	}
}

void work( int w ){
	int n = vec[w].size(); memset( a, 0, sizeof a );
	fp( i, 1, n ) h[vec[w][i - 1]] = i;
	fp( i, 1, n ){
		int u(vec[w][i - 1]); a[i][n + 1] += 1 + f[u], a[i][i] += 1;
		go( j, hd[u] ) if ( c[v] == w ) if ( c[v] == w ) a[h[v]][h[u]] -= 1. / d[v];
	} Gauss(n); fp( i, 1, n ) f[vec[w][i - 1]] = a[i][n + 1];
	for ( int u : vec[w] ) go( i, hd[u] ) if ( c[v] != w ) f[v] += f[u] / d[v];
}

bool vis[_];
bool check( int u ){
	if ( u == S ) return 1;
	vis[u] = 1; go( i, hd[u] ) if ( !vis[v] && check(v) ) return 1;
	return 0;
}

signed main(){
	read(N), read(M), read(S), read(T);
	int x, y; fp( i, 1, M ) read(x), read(y), x != T ? addedge(y, x), ++d[x] : 1;
	Tarjan(T); if ( !dfn[S] ) return printf("INF\n"), 0;
	fp( i, 1, N ) if ( !c[i] && check(i) ) return printf("INF\n"), 0;
	fp( i, 1, N ) vec[c[i]].push_back(i); fd( i, cnt - 1, 1 ) work(i);
	printf( "%.3lf\n", f[S] );
	return 0;
}