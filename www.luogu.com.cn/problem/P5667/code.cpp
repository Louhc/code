#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define open(s) freopen( s".in", "r", stdin ), freopen( s".out", "w", stdout )
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline bool cmax( T &x, T y ){ return x < y ? x = y, 1 : 0; }
template<typename T> inline bool cmin( T &x, T y ){ return y < x ? x = y, 1 : 0; }

int n, m;
inline int Pow( int x, int y ){ int ans(1); for ( ; y; y >>= 1, x = (i64)x * x % mod ) if ( y & 1 ) ans = (i64)ans * x % mod; return ans; }
char vis[_]; int p[_], tot, f[_];

void Init( int m ){
	f[1] = 1;
	for ( int i = 2; i <= m; ++i ){
		if ( !vis[i] ) p[++n] = i, f[i] = Pow(i, N);
		for ( int j = 1; i * p[j] <= m && j <= n; ++j ){
			vis[i * p[j]] = 1, f[i * p[j]] = f[i] * f[p[j]];
			if ( i % p[j] == 0 ) break;
		}
	}
	
}

int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	return 0;
}

