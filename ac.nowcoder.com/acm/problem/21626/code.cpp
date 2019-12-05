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

int a, b, c, d;
long double p1, p2, f1[55][2505], f2[55][2505], ans1, ans2;

signed main(){
	cin >> a >> b >> c >> d;
	if ( a * b <= c ) return printf("-1.0\n"), 0; 
	f2[0][0] = f1[0][0] = 1, p1 = 1. / b, p2 = 1. / d;
	fp( i, 0, a - 1 ) fp( j, i, i * b ) fp( k, 1, b ) f1[i + 1][j + k] += f1[i][j] * p1;
	fp( i, 0, c - 1 ) fp( j, i, i * d ) fp( k, 1, d ) f2[i + 1][j + k] += f2[i][j] * p2;	
	fp( i, 1, a * b ) f2[c][i] += f2[c][i - 1];
	fp( i, 1, a * b ) ans1 += f1[a][i] * f2[c][i - 1] * i, ans2 += f1[a][i] * f2[c][i - 1];
	printf( "%.10Lf\n", ans1 / ans2 );
	return 0;
}
