#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define open(s) freopen( s".in", "r", stdin ), freopen( s".out", "w", stdout )
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline bool cmax( T &x, T y ){ return x < y ? x = y, 1 : 0; }
template<typename T> inline bool cmin( T &x, T y ){ return y < x ? x = y, 1 : 0; }

const int _ = 5e5 + 55;
int N, M, x;
int a[_]; i64 b[_], s, cur;

int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N, M = (N + 1) >> 1;
	fp( i, 1, M ) cin >> a[i], cur += a[i];
	cin >> x; cur += 1ll * (N - M) * x;
	if ( cur > 0 ) return printf("%d\n", N), 0;
	fp( i, 1, N - M ){
		cur -= x;
		s += x - a[i], b[i] = min(b[i - 1], s);
		if ( cur + b[i] > 0 ) return printf("%d\n", N - i), 0;
	} return printf("-1\n"), 0;
	return 0;
}