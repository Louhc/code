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

const int _ = 1 << 20, mod = 998244353;
int N, n, f[_], g[_];
i64 s[_];

inline int dec( int x ){ return x >= mod ? x - mod : x; }

signed main(){
	cin >> N, n = (1 << N) - 1, g[0] = 1;
	fp( i, 0, N - 1 ) cin >> s[1 << i], f[1 << i] = 1;
	fp( i, 0, n ) s[i] = s[i & -i] + s[i ^ (i & -i)];
	fp( i, 1, n ){
		if ( s[i] < 0 ){ fp( j, 0, N - 1 ) if ( (i >> j) & 1 ) g[i] = dec(g[i] + g[i ^ (1 << j)]); }
		else{ fp( j, 0, N - 1 ) if ( ~(i >> j) & 1 ) f[i | (1 << j)] = dec(f[i | (1 << j)] + f[i]); }
	} int ans(0); fp( i, 1, n ) ans = (ans + s[i] % mod * f[i] % mod * g[n ^ i] ) % mod;
	printf( "%d\n", (ans + mod) % mod );
	return 0;
}
