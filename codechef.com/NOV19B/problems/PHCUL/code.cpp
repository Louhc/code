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

const int MAXN = 5e3 + 15;
int T, o[2], N, M, K;
int a[MAXN][2], b[MAXN][2], c[MAXN][2]; double m1[MAXN], m2[MAXN], ans;
inline i64 sqr( i64 x ){ return x * x; }
inline double dist( int *a, int *b ){ return sqrt(sqr(a[0]-b[0])+sqr(a[1]-b[1])); }

signed main(){
	read(T);
	while( T-- ){
		read(o[0]), read(o[1]), read(N), read(M), read(K), ans = 1e20;
		fp( i, 1, N ) read(a[i][0]), read(a[i][1]);
		fp( i, 1, M ) read(b[i][0]), read(b[i][1]);
		fp( i, 1, K ) read(c[i][0]), read(c[i][1]);
		fp( i, 1, M ) m1[i] = 1e20;
		fp( i, 1, M ) fp( j, 1, K ) cmin( m1[i], dist(b[i], c[j]) );
		fp( i, 1, N ) m2[i] = 1e20;
		fp( i, 1, N ) fp( j, 1, M ) cmin( m2[i], dist(a[i], b[j]) + m1[j] );
		fp( i, 1, N ) cmin( ans, dist(o, a[i]) + m2[i] );
		fp( i, 1, N ) m1[i] = 1e20;
		fp( i, 1, N ) fp( j, 1, K ) cmin( m1[i], dist(a[i], c[j]) );
		fp( i, 1, M ) m2[i] = 1e20;
		fp( i, 1, M ) fp( j, 1, N ) cmin( m2[i], dist(b[i], a[j]) + m1[j] );
		fp( i, 1, M ) cmin( ans, dist(o, b[i]) + m2[i] );
		printf( "%.10lf\n", ans );
	}
	return 0;
}
