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

int N, T;
int a[200], l[200];

signed main(){
	scanf( "%d", &T );
	a[1] = 0;
	fp( i, 1, 127 ){
		if ( l[a[i]] ) a[i + 1] = i - l[a[i]];
		else a[i + 1] = 0;
		l[a[i]] = i;
	}
	while( T-- ){
		scanf( "%d", &N );
		int ans(0);
		fp( i, 1, N ) ans += a[i] == a[N];
		printf( "%d\n", ans );
	}
	return 0;
}
