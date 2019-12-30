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

inline int Pow( int x, int y, int mod ){ int ans(1); for ( ; y; y >>= 1, x = (i64)x * x % mod ) if ( y & 1 ) ans = (i64)ans * x % mod; return ans; }
const int m1 = 998244353, m2 = 1004535809, m3 = 469762049, m = 1e9 + 7;
const i64 m12 = (i64)m1 * m2;
const int _ = 1e4, inv1 = Pow(m1, m2 - 2, m2), inv2 = Pow(m12 % m3, m3 - 2, m3);
struct Int{
	int a, b, c;
	inline Int( int x, int y, int z ):a(x), b(y), c(z){}
	inline Int( int x = 0 ):a(x), b(x), c(x){}
	inline Int inc( Int t ){ return Int(t.a + (t.a >> 31 & m1), t.b + (t.b >> 31 & m2), t.c + (t.c >> 31 & m3)); }
	inline Int operator + ( Int t ){ return inc(Int(a + t.a - m1, b + t.b - m2, c + t.c - m3)); }
	inline Int operator - ( Int t ){ return inc(Int(a - t.a, b - t.b, c - t.c)); }
	inline Int operator * ( Int t ){ return Int((i64)a * t.a % m1, (i64)b * t.b % m2, (i64)c * t.c % m3); }
	inline int get(){
		const i64 x = (i64)(b - a + m2) * inv1 % m2 * m1 + a;
		return ((c - x % m3 + m3) * inv2 % m3 * (m12 % m) + x) % m;
	}
};


int r[_]; Int gn[_], invn, x, y;
inline int Init( int N ){
	int n(1), w(-1); while( n < N ) n <<= 1, ++w;
	fp( i, 1, n - 1 ) r[i] = (r[i >> 1] >> 1) | ((i & 1) << w);
	gn[0] = Int(1), invn = Int(Pow(n, m1 - 2, m1), Pow(n, m2 - 2, m2), Pow(n, m3 - 2, m3)),
	gn[1] = Int(Pow(3, (m1 - 1) / n, m1), Pow(3, (m2 - 1) / n, m2), Pow(3, (m3 - 1) / n, m3));
	fp( i, 2, n ) gn[i] = gn[i - 1] * gn[1];
	return n;
}
inline void NTT( Int *a, int n, int opt ){
	fp( i, 0, n - 1 ) if ( i < r[i] ) swap( a[i], a[r[i]] );
	for ( int l(1); l < n; l <<= 1 )
		for ( int s(l << 1), t(n / s), i(0); i < n; i += s )
			for ( int j(i), k(0); j < i + l; ++j, k += t )
				x = a[j], y = a[j + l] * (opt > 0 ? gn[k] : gn[n - k]),
				a[j] = x + y, a[j + l] = x - y;
	if ( opt < 0 ) fp( i, 0, n - 1 ) a[i] = a[i] * invn;
}

int N, M, n;
Int a[_], b[_], c[_];
void mul( Int *a, Int *b ){
	fp( i, 0, n - 1 ) a[i] = a[i] * b[i]; NTT(a, n, -1);
	fp( i, N, n - 1 ) a[i % N] = a[i % N] + a[i], a[i] = Int(0);
	fp( i, 0, n - 1 ) a[i] = Int(a[i].get());
}

int main(){
	read(N), read(M), a[1] = Int(1), a[N - 1] = b[0] = Int(1), n = Init(N << 1);
	for ( ; M; M >>= 1, NTT(a, n, 1), mul(a, a) ) if ( M & 1 ) memcpy(c, a, sizeof c), NTT(c, n, 1), NTT(b, n, 1), mul(b, c);
	printf( "%d\n", b[0].a );
	return 0;
}