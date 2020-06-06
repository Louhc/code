#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define open(s) freopen( s".in", "r", stdin ), freopen( s".out", "w", stdout )
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline bool cmax( T &x, T y ){ return x < y ? x = y, 1 : 0; }
template<typename T> inline bool cmin( T &x, T y ){ return y < x ? x = y, 1 : 0; }

const int _ = 1e5 + 55;
int T, N, a[_];

int main(){
	scanf( "%d", &T );
	while( T-- ){
		scanf( "%d", &N );
		fp( i, 1, N ) scanf( "%d", a + i );
		sort( a + 1, a + N + 1 );
		int l = (1 + N) >> 1, r = l + 1;
		while( l >= 1 && r <= N ) printf( "%d %d ", a[l--], a[r++] );
		if ( l >= 1 ) printf( "%d ", a[l--] );
		if ( r <= N ) printf( "%d ", a[r++] );
		printf("\n");
	}
	return 0;
}