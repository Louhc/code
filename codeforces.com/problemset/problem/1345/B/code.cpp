#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define open(s) freopen( s".in", "r", stdin ), freopen( s".out", "w", stdout )
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline bool cmax( T &x, T y ){ return x < y ? x = y, 1 : 0; }
template<typename T> inline bool cmin( T &x, T y ){ return y < x ? x = y, 1 : 0; }

// N * (3N + 1) / 2 = x

int T, x;
int a[100000];

i64 calc( int x ){
	return 1ll * x * (3 * x + 1) / 2;
}

int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> T;
	fp( i, 1, 26000 ) a[i] = calc(i);
	while( T-- ){
		cin >> x;
		int ans(0);
		fd( i, 26000, 1 ) while( x >= a[i] ) x -= a[i], ++ans;
		printf( "%d\n", ans );
	}
	return 0;
}