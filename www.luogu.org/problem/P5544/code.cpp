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
// #define getchar() ( p1 == p2 && ( p1 = bf, p2 = bf + fread( bf, 1, 1 << 21, stdin ), p1 == p2 ) ? EOF : *p1++ )
char bf[1 << 21], *p1(bf), *p2(bf);
template<typename T>
inline void read( T &x ){ char t(getchar()), flg(0); x = 0;
	for ( ; !isdigit(t); t = getchar() ) flg = t == '-';
	for ( ; isdigit(t); t = getchar() ) x = x * 10 + ( t & 15 );
	flg ? x = -x : x;
}

int N, M, R;
int a[20][2], ar[20], b[1015][2];
#define eps 1e-9
inline double sqr( double x ){ return x * x; }
inline double rnd(){ return 1. * rand() / RAND_MAX; }

int calc( double x, double y ){
	double r(R); int ans(0);
	fp( i, 1, N ) cmin( r, sqrt(sqr(x-a[i][0]) + sqr(y-a[i][1])) - ar[i] );
	r = sqr(r); fp( i, 1, M ) ans += sqr(x-b[i][0]) + sqr(y-b[i][1]) - eps < r;
	return ans;
}

int SA( double x, double y ){
	double T(1e8); int cur(calc(x, y)), ans(cur);
	while( T > 1e-4 ){
		double _x = x + sqrt(T) * rnd(), _y = y + sqrt(T) * rnd();
		int t(calc(_x, _y));
		if ( exp((t - cur) / T) > rnd() ) x = _x, y = _y, cmax(ans, cur = t);
		T *= .982333;
	} fp( i, 1, 1000 ) cmax(ans, calc(x + (rnd() * 2 - 1) * .01, y + (rnd() * 2 - 1) * .01));
	return ans;
}

signed main(){
	srand(time(0));
	read(N), read(M), read(R);
	fp( i, 1, N ) read(a[i][0]), read(a[i][1]), read(ar[i]);
	fp( i, 1, M ) read(b[i][0]), read(b[i][1]);
	int ans(0), t;
	while( clock() < .98 * CLOCKS_PER_SEC )
		t = rand() % M + 1, cmax( ans, SA(b[t][0], b[t][1]) );
	printf( "%d\n", ans );
	return 0;
}

