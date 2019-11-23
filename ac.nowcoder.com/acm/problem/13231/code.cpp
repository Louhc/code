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


const int MAXN = 50005;
int N;
double v, u, c[MAXN], d[MAXN], ans;

signed main(){
	scanf( "%d%lf%lf", &N, &v, &u );
	fp( i, 1, N ) scanf( "%lf", c + i ), c[i] -= v;
	fp( i, 1, N ) scanf( "%lf", d + i );
	fp( i, 1, N ) fp( j, 0, N - 1 ) ans += u / (c[i] - j * d[i]);
	printf( "%.3lf\n", ans );
	return 0;
}