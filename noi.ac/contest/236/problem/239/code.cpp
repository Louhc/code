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
char bf[1 << 21], *p1(bf), *p2(bf);
template<typename T>
inline void read( T &x ){ char t(getchar()), flg(0); x = 0;
	for ( ; !isdigit(t); t = getchar() ) flg = t == '-';
	for ( ; isdigit(t); t = getchar() ) x = x * 10 + ( t & 15 );
	flg ? x = -x : x;
}

const int mod = 998244353;
i64 N, n, s, M, K, ans, L;
i64 fac[10000015], inv[10000015];
inline i64 Pow( i64 x, i64 y = mod - 2 ){ i64 ans(1); for ( ; y; y >>= 1, x = x * x % mod ) if ( y & 1 ) ans = ans * x % mod; return ans; }
inline i64 C( i64 x, i64 y ){
	if ( x < y || y < 0 ) return 0;
	if ( x <= L ) return fac[x] * inv[y] % mod * inv[x - y] % mod;
	i64 ans(inv[y]);
	for ( i64 i = x - y + 1; i <= x; ++i ) ans = ans * (i % mod) % mod;
	return ans;
}
inline i64 calc( i64 x ){ // 计算把x分成[1,M-1]的K个数的方案数 
	i64 ans(0);
	for ( int i = 0; i <= K; ++i )
		ans = ( ans + C( K, i ) * C(x - i * (M - 1) - 1, K - 1) % mod * ((i & 1) ? mod - 1 : 1) ) % mod;
	return ans;
}

signed main(){
	read(N), read(M), read(K), s = N / M, n = N % M;
	L = M * K, fac[0] = 1;
	fp( i, 1, L ) fac[i] = fac[i - 1] * i % mod;
	inv[L] = Pow(fac[L]);
	fd( i, L, 1 ) inv[i - 1] = inv[i] * i % mod;
	for ( i64 i = 0, I((K * (M - 1) - n) / M); i <= I; ++i )
		ans = ( ans + C(s - i + K - 1, K - 1) * calc(n + i * M) ) % mod;
	printf( "%lld\n", ans );
	return 0;
}


