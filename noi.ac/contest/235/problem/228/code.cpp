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

const int MAXN = 1e6 + 15;
int N, p, q, x, y, c, s[MAXN]; char str[MAXN];
int mn[MAXN], o; i64 ans(1e18);

signed main(){
	scanf( "%d%d%d%d%d", &N, &p, &q, &x, &y );
	while( (str[1] = getchar()) != '+' && str[1] != '-' );
	fread( str + 2, 1, N - 1, stdin ); fp( i, 1, N ) s[i] = s[i - 1] + ( str[i] == '+' ? 1 : -1 );
	mn[N] = s[N]; fd( i, N - 1, 1 ) mn[i] = min( mn[i + 1], s[i] );
	fp( i, 1, N ){
		o = max( 0, -min(mn[i] - s[i - 1], s[N] - s[i - 1] + c) - p ); if ( o & 1 ) ++o;
		cmin( ans, ( ((i64)abs(p + o + s[N] - q) >> 1) + (o >> 1) ) * x + (i64)(i - 1) * y ); cmin( c, mn[i] );
	} printf( "%lld\n", ans );
	return 0;
}
