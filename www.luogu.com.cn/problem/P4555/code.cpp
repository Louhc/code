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

int N, ans;
char s[200055];
int r[200055], f[200055];

signed main(){
	scanf( "%s", s );
	N = strlen(s);
	fd( i, N - 1, 0 ) s[i << 1 |1] = s[i], s[i << 1] = '*'; s[0] = '@'; N <<= 1;
	int mo(0), mr(0);
	fp( i, 1, N - 1 ){
		if ( mr > i ) r[i] = min( r[(mo << 1) - i], mr - i + 1 );
		else r[i] = 1;
		while( s[i - r[i]] == s[i + r[i]] ) ++r[i];
		if ( i + r[i] - 1 > mr ) mr = i + r[i] - 1, mo = i;
	} memset( f, 0x3f, sizeof f );
	fp( i, 1, N - 1 ) r[i] += (i - r[i] == 0 || i + r[i] == N), cmin( f[i + r[i]], i );
	fd( i, N, 1 ) cmin( f[i], f[i + 1] );
	fp( i, 1, N - 1 ) cmax( ans, i - f[i - r[i] + 1] );
	printf( "%d\n", ans );
	return 0;
}

