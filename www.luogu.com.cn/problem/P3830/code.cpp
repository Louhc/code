#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline void cmax( T &x, T y ){ x < y ? x = y : x; }
template<typename T> inline void cmin( T &x, T y ){ y < x ? x = y : x; }

const int MAXN = 105;
int Q, N;
double f[MAXN][MAXN];

signed main(){
	scanf( "%d%d", &Q, &N );
	if ( Q & 1 ){
		double ans(0); fp( i, 2, N ) ans += 2. / i;
		return printf( "%.6lf\n", ans ), 0;
	}
	fp( i, 0, N ) f[1][i] = 1;
	fp( i, 2, N ) fp( j, 1, N ){
		fp( k, 1, i - 1 ) f[i][j] += f[k][j - 1] * f[i - k][j - 1];
		f[i][j] /= i - 1;
	} double ans(0);
	fp( i, 0, N ) ans += 1 - f[N][i];
	printf( "%.6lf\n", ans );
	return 0;
}

