#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define open(s) freopen( s".in", "r", stdin ), freopen( s".out", "w", stdout )
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline bool cmax( T &x, T y ){ return x < y ? x = y, 1 : 0; }
template<typename T> inline bool cmin( T &x, T y ){ return y < x ? x = y, 1 : 0; }

const int _ = 2e5 + 55;
int N; i64 x, cur, ans;
int a[_<<1];

i64 sum( int l, int r ){
	return (i64)(l + r) * (r - l + 1) / 2;
}

int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> x;
	fp( i, 1, N ) cin >> a[i], a[i + N] = a[i];
	int j = 1; x -= a[1], cur = sum(1, a[1]);
	fp( i, 1, N ){
		while( x >= 0 ) x -= a[++j], cur += sum(1, a[j]);
		if ( a[i] + x >= 0 ) cmax(ans, cur - sum(1, -x));
		cur -= sum(1, a[i]), x += a[i];
	} cout << ans << endl;
	return 0;
}