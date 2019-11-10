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

const int MAXN = 1e5 + 15;
int T, N;
int tr[MAXN*10][2], n;
char s[20]; int ans[20];

signed main(){
	scanf( "%d", &T );
	while( T-- ){
		scanf( "%d", &N ); n = 1;
		memset( ans, 0, sizeof ans );
		fp( i, 1, N ){
			scanf( "%s", s + 1 );
			fp( j, 1, 10 ) ans[j] ^= s[j] & 1;
		} int r(0); fp( i, 1, 10 ) r += ans[i];
		printf( "%d\n", r );
	}
	return 0;
}
