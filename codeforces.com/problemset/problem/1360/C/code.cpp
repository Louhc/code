#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define open(s) freopen( s".in", "r", stdin ), freopen( s".out", "w", stdout )
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline bool cmax( T &x, T y ){ return x < y ? x = y, 1 : 0; }
template<typename T> inline bool cmin( T &x, T y ){ return y < x ? x = y, 1 : 0; }

const int _ = 105;
int T, N, a[_];

int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> T;
	while( T-- ){
		cin >> N; int x(0), y(0), z(0);
		fp( i, 1, N ) cin >> a[i], x ^= a[i] & 1, y ^= !(a[i] & 1);
		sort(a + 1, a + N + 1); fp( i, 1, N - 1 ) z |= a[i] + 1 == a[i + 1];
		printf( (!x && !y) || (x && y && z) ? "YES\n" : "NO\n" );
	}
	return 0;
}