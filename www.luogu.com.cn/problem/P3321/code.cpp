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

const int mod = 1004535809, _ = 40055;
int N, M, x, K, m, G;
int p[10005], tot;
int n, r[_], g[_], invn, a[_], b[_], c[_];

inline int Pow( int x, int y, int m = mod ){ int ans(1); for ( ; y; y >>= 1, x = (i64)x * x % m ) if ( y & 1 ) ans = (i64)ans * x % m; return ans; }
inline int inc( int x ){ return x + (x >> 31 & mod); }
inline int Init( int N ){
	int n(1), w(-1); while( n < N ) n <<= 1, ++w;
	fp( i, 0, n - 1 ) r[i] = (r[i >> 1] >> 1) | ((i & 1) << w);
	g[0] = 1, g[1] = Pow(3, (mod - 1) / n), invn = Pow(n, mod - 2);
	fp( i, 2, n ) g[i] = (i64)g[i - 1] * g[1] % mod; return n;
}
inline void NTT( int *a, int n, int opt ){
	fp( i, 0, n - 1 ) if ( i < r[i] ) swap( a[i], a[r[i]] );
	for ( int l(1); l < n; l <<= 1 )
		for ( int s(l << 1), i(0), t(n / s); i < n; i += s )
			for ( int j(i), w(0), x, y; j < i + l; ++j, w += t )
				x = a[j], y = (i64)a[j + l] * g[opt < 0 ? n - w : w] % mod,
				a[j] = inc(x + y - mod), a[j + l] = inc(x - y);
	if ( opt < 0 ) fp( i, 0, n - 1 ) a[i] = (i64)a[i] * invn % mod;
}

void poly_mul( int *a, int *b ){
	memcpy( c, b, n << 2 );
	NTT(a, n, 1), NTT(c, n, 1);
	fp( i, 0, n - 1 ) a[i] = (i64)a[i] * c[i] % mod;
	NTT(a, n, -1);
	fd( i, n - 1, m ) a[i - m] = inc(a[i - m] + a[i] - mod), a[i] = 0;
}

int main(){
	read(N), read(M), read(x), read(K), m = M - 1;
	for ( int i = 2; i * i <= m; ++i ) if ( m % i == 0 ){
		p[++tot] = i; while( m % i == 0 ) m /= i;
	} if ( m > 1 ) p[++tot] = m;
	fp( i, 2, m = M - 1 ){
		bool flg(1);
		fp( j, 1, tot ) if ( Pow(i, m / p[j], M) == 1 ){ flg = 0; break; }
		if ( flg ){ G = i; break; }
	} int t(1); p[1] = 0; fp( i, 1, M - 2 ) t = (i64)t * G % M, p[t] = i;
	x = p[x];
	fp( i, 1, K ){ read(t); if ( t % M > 0 ) ++a[p[t % M]]; }
	n = Init(m << 1), b[0] = 1;
	for ( ; N; N >>= 1, poly_mul(a, a) ) if ( N & 1 ) poly_mul(b, a);
	printf( "%d\n", b[x] );
	return 0;
}