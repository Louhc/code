#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define open(s) freopen( s".in", "r", stdin ), freopen( s".out", "w", stdout )
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline void cmax( T &x, T y ){ x < y ? x = y : x; }
template<typename T> inline void cmin( T &x, T y ){ y < x ? x = y : x; }

int N, s[1 << 20];
double a[1 << 20], ans;

int main(){
	scanf( "%d", &N ), N = 1 << N;
	fp( i, 0, N - 1 ) scanf( "%lf", a + i );
	for ( int l(1); l < N; l <<= 1 )
		for ( int s(l << 1), i(0); i < N; i += s )
			for ( int j(i); j < i + l; ++j )
				a[j + l] += a[j];
	fp( i, 1, --N ){
		if ( (1 - a[i ^ N]) < 1e-8 ) return printf("INF\n"), 0;
		s[i] = s[i >> 1] ^ (i & 1);
		ans += (s[i] & 1 ? 1 : -1) / (1 - a[i ^ N]);
	} printf( "%.10lf", ans );
	return 0;
}