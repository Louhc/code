#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define f80 long double
#define rgt register
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline bool cmax( T &x, T y ){ return x < y ? x = y, 1 : 0; }
template<typename T> inline bool cmin( T &x, T y ){ return y < x ? x = y, 1 : 0; }

int N, l, r, M, L, R;
double p, s, t;

signed main(){
	cin >> N >> l >> r >> M >> L >> R;
	if ( !N ) return printf( "0.00000\n" ), 0;
	fp( i, l, r ) fp( j, L, R )
		s += i != j ? 1 : 0, p += i > j ? 1 : 0;
	p /= s, s = 1, t = 0;
	fp( i, 1, N + M - 1 ){
		t = p / (1 - (1 - p) * t);
		if ( i >= N ) s *= t;
	} printf( "%.5lf\n", s );
	return 0;
}