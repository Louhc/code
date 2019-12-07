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

const int _ = 1e6 + 15, mod = 998244353;
int T, N, p, r; char t;

inline int Pow( int x, int y ){ int ans(1); for ( ; y; y >>= 1, x = (i64)x * x % mod ) if ( y & 1 ) ans = (i64)ans * x % mod; return ans; }

int calc( int n, int m ){
	int ans(1); while( m-- ) ans = (i64)ans * (n--) % mod;
	return (ans + mod) % mod;
} 

signed main(){
	cin >> T;
	while( T-- ){
		cin >> N >> p >> r;
		int ans(0);
		fp( i, 0, N )
			ans = ( ans + calc(Pow(p, i), r) ) % mod;
		fp( i, 1, r ) ans = 1ll * ans * Pow(i, mod - 2) % mod;
		printf( "%d\n", ans );
	}
	return 0;
}


