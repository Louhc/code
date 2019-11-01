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
#define getchar() ( p1 == p2 && ( p1 = bf, p2 = bf + fread( bf, 1, 1 << 21, stdin ), p1 == p2 ) ? EOF : *p1++ )
char bf[1 << 21], *p1(bf), *p2(bf);
template<typename T>
inline void read( T &x ){ char t(getchar()), flg(0); x = 0;
	for ( ; !isdigit(t); t = getchar() ) flg = t == '-';
	for ( ; isdigit(t); t = getchar() ) x = x * 10 + ( t & 15 );
	flg ? x = -x : x;
}

const int MAXN = 1e5 + 15;
int T, N, a[1000005], b[1000005];

signed main(){
	read(T);
	while( T-- ){
		read(N); int x, n(0); i64 c1(0), c2(0);
		fp( i, 1, N ) read(x), ++a[x], cmax( n, x );
		fp( i, 1, N ) read(x), ++b[x], cmax( n, x );
		fp( i, 1, n ){
			c1 += (i64)a[i] * b[i - 1];
			c2 += (i64)b[i] * a[i - 1];
			a[i] += a[i - 1], b[i] += b[i - 1];
		} printf( c1 != c2 ? c1 < c2 ? "Bob\n" : "Alice\n" : "Tie\n" );
		memset( a, 0, (n + 1) << 2 ), memset( b, 0, (n + 1) << 2 );
	}
	return 0;
}
