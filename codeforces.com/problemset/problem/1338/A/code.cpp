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
int T, N;
int a[_];

int main(){
	scanf( "%d", &T );
	while( T-- ){
		scanf( "%d", &N );
		fp( i, 1, N ) scanf( "%d", a + i );
		int t(a[1]), mx(0), ans(0);
		fp( i, 2, N ) cmax(mx, t - a[i]), cmax(t, a[i]);
		while( mx ) mx >>= 1, ++ans;
		printf( "%d\n", ans );
	}
	return 0;
}