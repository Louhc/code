#include<bits/stdc++.h>
using namespace std;
#define i64 long long
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

const int mod = 998244353, _ = 4e5 + 15;

int N, M, r[_];
int f[_], g[_];
int rf[_], rg[_], ig[_];

inline int Pow( int x, int y = mod - 2 ){ int ans(1); for ( ; y; y >>= 1, x = (i64)x * x % mod ) if ( y & 1 ) ans = (i64)ans * x % mod; return ans; }
inline int dec( int x ){ return x >= mod ? x - mod : x; }
inline int Init( int N ){ int n(1), w(-1); while( n < N ) n <<= 1, ++w; fp( i, 1, n - 1 ) r[i] = (r[i >> 1] >> 1) | ((i & 1) << w); return n; }

void NTT( int *a, int n, int opt ){
	int o(opt < 0 ? (mod + 1) / 3 : 3);
	fp( i, 0, n - 1 ) if ( i < r[i] ) swap( a[i], a[r[i]] );
	for ( int l(1); l < n; l <<= 1 ){
		int s(l << 1), gn = Pow(o, (mod - 1) / s);
		for ( int i(0); i < n; i += s )
			for ( int j(i), gi(1), x, y; j < i + l; ++j, gi = (i64)gi * gn % mod )
				x = a[j], y = (i64)a[j + l] * gi % mod, a[j] = dec(x + y), a[j + l] = dec(x - y + mod);
	} if ( opt < 0 ) for ( int i(0), t(Pow(n)); i < n; ++i ) a[i] = (i64)a[i] * t % mod;
}

void work( int *a, int *b, int d ){
	if ( d == 1 ) return void(b[0] = Pow(a[0]));
	work( a, b, (d + 1) >> 1);
	int n(Init(d << 1)); static int c[_];
	fp( i, 0, n - 1 ) c[i] = i < d ? a[i] : 0;
	NTT(c, n, 1), NTT(b, n, 1); fp(i, 0, n - 1) b[i] = (2 + mod - (i64)c[i] * b[i] % mod) * b[i] % mod; NTT(b, n, -1);
	fp( i, d, n - 1 ) b[i] = 0;
}

signed main(){
	read(N), read(M);
	fp( i, 0, N ) read(f[i]), rf[N - i] = f[i];
	fp( i, 0, M ) read(g[i]), rg[M - i] = g[i];
	fp( i, N - M + 1, N ) rf[i] = 0;
	fp( i, N - M + 1, M ) rg[i] = 0;
	work(rg, ig, N - M + 1);	
	int n = Init((N - M + 1) << 1);
	NTT(ig, n, 1), NTT(rf, n, 1); fp( i, 0, n - 1 ) ig[i] = (i64)ig[i] * rf[i] % mod; NTT(ig, n, -1);
	fp( i, N - M + 1, n ) ig[i] = 0; reverse(ig, ig + N - M + 1);
	fp( i, 0, N - M ) printf( "%d ", ig[i] ); printf("\n");
	n = Init(N + 1);
	NTT(ig, n, 1), NTT(g, n, 1); fp( i, 0, n - 1 ) ig[i] = (i64)ig[i] * g[i] % mod; NTT(ig, n, -1);
	fp( i, 0, M - 1 ) printf( "%d ", dec(f[i] - ig[i] + mod) ); printf("\n");
	return 0;
}


