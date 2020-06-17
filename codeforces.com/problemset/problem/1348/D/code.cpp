#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline bool cmax( T &x, T y ){ return x < y ? x = y, 1 : 0; }
template<typename T> inline bool cmin( T &x, T y ){ return y < x ? x = y, 1 : 0; }

int T, N, d, a[1000], n;

int main(){
	scanf( "%d", &T );
	while( T-- ){
		scanf( "%d", &N );
		--N, n = 0, d = 2;
		while( N >= d ) a[++n] = d, N -= d, d <<= 1;
		if ( N ) a[++n] = N;
		sort(a + 1, a + n + 1 ), a[0] = 1;
		printf("%d\n", n); fp( i, 1, n ) printf( "%d%c", a[i] - a[i - 1], "\n "[i < n] ); 
	}
	return 0;
}
