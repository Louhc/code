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
// #define getchar() ( p1 == p2 && ( p1 = bf, p2 = bf + fread( bf, 1, 1 << 21, stdin ), p1 == p2 ) ? EOF : *p1++ )
char bf[1 << 21], *p1(bf), *p2(bf);
template<typename T>
inline void read( T &x ){ char t(getchar()), flg(0); x = 0;
	for ( ; !isdigit(t); t = getchar() ) flg = t == '-';
	for ( ; isdigit(t); t = getchar() ) x = x * 10 + ( t & 15 );
	flg ? x = -x : x;
}

const int MAXN = 1e5 + 5, mod = 123456789;
int N, M, a[MAXN], b[MAXN]; double d[MAXN];
int c[MAXN];
#define DIV(x, y) (int)(x * d[y])
inline int dec( int x ){ return x >= mod ? x - mod : x; }

inline i64 get( int x, int y ){
	if ( x <= M ) return f[x][y];
	int ans(0); for ( int i = y; i >= 0; i -= x ) ans = dec(ans + b[i]);
	return ans;
}

inline i64 calc( int n ){
	i64 ans(0);
	for ( int i = 1, j, k; i <= n; i = j + 1 )
		k = DIV(n, i), j = DIV(n, k), ans = ( ans + get( k, n - k * i ) * a[k] ) % mod;
	return ans;
}

signed main(){
	read(N), M = sqrt(N); fp( i, 1, N ) read(a[i]), d[i] = 1. / i; fp( i, 0, N - 1 ) read(b[i]);
	fp( x, 1, M ) fp( y, 0, x - 1 ){
		// x = i / j, y = i % x, k < j
		for ( int k = y; k <= n; k += x ){
			;
		}
	}
	return 0;
}
