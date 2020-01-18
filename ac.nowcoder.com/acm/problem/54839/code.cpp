#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define open(s) freopen( s".in", "r", stdin ), freopen( s".out", "w", stdout )
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline bool cmax( T &x, T y ){ return x < y ? x = y, 1 : 0; }
template<typename T> inline bool cmin( T &x, T y ){ return y < x ? x = y, 1 : 0; }

const int mod = 998244353;
i64 N, M;
int inv[5015];

inline int Pow( int x, int y ){ int ans(1); for ( ; y; y >>= 1, x = (i64)x * x % mod ) if ( y & 1 ) ans = (i64)ans * x % mod; return ans; }
inline int inc( int x ){ return x + (x >> 31 & mod); }

int calc( i64 n, int m ){
	int ans(0), s(0);
	fp( i, 1, m + 2 ){
		int t = s = inc(Pow(i, m) + s - mod);
		fp( j, 1, m + 2 ) if ( i != j ) t = (n - j + mod) % mod * (i < j ? mod - inv[j - i] : inv[i - j]) % mod * t % mod;
		ans = inc(ans + t - mod);
	} return ans;
}

signed main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> M, --N;
	inv[1] = 1; fp( i, 2, M + 3 ) inv[i] = (i64)(mod - mod / i) * inv[mod % i] % mod;
	cout << (N + 1 - (i64)calc(N, M + 1) * Pow(calc(N, M) + (M == 0), mod - 2) % mod + mod) % mod << endl;
	return 0;
}

