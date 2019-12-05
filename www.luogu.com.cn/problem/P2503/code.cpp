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
//#define getchar() ( p1 == p2 && ( p1 = bf, p2 = bf + fread( bf, 1, 1 << 21, stdin ), p1 == p2 ) ? EOF : *p1++ )
char bf[1 << 21], *p1(bf), *p2(bf);
template<typename T>
inline void read( T &x ){ char t(getchar()), flg(0); x = 0;
	for ( ; !isdigit(t); t = getchar() ) flg = t == '-';
	for ( ; isdigit(t); t = getchar() ) x = x * 10 + ( t & 15 );
	flg ? x = -x : x;
}

int N, M;
int a[25], b[25], s[25];
double ans(1e20);
inline double sqr( double x ){ return x * x; }
inline double calc(){
	double x(0), r(0);
	fp( i, 0, M - 1 ) x += s[i];
	x /= M;
	fp( i, 0, M - 1 ) r += sqr(x - s[i]);
	return sqrt(r / M);
}

void SA(){
	double cur(calc()), T(1e4);
	while( T > 1e-4 ){
		int x(rand() % N + 1), y((b[x] + rand() % (M - 1) + 1) % M);
		s[y] += a[x], s[b[x]] -= a[x];
		double t; cmin(ans, t = calc());
		if ( t < cur || exp((cur - t) / T) * RAND_MAX > rand() ) b[x] = y, cur = t;
		else s[y] -= a[x], s[b[x]] += a[x];
		T *= .9982;
	}
}

signed main(){
	read(N), read(M);
	fp( i, 1, N ) read(a[i]), b[i] = i % M, s[b[i]] += a[i];
	ans = calc(); while( clock() < CLOCKS_PER_SEC * .9 ) SA();
	printf( "%.2lf\n", ans );
	return 0;
}
