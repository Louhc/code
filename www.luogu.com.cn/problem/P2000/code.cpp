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

const int _ = 8e5 + 66, mod = 998244353;
int n, s[_], r[_], ans[_];

inline int dec( int x ){ return x >= mod ? x - mod : x; }
inline int Pow( int x, int y = mod - 2 ){ int ans(1); for ( ; y; y >>= 1, x = (i64)x * x % mod ) if ( y & 1 ) ans = (i64)ans * x % mod; return ans; }
inline int Init( int N ){ int n(1), w(-1); while( n < N ) n <<= 1, ++w; fp( i, 1, n - 1 ) r[i] = (r[i >> 1] >> 1) | ((i & 1) << w); return n; }
inline void NTT( int *a, int n, int opt ){ int o(opt < 0 ? (mod + 1) / 3 : 3);
	fp( i, 0, n - 1 ) if ( i < r[i] ) swap(a[i], a[r[i]]);
	for ( int l(1); l < n; l <<= 1 ){
		int s(l << 1), gn(Pow(o, (mod - 1) / s));
		for ( int i(0); i < n; i += s )
			for ( int j(i), gi(1), x, y; j < i + l; ++j, gi = (i64)gi * gn % mod )
				x = a[j], y = (i64)gi * a[j + l] % mod, a[j] = dec(x + y), a[j + l] = dec(x - y + mod);
	} if ( opt < 0 ) for ( int i = 0, t = Pow(n); i < n; ++i ) a[i] = (i64)a[i] * t % mod;
}
void mul( int *a, int *b ){
	static int c[_]; memcpy( c, b, _<<2 );
	NTT(a, n, 1), NTT(c, n, 1); fp( i, 0, n - 1 ) a[i] = (i64)a[i] * c[i] % mod; NTT(a, n, -1);
	fp( i, 0, n - 1 ) a[i + 1] += a[i] / 10, a[i] %= 10;
}
void div(){
	fd( i, n - 1, 1 ) ans[i - 1] += ans[i] % 24 * 10, ans[i] /= 24;
	ans[0] /= 24;
}

int main(){
	// open("data");
	fd( i, 1e5 - 1, 0 ) s[i] = getchar() & 15;
	n = Init(4e5), ++s[0], memcpy(ans, s, sizeof s), ++s[0], mul(ans, s), ++s[0], mul(ans, s), ++s[0], mul(ans, s), div();
	while( !ans[n] ) --n; fd( i, n, 0 ) printf( "%d", ans[i] ); printf("\n");
	return 0;
}