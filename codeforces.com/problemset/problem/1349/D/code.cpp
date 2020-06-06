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
int N, M, invM, invN1;
int a[100005], f[300005];

inline int Pow( int x, int y = mod - 2 ){
	int ans(1);
	for ( ; y; y >>= 1, x = 1ll * x * x % mod ) if ( y & 1 ) ans = 1ll * ans * x % mod;
	return ans;
}

inline int dec( int x ){
	return x >= mod ? x - mod : x;
}

int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N;
	fp( i, 1, N ) cin >> a[i], M += a[i];
	invM = Pow(M), invN1 = Pow(N - 1);
	// fp( i, 1, M ) f[i] = (1ll * )
	fd( i, M, 1 ) f[i] = (1ll * (M - i) * invM % mod * f[i + 1] + 1) % mod * M % mod * (N - 1) % mod * Pow(i) % mod;
	cerr << f[0] << endl;
	fp( i, 1, M ) f[i] = dec(f[i - 1] + f[i]);
	i64 ans(0);
	fp( i, 1, N ) ans = dec(ans + f[M - a[i]]);
	cout << (ans + mod - 1ll * f[M] * (N - 1) % mod) * Pow(N) % mod;
	return 0;
}