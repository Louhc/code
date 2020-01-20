#include<cstdio>
#include<cstring>
#include<algorithm>
#define rgt register
template<typename T> inline void cmax( T &x, T y ){ x < y ? x = y : x; }
#define getchar() ( p1 == p2 && ( p1 = bf, p2 = bf + fread( bf, 1, 1 << 21, stdin ), p1 == p2 ) ? EOF : *p1++ )
char bf[1 << 21], *p1(bf), *p2(bf);
template<typename T>
inline void read( rgt T &x ){ rgt char t(getchar()); x = 0;
	for ( ; !isdigit(t); t = getchar() );
	for ( ; isdigit(t); t = getchar() ) x = x * 10 + ( t & 15 );
}
char ot[11000000]; int p(-1), stk[40], tp;
inline void print( int x ){
	while( x ) stk[++tp] = x % 10, x /= 10;
	while( tp ) ot[++p] = (stk[tp--] | 48);
	ot[++p] = ' ';
}

const int _ = 1e6 + 55;
int N, h[_], f[_], n, r[_], s[_];
char flg[_];

int main(){
	read(N);
	for ( rgt int i = 1; i <= N; ++i ) read(h[i]);
	for ( rgt int i = 1; i <= N; ++i ) f[r[i] = f[n] > h[i] ? std::upper_bound(f + 1, f + n + 1, h[i]) - f : ++n] = h[i];
	memset(f + 1, 0, n << 2);
	for ( rgt int i = N; i >= 1; --i ) if ( r[i] == n || h[i] <= f[r[i] + 1] ) flg[i] = 1, cmax(f[r[i]], h[i]), ++s[r[i]];
	for ( rgt int i = 1; i <= N; ++i ) print(n - (flg[i] && s[r[i]] < 2));
	fwrite(ot, 1, p, stdout);
	return 0;
}