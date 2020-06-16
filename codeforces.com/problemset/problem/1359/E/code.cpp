#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline bool cmax( T &x, T y ){ return x < y ? x = y, 1 : 0; }
template<typename T> inline bool cmin( T &x, T y ){ return y < x ? x = y, 1 : 0; }

const int _ = 5e5 + 55, mod = 998244353;
int N, M, K, f[_][20], fac[_<<1], ifac[_<<1], ans;
void add( int x, int y ){ x += y, x >= mod ? x -= mod : x; }
int Pow( int x, int y = mod - 2 ){ int ans(1); for ( ; y; y >>= 1, x = 1ll * x * x % mod ) if ( y & 1 ) ans = 1ll * ans * x % mod; return ans; }

int main(){
	cin >> N >> K; fac[0] = 1; M = N << 1;
	fp( i, 1, M ) fac[i] = (i64)fac[i - 1] * i % mod;
	ifac[M] = Pow(fac[M]);
	fd( i, M, 1 ) ifac[i - 1] = (i64)ifac[i] * i % mod;
	fp( i, 1, N ) if ( N / i >= K )ans = (ans + 1ll * fac[N / i - 1] * ifac[K - 1] % mod * ifac[N / i - K]) % mod; else break;
	printf( "%d\n", ans );
	return 0;
}
