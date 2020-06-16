#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline bool cmax( T &x, T y ){ return x < y ? x = y, 1 : 0; }
template<typename T> inline bool cmin( T &x, T y ){ return y < x ? x = y, 1 : 0; }

const int _ = 1e5 + 55;
int N, Q, x, b[35], n;
int Pow( int x, int y ){ int ans(1); for ( ; y; y >>= 1, x = x * x % 10086 ) if ( y & 1 ) ans = ans * x % 10086; return ans; }

int main(){
	scanf( "%d", &N );
	fp( i, 1, N ){
		scanf( "%d", &x );
		fd( j, 30, 0 ) if ( (x >> j) & 1 ){
			if ( b[j] ) x ^= b[j];
			else{ b[j] = x, ++n; break; }
		}
	}
	scanf( "%d", &Q ); int c(0), ans(0);
	fp( i, 0, 30 ) if ( b[i] ){
		if ( ((Q >> i) & 1) ) ans |= 1 << c; ++c;
	} printf( "%d\n", ((i64)ans * Pow(2, N - n) + 1) % 10086 );
	return 0;
}
