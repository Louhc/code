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
#define getchar() ( p1 == p2 && ( p1 = bf, p2 = bf + fread( bf, 1, 1 << 21, stdin ), p1 == p2 ) ? EOF : *p1++ )
char bf[1 << 21], *p1(bf), *p2(bf);
template<typename T>
inline void read( T &x ){ char t(getchar()), flg(0); x = 0;
	for ( ; !isdigit(t); t = getchar() ) flg = t == '-';
	for ( ; isdigit(t); t = getchar() ) x = x * 10 + ( t & 15 );
	flg ? x = -x : x;
}

const int MAXN = 1e5 + 15;
int N, a[MAXN];
int l(1), r(300000), mid, ans;

bool check( int x ){
	int mx(a[1]), mn(a[1]), t;
	fp( i, 2, N ){
		t = max( a[i] - x + a[1] + a[i - 1] - mx, 0 ),
		mx = min( a[1] - mn, a[i] ), mn = t;
	}
	return !mn;
}

signed main(){
	read(N); fp( i, 1, N ) read(a[i]), cmax( l, a[i] + a[i - 1] );
	if ( N == 1 ) return printf( "%d\n", a[1] ), 0;
	while( l <= r ){
		mid = ( l + r ) >> 1;
		if ( check(mid) ) r = mid - 1, ans = mid;
		else l = mid + 1;
	} printf( "%d\n", ans );
	return 0;
}
