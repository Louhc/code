#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define open(s) freopen( s".in", "r", stdin ), freopen( s".out", "w", stdout )
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline bool cmax( T &x, T y ){ return x < y ? x = y, 1 : 0; }
template<typename T> inline bool cmin( T &x, T y ){ return y < x ? x = y, 1 : 0; }

const int _ = 1e5 + 55;
int N;
struct node{ int s, v, l; }a[_];

bool check( double t ){
	double s(0);
	fp( i, 0, N ){
		if ( s + a[i].s > t * a[i].v ) return 0;
		s += a[i + 1].l;
	} return 1;
}

int main(){
	while( ~scanf( "%d", &N ) ){
		fp( i, 0, N ) scanf( "%d", &a[i].l );
		fp( i, 0, N ) scanf( "%d", &a[i].s );
		fp( i, 0, N ) scanf( "%d", &a[i].v );
		double l(0), r(1e9), mid;
		fp( i, 1, 100 ){
			mid = (l + r) / 2;
			if ( check(mid) ) r = mid; else l = mid;
		} printf( "%.8lf\n", l );
	}
	return 0;
}