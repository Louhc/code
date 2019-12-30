#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define open(s) freopen( s".in", "r", stdin ), freopen( s".out", "w", stdout )
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline void cmax( T &x, T y ){ x < y ? x = y : x; }
template<typename T> inline void cmin( T &x, T y ){ y < x ? x = y : x; }
#define getchar() ( p1 == p2 && ( p1 = bf, p2 = bf + fread( bf, 1, 1 << 21, stdin ), p1 == p2 ) ? EOF : *p1++ )
char bf[1 << 21], *p1(bf), *p2(bf);
template<typename T>
inline void read( T &x ){ char t(getchar()), flg(0); x = 0;
        for ( ; !isdigit(t); t = getchar() ) flg = t == '-';
        for ( ; isdigit(t); t = getchar() ) x = x * 10 + ( t & 15 );
        flg ? x = -x : x;
}
struct cpl{
	double x, y;
	cpl(){} cpl( double a, double b ){ x = a, y = b; }
	cpl operator + ( cpl t ){ return cpl(x + t.x, y + t.y); }
	cpl operator - ( cpl t ){ return cpl(x - t.x, y - t.y); }
	cpl operator * ( cpl t ){ return cpl(x * t.x - y * t.y, x * t.y + y * t.x); }
	cpl operator / ( double t ){ return cpl(x / t, y / t); }
};

const double pi = 3.1415926535897932;
const int _ = 3e5 + 55;
int N, r[_];
cpl a[_], b[_], c[_], g[_];

inline int Init( int N ){
	int n(1), w(-1); while( n < N ) n <<= 1, ++w;
	fp( i, 1, n - 1 ) r[i] = (r[i >> 1] >> 1) | ((i & 1) << w);
	g[0] = cpl(1, 0), g[1] = cpl(cos(2 * pi / n), sin(2 * pi / n));
	fp( i, 2, n ) g[i] = g[i - 1] * g[1]; return n;
} cpl x, y;
inline void FFT( cpl *a, int n, int opt ){
	fp( i, 0, n - 1 ) if ( i < r[i] ) swap( a[i], a[r[i]] );
	for ( int l = 1; l < n; l <<= 1 )
		for ( int s(l << 1), i(0), t(n / s); i < n; i += s )
			for ( int j(i), w(0); j < i + l; ++j, w += t )
				x = a[j], y = a[j + l] * g[opt < 0 ? n - w : w],
				a[j] = x + y, a[j + l] = x - y;
	if ( opt < 0 ) fp( i, 0, n - 1 ) a[i] = a[i] / n;
}

int main(){
	scanf( "%d", &N );
	fp( i, 0, N - 1 ) scanf( "%lf", &a[i].x );
	memcpy(b, a, sizeof a), reverse(b, b + N);
	fp( i, 1, N - 1 ) c[i].x = 1. / ((i64)i * i);
	int n = Init(N<<1); FFT(a, n, 1), FFT(b, n, 1), FFT(c, n, 1);
	fp( i, 0, n - 1 ) a[i] = a[i] * c[i], b[i] = b[i] * c[i];
	FFT(a, n, -1), FFT(b, n, -1);
	fp( i, 0, N - 1 ) printf( "%lf\n", a[i].x - b[N - i - 1].x );
	return 0;
}