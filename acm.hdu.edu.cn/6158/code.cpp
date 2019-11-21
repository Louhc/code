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

int T, N;
double R, R1, R2, l1, l2, ans, t, l;
double x, y, r, d;
inline double area( double r ){ return r * r * 3.14159265358979323846; }

signed main(){
	cin >> T;
	while( T-- ){
		cin >> R1 >> R2 >> N;
		if ( R1 > R2 ) swap( R1, R2 );
		l1 = R = R1 * 2, l2 = R * R / (R2 * 2);
		ans = area(R2 - R1),
		x = (l1 + l2) / 2, y = 0, d = l1 - l2, r = d / 2;
		fp( i, 1, N / 2 ){
			y += d, l = sqrt(x * x + y * y);
			t = area((R * R / (l - r) - R * R / (l + r)) / 2);
			ans += t; if ( i * 2 < N ) ans += t;
			if ( t * (N - i * 2) < 5e-7 ) break;
		} printf( "%.5lf\n", ans );
	}
	return 0;
}
