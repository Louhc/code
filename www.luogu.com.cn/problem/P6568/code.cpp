#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define open(s) freopen( s".in", "r", stdin ), freopen( s".out", "w", stdout )
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline bool cmax( T &x, T y ){ return x < y ? x = y, 1 : 0; }
template<typename T> inline bool cmin( T &x, T y ){ return y < x ? x = y, 1 : 0; }

const int _ = 1e6 + 55;
int N, K, ans;
int a[_];

int main(){
	scanf( "%d%d", &N, &K ), ++K;
	fp( i, 1, N ) scanf( "%d", a + i ), a[i] += a[i - 1];
	fp( i, K, N ) cmax(ans, a[i] - a[i - K]);
	printf( "%d\n", ans );
	return 0;
}