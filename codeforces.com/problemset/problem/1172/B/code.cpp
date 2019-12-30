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

const int _ = 2e5 + 55, mod = 998244353;
int N, d[_], fac[_], ans;

int main(){
	read(N); int x, y;
	fp( i, 1, N - 1 ) read(x), read(y), ++d[x], ++d[y];
	fac[0] = 1, ans = N; fp( i, 1, N - 1 ) fac[i] =- (i64)fac[i - 1] * i % mod;
	fp( i, 1, N ) ans = (i64)ans * fac[d[i]] % mod; printf( "%d\n", ans );
	return 0;
}