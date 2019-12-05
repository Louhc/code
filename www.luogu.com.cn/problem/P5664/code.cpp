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

const int mod = 998244353;
int N, M, a[105][2005], s[105];
int f[105][205], ans, t(1);
inline int dec( int x ){ return x >= mod ? x - mod : x; }

signed main(){
	read(N), read(M);
	fp( i, 1, N ) fp( j, 1, M ) read(a[i][j]), s[i] = dec(s[i] + a[i][j]);
	fp( k, 1, M ){
		memset( f, 0, sizeof f ), f[0][N] = 1;
		fp( i, 1, N ) fp( j, N - i, N + i )
			f[i][j] = ( f[i - 1][j] + ( j ? (i64)f[i - 1][j - 1] * a[i][k] : 0 ) + (i64)f[i - 1][j + 1] * (s[i] - a[i][k] + mod) ) % mod;
		fp( i, N + 1, N << 1 ) ans = dec(ans + f[N][i]);
	}
	ans = mod - ans;
	fp( i, 1, N ) ans = ( ans + (i64)t * s[i] ) % mod, t = ( t + (i64)t * s[i] ) % mod;
	printf( "%d\n", (ans + mod) % mod );
	return 0;
}


