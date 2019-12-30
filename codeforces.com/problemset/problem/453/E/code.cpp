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

const int _ = 4e5, mod = 998244353;
int r[_], g[_], invn;
inline int inc( int x ){ return x + (x >> 31 & mod); }
inline int Pow( int x, int y = mod - 2 ){ int ans(1); for ( ; y; y >>= 1, x = (i64)x * x % mod ) if ( y & 1 ) ans = (i64)ans * x % mod; return ans; }
inline int Init( int N ){
	int w(-1), n(1); while( n < N ) n <<= 1, ++w;
	fp( i, 0, n - 1 ) r[i] = (r[i >> 1] >> 1) | ((i & 1) << w);
	g[0] = 1, g[1] = Pow(3, (mod - 1) / n), invn = Pow(n);
	fp( i, 2, n ) g[i] = (i64)g[i - 1] * g[1] % mod;
	return n;
}
inline void NTT( int *a, int n, int opt ){
	fp( i, 0, n - 1 ) if ( i < r[i] ) swap( a[i], a[r[i]] );
	for ( int l(1); l < n; l <<= 1 )
		for ( int s(l << 1), i(0), t((mod - 1) / s); i < n; i += l )
			for ( int j = i, x, y, w(0); j < i + l; ++j, w += t )
				x = a[j], y = (i64)a[j + l] * g[opt < 0 ? n - w : w] % mod,
				a[j] = inc(x + y - mod), a[j + l] = inc(x - y);
	if ( opt < 0 ) fp( i, 0, n - 1 ) a[i] = (i64)a[i] * invn % mod;
}

int N, M, n, ans(1), x;
int a[_], b[_], c[_];

void mul( int *a, int *b ){
	fp( i, 0, n - 1 ) a[i] = (i64)a[i] * b[i] % mod;
	NTT(a, n, -1);
}

int main(){
	open("data");
	read(N), read(M), n = Init(M << 1 | 1);
	fp( i, 1, N ) read(x), ++a[x];
	fp( i, 0, N ) printf( "%d\n", a[i] );
	return 0;
}