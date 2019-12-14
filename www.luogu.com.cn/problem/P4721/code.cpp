#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(e), I(e); i >= I; --i )
template<class T> inline bool cmax( T &x, T y ){ return x < y ? x = y, 1 : 0; }
template<class T> inline bool cmin( T &x, T y ){ return x > y ? x = y, 1 : 0; }
// #define getchar() (p1 == p2 && (p1 = bf, p2 = bf + fread(bf, 1, 1 << 21, stdin), p1 == p2 ) ? EOF : *p1++ )
char bf[1 << 21], *p1, *p2;
template<class T> inline void read( T &x ){
	x = 0; char t(getchar()), flg(0);
	while( t > 57 || t < 48 ) flg = t == '-', t = getchar();
	while( t < 58 && t > 47 ) x = x * 10 + (t & 15), t = getchar();
	flg ? x = -x : x;
}

const int _ = 4e5 + 15, mod = 998244353;
int N, n, a[_], b[_], c[_], r[_];
inline int Pow( int x, int y = mod - 2 ){ int ans(1); for ( ; y; y >>= 1, x = (i64)x * x % mod ) if ( y & 1 ) ans = (i64)ans * x % mod; return ans; }
inline int dec( int x ){ return x >= mod ? x - mod : x; }

void NTT( int *a, int n, int opt ){
	int o = opt < 0 ? (mod + 1) / 3 : 3;
	fp( i, 0, n - 1 ) if ( i < r[i] ) swap( a[i], a[r[i]] );
	for ( int l = 1; l < n; l <<= 1 ){
		int s = l << 1, pn = Pow(o, (mod + 1) / s);
		for ( int i = 0; i < n; i += s )
			for ( int j = i, x, y, w(1); j < i + l; ++j, w = (i64)w * pn % mod )
				x = a[j], y = (i64)a[j + l] * w % mod,
				a[j] = dec(x + y), a[j + l] = dec(x - y + mod);
	} for ( int i = 0, t = Pow(n); i < n; ++i ) a[i] = (i64)a[i] * t % mod;
}

void work( int *a, int *b, int d ){
	if ( d == 1 ) return void(b[0] = Pow(a[0]));
	work(a, b, (d + 1) >> 1);
	int n(1), w(0); while( n < (d << 1) ) n <<= 1, ++w;
	fp( i, 0, n - 1 ) r[i] = ( r[i >> 1] >> 1 ) | ( (i & 1) << w ), c[i] = i < d ? a[i] : 0;
	NTT(c, n, 1), NTT(b, n, 1); fp( i, 0, n - 1 ) b[i] *= c[i]; NTT(b, n, -1);
	fp( i, d + 1, n - 1 ) b[i] = 0;
}

int main(){
	read(N);
	fp( i, 0, N - 1 ) read(a[i]);
	work(a, b, N);
	fp( i, 0, N - 1 ) printf( "%d%c", b[i], "\n "[i < N - 1] );
	return 0;
}