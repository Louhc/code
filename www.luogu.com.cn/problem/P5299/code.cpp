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

const int _ = 1515, mod = 998244353;
int T, N, M, K, w1[_], w2[_], C[_][_];
int f[_], g[_];
inline int dec( int x ){ return x >= mod ? x - mod : x; }
inline bool cmp( int x, int y ){ return x > y; }

signed main(){
	read(T), C[0][0] = 1;
	fp( i, 1, 1500 ){
		C[i][0] = 1; fp( j, 1, 1500 ) C[i][j] = dec(C[i - 1][j - 1] + C[i - 1][j]);
	}
	while( T-- ){
		read(N), read(M), read(K);
		fp( i, 1, N ) read(w1[i]); fp( i, 1, N ) read(w2[i]);
		sort(w1 + 1, w1 + N + 1, cmp), sort(w2 + 1, w2 + N + 1);
		memset( f, 0, sizeof f ), memset( g, 0, sizeof g ), f[0] = 1;
		fp( i, 1, N ) fd( j, min(i, M - 1), 1 )
			f[j] = j < K ? (f[j] + (i64)f[j - 1] * w1[i]) % mod : dec(f[j] + f[j - 1]);
		fp( i, 1, N ) fd( j, min(i, M), 1 )
			g[j] = (g[j] + (i64)w2[i] * C[i - 1][j - 1] + (j > M - K + 1 ? g[j - 1] : 0)) % mod;
		int ans(0); fp( i, max(0, M - N), min(N, M) ) ans = (ans + (i64)f[i] * g[M - i]) % mod;
		printf( "%d\n", ans );
	}
	return 0;
}


