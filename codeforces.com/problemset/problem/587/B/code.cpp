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

const int MAXN = 1e6 + 5, mod = 1e9 + 7;
int N, K, n, s[MAXN], f[MAXN]; i64 L;
int a[MAXN], b[MAXN], ans;
inline int dec( int x ){ return x >= mod ? x - mod : x; }

signed main(){
	read(N), read(L), read(K);
	fp( i, 1, N ) read(a[i]), b[i] = a[i];
	sort( b + 1, b + N + 1 ), n = unique( b + 1, b + N + 1 ) - b - 1;
	fp( i, 1, N ) a[i] = lower_bound( b + 1, b + n + 1, a[i] ) - b, f[i] = 1;
	fp( i, 1, min( (i64)K, (L - 1) / N + 1 ) ){
		fp( j, 1, N ) if ( N * (i - 1) + j <= L ) ans = ( ans + ((L - N * (i - 1) - j) / N + 1) % mod * f[j] ) % mod;
		fp( j, 1, N ) s[a[j]] = dec(s[a[j]] + f[j]), f[j] = 0;
		fp( j, 1, n ) s[j] = dec(s[j] + s[j - 1]);
		fp( j, 1, N ) f[j] = s[a[j]];
		fp( j, 1, n ) s[j] = 0;
	} printf( "%d\n", ans );
	return 0;
}
