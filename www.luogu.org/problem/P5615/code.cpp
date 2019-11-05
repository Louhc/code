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
template<typename T>
inline void read( T &x ){ char t(getchar()), flg(0); x = 0;
	for ( ; !isdigit(t); t = getchar() ) flg = t == '-';
	for ( ; isdigit(t); t = getchar() ) x = x * 10 + ( t & 15 );
	flg ? x = -x : x;
}

const int MAXN = 5005, mod = 1e9 + 7;
inline int Pow( int x, int y = mod - 2 ){ int ans(1); for ( ; y; y >>= 1, x = 1ll * x * x % mod ) if ( y & 1 ) ans = 1ll * ans * x % mod; return ans; }
inline int dec( int x ){ return x >= mod ? x - mod : x; }
int T, N, f[MAXN], g[MAXN], p[MAXN], res[MAXN], tf, tg;

signed main(){
	read(T), p[0] = 1;
	fp( i, 1, 4999 ){
		p[i] = dec(p[i - 1] << 1);
		fd( j, 5000, 0 ){
			tf = j < i ? p[i - 1] : f[j - i];
			tg = j < i ? i < 2 ? 0 : (int)((i64)p[i - 2] * (i - 1) % mod) : g[j - i];
			g[j] = dec(g[j] + dec(tf + tg)), f[j] = dec(f[j] + tf);
		} res[i + 1] = dec(res[i] + dec(g[i + 1] + f[i + 1]));
	} p[5000] = dec(p[4999] << 1); while( T-- ) read(N), printf( "%lld\n", 1ll * res[N] * Pow(p[N]) % mod );
	return 0;
}


