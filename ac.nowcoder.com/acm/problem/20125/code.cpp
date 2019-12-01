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

const int _ = 10015;
int n, N, M, U;
double p[_][3], f[_][14][9];

signed main(){
	scanf( "%d%d%d%d", &n, &N, &M, &U );
	fp( i, 1, n ){
		double t1, t2, t3;
		scanf( "%lf%lf%lf%lf%lf%lf", p[i], p[i] + 1, p[i] + 2, &t1, &t2, &t3 );
		p[i][0] /= t1, p[i][1] /= t2, p[i][2] /= t3, sort(p[i], p[i] + 3),
		p[i][1] += p[i][2], p[i][0] += p[i][1];
		p[i][0] = log(p[i][0]), p[i][1] = log(p[i][1]), p[i][2] = log(p[i][2]);
	} double ans(0);
	fp( i, 1, n ){
		for ( int j(0), tj(1); tj <= U; ++j, tj *= 2 )
			for ( int k(0), tk(tj); tk <= U; ++k, tk *= 3 ){
				cmax( f[i][j][k], f[i - 1][j][k] + p[i][2] );
				if ( j ) cmax( f[i][j][k], f[i - 1][j - 1][k] + p[i][1] );
				if ( k ) cmax( f[i][j][k], f[i - 1][j][k - 1] + p[i][0] );
			}
	} fp( i, 0, 13 ) fp( j, 0, 8 ) cmax( ans, f[n][i][j] );
	printf( "%.3lf\n", ans + log(M) - log(N) );
	return 0;
}


