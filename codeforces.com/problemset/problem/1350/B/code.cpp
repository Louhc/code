#include<bits/stdc++.h>
using namespace std;
#define fp(i, b, e) for ( int i = b, I = e; i <= I; ++i )
#define fd(i, b, e) for ( int i = b, I = e; i >= I; --i )
#define go(i, b) for ( int i = b, v = to[b]; i; v = to[i = nxt[i]] )
#define i64 long long
inline bool cmin( int &x, int y ){ return x > y ? x = y, 1 : 0; }
inline bool cmax( int &x, int y ){ return x < y ? x = y, 1 : 0; }

const int _ = 1e5 + 55;
int T, N, a[_];
int f[_];

int main(){
	scanf( "%d", &T );
	while( T-- ){
		scanf( "%d", &N );
		fp( i, 1, N ) scanf( "%d", a + i );
		int ans(1);
		fp( i, 1, N ) f[i] = 1;
		fp( i, 2, N ){
			if ( a[1] < a[i] ) cmax( f[i], f[1] + 1 );
			for ( int j = 2; j * j <= i; ++j ){
				if ( i % j == 0 ){
					if ( a[j] < a[i] ) cmax( f[i], f[j] + 1 );
					if ( a[i / j] < a[i] ) cmax( f[i], f[i / j] + 1 );
				}
			} cmax(ans, f[i]);
		} printf( "%d\n", ans );
	}
	return 0;
}