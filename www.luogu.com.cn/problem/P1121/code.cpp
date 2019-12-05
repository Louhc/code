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

const int MAXN = 2e5 + 15;
int N, sum, ans, a[MAXN], f[MAXN];

inline int calc(){
	int t, h, ans(0); t = 0; fd( i, N, 1 ) f[i] = max( a[i] + t, f[i + 1] ), t = max( 0, a[i] + t );
	h = t = 0; fp( i, 1, N - 1 ) cmax( h, a[i] + t ), t = max( 0, a[i] + t ), cmax( ans, h + f[i + 1] );
	return ans;
}

signed main(){
	read(N); int c(0);
	fp( i, 1, N ) read(a[i]), sum += a[i], c += a[i] > 0;
	if ( c < 2 ){ int t1(-2e9), t2(-2e9); fp( i, 1, N ) if ( a[i] > t1 ) t2 = t1, t1 = a[i]; else if ( a[i] > t2 ) t2 = a[i]; printf( "%d\n", t1 + t2 ); return 0; }
	ans = calc(); fp( i, 1, N ) a[i] = -a[i];
	printf( "%d\n", max( ans, sum + calc() ) );
	return 0;
}
