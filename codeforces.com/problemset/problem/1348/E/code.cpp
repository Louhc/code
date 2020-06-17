#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline bool cmax( T &x, T y ){ return x < y ? x = y, 1 : 0; }
template<typename T> inline bool cmin( T &x, T y ){ return y < x ? x = y, 1 : 0; }

const int _ = 505;
int N, K, a[_], b[_];
i64 sa, sb, s, d;
bool f[_], g[_];

int main(){
	scanf( "%d%d", &N, &K );
	fp( i, 1, N ) scanf( "%d%d", a + i, b + i ), sa += a[i], sb += b[i];
	if ( (sa + sb) / K == sa / K + sb / K ) return printf( "%lld\n", (sa + sb) / K ), 0;
	f[0] = 1;
	fp( i, 1, N ){
		memcpy( g, f, sizeof g );
		fp( j, 0, K - 1 ) fp( k, K - min( K, b[i] ), min( K, a[i] ) ) f[(j + k) % K] |= g[j];
	}
	fp( i, 0, K - 1 ) if ( f[i] && (sa - i + K) % K + (sb + i) % K < K ) return printf( "%lld\n", (sa + sb) / K ), 0;
	printf( "%lld\n", sa / K + sb / K );
	return 0;
}
