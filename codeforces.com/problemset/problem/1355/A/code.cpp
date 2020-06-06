#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define open(s) freopen( s".in", "r", stdin ), freopen( s".out", "w", stdout )
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline bool cmax( T &x, T y ){ return x < y ? x = y, 1 : 0; }
template<typename T> inline bool cmin( T &x, T y ){ return y < x ? x = y, 1 : 0; }

int f( i64 x ){
	int mx(0), mn(9);
	if ( x == 0 ) return 0;
	while( x ) cmax(mx, (int)(x % 10)), cmin(mn, (int)(x % 10)), x /= 10;
	return mx * mn;
}

int T, t;
i64 x, k;

int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> T;
	while( T-- ){
		cin >> x >> k;
		while( (t = f(x)) && --k ) x += t;
		cout << x << endl;
	}
	return 0;
}