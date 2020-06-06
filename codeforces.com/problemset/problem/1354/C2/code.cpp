#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define open(s) freopen( s".in", "r", stdin ), freopen( s".out", "w", stdout )
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline bool cmax( T &x, T y ){ return x < y ? x = y, 1 : 0; }
template<typename T> inline bool cmin( T &x, T y ){ return y < x ? x = y, 1 : 0; }
#define pi 3.14159265358979323846

int T, N; double t;

int main(){
	scanf( "%d", &T );
	while( T-- ){
		scanf( "%d", &N );
		printf( "%.8lf\n", 1 / sin(pi / (N << 1)) * cos((pi * .5 - (N >> 1) * pi / N) * .5) );
	}
	return 0;
}