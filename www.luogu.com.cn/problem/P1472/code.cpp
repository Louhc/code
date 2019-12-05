#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline void cmax( T &x, T y ){ x < y ? x = y : x; }
template<typename T> inline void cmin( T &x, T y ){ y < x ? x = y : x; }

int N, K;
int f[105][105];
const int mod = 9901;

signed main(){
	scanf( "%d%d", &N, &K );
	if ( !(N & 1) ) return printf("0\n"), 0;
	N = N >> 1;
	fp( i, 1, K ) f[0][i] = 1;
	fp( i, 1, N ) fp( j, 1, K ) fp( k, 0, i - 1 )
		f[i][j] = (f[i][j] + f[k][j - 1] * f[i - k - 1][j - 1]) % mod;
	printf( "%d\n", ( f[N][K] + mod - f[N][K - 1] ) % mod );
	return 0;
}

