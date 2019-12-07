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

const int _ = 1e5 + 15, mod = 1e9 + 7;
int T, N, a, b; char t;
int fac[_], inv[_];

inline int Pow( int x, int y ){ int ans(1); for ( ; y; y >>= 1, x = (i64)x * x % mod ) if ( y & 1 ) ans = (i64)ans * x % mod; return ans; }

signed main(){
	scanf( "%d", &T ), fac[0] = 1;
	fp( i, 1, 100000 ) fac[i] = (i64)fac[i - 1] * i % mod;
	inv[100000] = Pow(fac[100000], mod - 2);
	fd( i, 100000, 1 ) inv[i - 1] = (i64)inv[i] * i % mod;
	while( T-- ){
		scanf( "%d", &N ), a = b = 0;
		while( (t = getchar()) != 48 && t != 49 ); a += t == '1';
		fp( i, 2, N ) a += getchar() == '1';
		while( (t = getchar()) != 48 && t != 49 ); b += t == '1';
		fp( i, 2, N ) b += getchar() == '1';
		int ans(0);
		for ( int i = abs(a - b), I(min(a + b, (N << 1) - a - b)); i <= I; i += 2 )
			ans = ( 1ll * fac[N] * inv[i] % mod * inv[N - i] + ans ) % mod;
		printf( "%d\n", ans );
	}
	return 0;
}


