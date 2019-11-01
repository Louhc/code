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

const int MAXN = 200005;
int N, M, s[MAXN];
int hd[MAXN], nxt[MAXN<<1], to[MAXN<<1], tot;
bool vis[MAXN]; int c1, c2;
inline void addedge( int x, int y ){
	nxt[++tot] = hd[x], hd[x] = tot, to[tot] = y;
}

void DFS( int u ){
	vis[u] = 1; ++c1;
	go( i, hd[u] ){
		++c2; if ( !vis[v] ) vis[v] = 1, DFS(v);
	}
}

signed main(){
	read(N), read(M); int x, y, ans(0);
	fp( i, 1, M ) read(x), read(y), addedge( x, y ), addedge( y, x );
	fp( i, 1, N ) if ( !vis[i] ) c1 = c2 = 0, DFS(i), c2 >>= 1, ans += (c1 ^ c2) & 1 ? c1 - 1 : c1;
	printf( "%d\n", ans );
	return 0;
}
