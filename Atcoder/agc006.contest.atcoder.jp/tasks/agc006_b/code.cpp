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
template<typename T>
inline void read( T &x ){ char t(getchar()), flg(0); x = 0;
	for ( ; !isdigit(t); t = getchar() ) flg = t == '-';
	for ( ; isdigit(t); t = getchar() ) x = x * 10 + ( t & 15 );
	flg ? x = -x : x;
}

const int MAXN = 2e5 + 5; int N, x;
int a[MAXN]; bool vis[MAXN]; int l(1), r;
inline int GetL(){ while( l <= r && vis[l] ) ++l; vis[l] = 1; return l; }
inline int GetR(){ while( l <= r && vis[r] ) --r, vis[r] = 1; return r; }


signed main(){
	read(N), read(x), r = 2 * N - 1;
	if ( N == 1 ) return printf( "%d\n", x ), 0;
	if ( x == 1 || x == 2 * N - 1 ) return printf( "No\n" ), 0;
	a[N] = x, vis[x] = 1, a[N + 1] = GetR(), a[N - 1] = GetL();
	if ( x == 1 ) a[N - 2] = GetR(); else a[N + 2] = GetL();
	fp( i, 1, 2 * N - 1 ) if ( !a[i] ) a[i] = GetL();
	printf( "Yes\n" );
	fp( i, 1, 2 * N - 1 ) printf( "%d\n", a[i] );
	return 0;
}
