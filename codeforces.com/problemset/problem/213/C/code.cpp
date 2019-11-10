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

int N, a[305][305], f[305][305][305];

signed main(){
	read(N); fp( i, 1, N ) fp( j, 1, N ) read(a[i][j]);
	fp( i, 1, N ) fp( j, 1, N ) fp( x, max( i + j - N, 1 ), min( i + j, N ) ){
		int y(i + j - x); f[i][j][x] = i == 1 && j == 1 ? 0 : -1e9;
		if ( i > 1 && x > 1 ) cmax( f[i][j][x], f[i - 1][j][x - 1] );
		if ( i > 1 && y > 1 ) cmax( f[i][j][x], f[i - 1][j][x] );
		if ( j > 1 && x > 1 ) cmax( f[i][j][x], f[i][j - 1][x - 1] );
		if ( j > 1 && y > 1 ) cmax( f[i][j][x], f[i][j - 1][x] );
		f[i][j][x] += a[i][j] + ( i == x ? 0 : a[x][y] );
	} printf( "%d\n", f[N][N][N] );
	return 0;
}
