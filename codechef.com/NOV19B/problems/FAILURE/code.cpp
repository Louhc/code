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

const int MAXN = 1e5 + 15, MAXM = 2e5 + 15;
// const int MAXN = 1e3 + 15, MAXM = 2e5 + 15;
int T, N, M;
int hd[MAXN], nxt[MAXM], to[MAXM], tot;
inline void addedge( int x, int y ){
	nxt[++tot] = hd[x], hd[x] = tot, to[tot] = y;
}

int fbd, bg, r;
char vis[MAXN], tg[MAXN], te[MAXM];

bool Find( int u, int ls ){
	vis[u] = 1;
	go( i, hd[u] ) if ( v != fbd && i != ls ){
		if ( vis[v] ) return bg = v, te[i] = tg[u] = 1;
		if ( Find(v, i ^ 1) ) return te[i] = tg[u] = (tg[v] && v != bg), 1;
	} return 0;
}
bool find( int u, int ls ){ 
	vis[u] = 1;
	go( i, hd[u] ) if ( v != fbd && i != ls )
		if ( vis[v] || find(v, i ^ 1) ) return 1;
	return 0;
}
inline int check( int x ){
	memset( vis, 0, sizeof vis ), fbd = x;
	fp( i, 1, N ) if ( i != x && !vis[i] && find(i, 0) ) return i;
	return 0;
}
int DFS( int u, int ls ){
	vis[u] = 1; int x;
	go( i, hd[u] ) if ( i != ls && !te[i] && !te[i ^ 1] ){
		if ( tg[v] ) return r = v, 1;
		if ( vis[v] ) return 2;
		if ( ( x = DFS(v, i ^ 1) ) ) return x;
	} return 0;
}

signed main(){
	read(T);
	while( T-- ){
		read(N), read(M); int x, y;
		memset( hd, 0, sizeof hd ), tot = 1;
		fp( i, 1, M ) read(x), read(y), addedge(x, y), addedge(y, x);
		
		if ( !(x = check(0)) ){ printf("-1\n"); continue; }
		memset( vis, 0, sizeof vis ), memset( tg, 0, sizeof tg ), memset( te, 0, sizeof te );
		bool flg(0); Find(x, -1);
		fp( i, 1, N ) if ( tg[i] ){
			if ( !check(i) ) flg = 1, printf( "%d\n", i ); break;
		} if ( flg ) continue;
		memset( vis, 0, sizeof vis ), flg = 1;
		fp( i, 1, N ) if ( tg[i] ){
			y = DFS(i, -1);
			if ( y == 1 ){
				x = i, y = r;
				if ( x > y ) swap( x, y );
				if ( !check(x) ) printf( "%d\n", x ), flg = 0;
				else if ( !check(y) ) printf( "%d\n", y ), flg = 0;
				break;
			} else if ( y == 2 ) break;
		} if ( flg ) printf("-1\n");
	}
	return 0;
}
