#include<bits/stdc++.h>
using namespace std;
#define fp(i, b, e) for ( int i = b, I = e; i <= I; ++i )
#define fd(i, b, e) for ( int i = b, I = e; i >= I; --i )
#define go(i, b) for ( int i = b, v = to[b]; i; v = to[i = nxt[i]] )
#define i64 long long
inline bool cmin( int &x, int y ){ return x > y ? x = y, 1 : 0; }
inline bool cmax( int &x, int y ){ return x < y ? x = y, 1 : 0; }

const int _ = 5055, mod = 998244353;
int N, fac[_], inv[_];
int f[_][_];
int ans[_];

inline int dec( int x ){ return x >= mod ? x - mod : x; }
inline int Pow( int x, int y = mod - 2 ){
	int ans(1); for ( ; y; y >>= 1, x = (i64)x * x % mod ) if ( y & 1 ) ans = (i64)ans * x % mod; return ans;
}

int main(){
	cin >> N;
	fac[0] = fac[1] = inv[0] = 1;
	fp( i, 2, N ) fac[i] = 1ll * fac[i - 1] * i % mod;
	inv[N] = Pow(fac[N]);
	fd( i, N, 2 ) inv[i - 1] = 1ll * inv[i] * i % mod;
	f[0][0] = 1;
	fp( i, 1, N ) fp( j, 1, i ) f[i][j] = (1ll * f[i - 1][j] * j + 1ll * f[i - 1][j - 1] * (i - j + 1)) % mod;
	fp( i, 1, N ) fp( j, 1, N ) ans[j] = (ans[j] + 1ll * f[i][j] * inv[i]) % mod;
	fp( i, 1, N ) cout << 1ll * ans[i] * fac[N] % mod << " ";
	return 0;
}