#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define open(s) freopen( s".in", "r", stdin ), freopen( s".out", "w", stdout )
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline void cmax( T &x, T y ){ x < y ? x = y : x; }
template<typename T> inline void cmin( T &x, T y ){ y < x ? x = y : x; }
#define getchar() ( p1 == p2 && ( p1 = bf, p2 = bf + fread( bf, 1, 1 << 21, stdin ), p1 == p2 ) ? EOF : *p1++ )
char bf[1 << 21], *p1(bf), *p2(bf);
template<typename T>
inline void read( T &x ){ char t(getchar()), flg(0); x = 0;
        for ( ; !isdigit(t); t = getchar() ) flg = t == '-';
        for ( ; isdigit(t); t = getchar() ) x = x * 10 + ( t & 15 );
        flg ? x = -x : x;
}


const int _ = 4e5 + 55, mod = 998244353, inv2 = (mod + 1) >> 1;
int N, a[_], b[_];
int r[_], g[_], invn;
inline int Pow( int x, int y = mod - 2 ){ int ans(1); for ( ; y; y >>= 1, x = (i64)x * x % mod ) if ( y & 1 ) ans = (i64)ans * x % mod; return ans; }
inline int inc( int x ){ return x + (x >> 31 & mod); }
inline int Init( int N ){
	int n(1), w(-1); while( n < N ) n <<= 1, ++w;
	fp( i, 0, n - 1 ) r[i] = ( r[i >> 1] >> 1 ) | ((i & 1) << w);
	g[0] = 1, g[1] = Pow(3, (mod - 1) / n), invn = Pow(n);
	fp( i, 2, n ) g[i] = (i64)g[i - 1] * g[1] % mod; return n;
}
inline void NTT( int *a, int n, int opt ){
	fp( i, 0, n - 1 ) if ( i < r[i] ) swap( a[i], a[r[i]] );
	for ( int l(1); l < n; l <<= 1 )
		for ( int s(l << 1), i(0), t(n / s); i < n; i += s )
			for ( int j(i), x, y, w(0); j < i + l; ++j, w += t )
				x = a[j], y = (i64)a[j + l] * g[opt < 0 ? n - w : w] % mod,
				a[j] = inc(x + y - mod), a[j + l] = inc(x - y);
	if ( opt < 0 ) fp( i, 0, n - 1 ) a[i] = (i64)a[i] * invn % mod;
}
inline void poly_inv( int *a, int *b, int d ){
	if ( d == 1 ) return void(b[0] = Pow(a[0]));
	poly_inv(a, b, (d + 1) >> 1);
	int n = Init(d << 1); static int c[_];
	fp( i, 0, n - 1 ) c[i] = i < d ? a[i] : 0;
	NTT(b, n, 1), NTT(c, n, 1);
	fp( i, 0, n - 1 ) b[i] = (2 + mod - (i64)c[i] * b[i] % mod) * b[i] % mod;
	NTT(b, n, -1); fp( i, d, n ) b[i] = 0;
}
inline void poly_sqrt( int *a, int *b, int d ){
	if ( d == 1 ) return void(b[0] = a[0]);
	static int c[_], vb[_];
	poly_sqrt(a, b, (d + 1) >> 1);
	memset( vb, 0, sizeof vb );
	poly_inv(b, vb, d);
	int n = Init(d << 1 | 2);
	fp( i, 0, n - 1 ) c[i] = i < d ? a[i] : 0;
	NTT(c, n, 1), NTT(vb, n, 1);
	fp( i, 0, n - 1 ) c[i] = (i64)c[i] * vb[i] % mod;
	NTT(c, n, -1);
	fp( i, 0, n - 1 ) b[i] = (i64)(c[i] + b[i]) * inv2 % mod;
	fp( i, d, n ) b[i] = 0;
}

int main(){
	read(N);
	fp( i, 0, N - 1 ) read(a[i]);
	poly_sqrt(a, b, N);
	fp( i, 0, N - 1 ) printf( "%d%c", b[i], "\n "[i < N - 1] );
	return 0;
}