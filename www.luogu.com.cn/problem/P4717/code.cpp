#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(e), I(e); i >= I; --i )
template<class T> inline bool cmax( T &x, T y ){ return x < y ? x = y, 1 : 0; }
template<class T> inline bool cmin( T &x, T y ){ return x > y ? x = y, 1 : 0; }
#define getchar() (p1 == p2 && (p1 = bf, p2 = bf + fread(bf, 1, 1 << 21, stdin), p1 == p2 ) ? EOF : *p1++ )
char bf[1 << 21], *p1, *p2;
template<class T> inline void read( T &x ){
	x = 0; char t(getchar()), flg(0);
	while( t > 57 || t < 48 ) flg = t == '-', t = getchar();
	while( t < 58 && t > 47 ) x = x * 10 + (t & 15), t = getchar();
	flg ? x = -x : x;
}

const int _ = 1 << 17, mod = 998244353, inv2 = (mod + 1) >> 1;
int N, n, A[_], B[_], a[_], b[_], c[_];
inline int dec( int x ){ return x >= mod ? x - mod : x; }

void FWT_or( int *a, bool opt ){
	for ( int i(1); i < N; i <<= 1 ) for ( int j(0), sj(i << 1); j < N; j += sj ) for ( int k(j); k < j + i; ++k )
		a[k + i] = dec(opt ? (a[k + i] + mod - a[k]) : (a[k + i] + a[k]));
}

void FWT_and( int *a, bool opt ){
	for ( int i(1); i < N; i <<= 1 ) for ( int j(0), sj(i << 1); j < N; j += sj ) for ( int k(j); k < j + i; ++k )
		a[k] = dec(opt ? (a[k] + mod - a[k + i]) : (a[k] + a[k + i]));
}

void FWT_xor( int *a, bool opt ){ int X, Y;
	for ( int i(1); i < N; i <<= 1 ) for ( int j(0), sj(i << 1); j < N; j += sj ) for ( int k(j); k < j + i; ++k )
		X = a[k], Y = a[k + i], a[k] = dec(X + Y), a[k + i] = dec(X + mod - Y),
		opt ? a[k] = (i64)a[k] * inv2 % mod, a[k + i] = (i64)a[k + i] * inv2 % mod : 1;
}

template<class Func> void work( Func FWT ){
	memcpy(a, A, N<<2), memcpy(b, B, N<<2), FWT(a, 0), FWT(b, 0);
	fp( i, 0, N - 1 ) c[i] = (i64)a[i] * b[i] % mod;
	FWT(c, 1); fp( i, 0, N - 1 ) printf( "%d%c", c[i], "\n "[i < N - 1] );
}
	
int main(){
	read(n), N = 1 << n;
    fp( i, 0, N - 1 ) read(A[i]);
	fp( i, 0, N - 1 ) read(B[i]);
    work(FWT_or), work(FWT_and), work(FWT_xor);
	return 0;
}