#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define open(s) freopen( s".in", "r", stdin ), freopen( s".out", "w", stdout )
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline bool cmax( T &x, T y ){ return x < y ? x = y, 1 : 0; }
template<typename T> inline bool cmin( T &x, T y ){ return y < x ? x = y, 1 : 0; }

const int _ = 100;
int T;
i64 N, M;

int main(){
	scanf( "%d", &T );
	while( T-- ){
		scanf( "%lld", &N );
		if ( N <= 3 ){ printf("%lld\n", N); continue; }
		M = (N - 1) / 3 - 1;
		int n = 2; i64 t;
		while( M >= (1ll << n) ) M -= 1ll << n, n += 2;
		if ( N % 3 == 1 ){ printf( "%lld\n", 1ll << n | M ); continue; }
		t = 1ll << (n + 1);
		fp( i, 1, n >> 1 ){
			switch ( (M >> ((i - 1) << 1)) & 3 ){
				case 1: t |= 2ll << ((i - 1) << 1); break;
				case 2: t |= 3ll << ((i - 1) << 1); break;
				case 3: t |= 1ll << ((i - 1) << 1); break;
			}
		}
		printf( "%lld\n", N % 3 == 0 ? t ^ (1ll << n | M) : t );
	}
	return 0;
}