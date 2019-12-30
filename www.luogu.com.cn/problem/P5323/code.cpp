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

const int mod = 1e9 + 7, inv100 = 570000004;
int N, M, a, b, f, g;
inline int Pow( int x, int y = mod - 2 ){ int ans(1); for ( ; y; y >>= 1, x = (i64)x * x % mod ) if ( y & 1 ) ans = (i64)ans * x % mod; return ans; }

int main(){
	read(N);
	f = 1, g = 0;
	fp( i, 1, N ){
		g = (b + (i64)a * a % mod * g % mod * Pow(mod + 1 - (i64)b * g % mod)) % mod;
		read(a), read(b), a = (i64)a * inv100 % mod, b = (i64)b * inv100 % mod;
		f = (i64)f * a % mod * Pow(1 + mod - (i64)b * g % mod) % mod;
	} printf( "%d\n", f );
	return 0;
}