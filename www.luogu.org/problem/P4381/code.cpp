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

const int MAXN = 1e6 + 15;
int N, bg;
int hd[MAXN], nxt[MAXN << 1], to[MAXN << 1], val[MAXN << 1], tot(1);
bool vis[MAXN], in[MAXN]; int c[MAXN], cnt; i64 h[MAXN<<1], s[MAXN<<1];
inline void addedge( int x, int y, int z ){ nxt[++tot] = hd[x], hd[x] = tot, to[tot] = y, val[tot] = z; }

void DFS( int u, int ls ){
	vis[u] = 1;
	go( i, hd[u] ) if ( i != ls ){
		if ( vis[v] ) return bg = v, in[c[++cnt] = u] = 1, h[cnt] = val[i], void();
		DFS(v, i ^ 1);
		if ( bg ){ if ( in[v] && v != bg ) in[c[++cnt] = u] = 1, h[cnt] = val[i]; return; }
	}
}

i64 ans; int q[MAXN], qh, qt;
i64 DP( int u, int fa ){
	i64 mx(0), t; vis[u] = 1;
	go( i, hd[u] ) if ( !in[v] && v != fa )
		cmax( ans, mx + (t = DP(v, u) + val[i]) ), cmax( mx, t );
	return mx;
}

i64 calc(){
	ans = 0, qh = 1, qt = 0;
	fp( i, 1, cnt ) s[i] = s[i + cnt] = DP(c[i], 0), h[i + cnt] = h[i];
	fp( i, 1, cnt << 1 ){ h[i] += h[i - 1];
		while( qh <= qt && q[qh] <= i - cnt ) ++qh;
		if ( qh <= qt ) cmax( ans, s[i] + h[i] + s[q[qh]] - h[q[qh]] );
		while( qh <= qt && s[i] - h[i] >= s[q[qt]] - h[q[qt]] ) --qt;
		q[++qt] = i;
	}
	return ans;
}

signed main(){
	read(N); int x, y;
	fp( i, 1, N ) read(x), read(y), addedge(i, x, y), addedge(x, i, y);
	i64 res(0);
	fp( i, 1, N ) if ( !vis[i] ) bg = 0, cnt = 0, DFS(i, 0), res += calc();
	printf( "%lld\n", res );
	return 0;
}

