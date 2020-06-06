#include<bits/stdc++.h>
using namespace std;
inline bool cmin( int &x, int y ){ return x > y ? x = y, 1 : 0; }
inline bool cmax( int &x, int y ){ return x < y ? x = y, 1 : 0; }
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[b]); i; v = to[i = nxt[i]] )
#define i64 long long
 
const int _ = 1e5 + 55;
int N, x, mn(1e9), mx(-1e9); i64 ans(0);
int ct1, ct2;

int main(){
	scanf( "%d", &N );
	fp( i, 1, N ){
		scanf( "%d", &x ), cmin(mn, x), cmax(mx, x),
		ans += abs(x), ct1 += x > 0, ct2 += x < 0;
	}
	if ( N == 1 ) return printf( "%d\n", mx ), 0;
	else if ( N == 2 ) return printf( "%d\n", mx - mn ), 0;
	if ( ct2 == 0 ) ans -= 2ll * mn;
	else if ( ct1 == 0 ) ans += 2ll * mx;
	printf( "%lld\n", ans );
	return 0;
}