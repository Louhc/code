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

int N, a[105][105][105];
int p[105], pn, q[105], qn, r[105], rn;
int vp[105], vq[105], vr[105];

signed main(){
	read(N);
	fp( i, 1, N ) fp( j, 1, N ) fp( k, 1, N ){
		while( (a[i][j][k] = getchar()) != '0' && a[i][j][k] != '1' );
		a[i][j][k] &= 1;
		if ( !a[i][j][k] ){
			if ( !vp[i] ) p[++pn] = i, vp[i] = 1;
			if ( !vq[j] ) q[++qn] = j, vq[j] = 1;
			if ( !vr[k] ) r[++rn] = k, vr[k] = 1;
		}
	}
	fp( i, 1, N ){
		if ( !vp[i] ) p[++pn] = i;
		if ( !vq[i] ) q[++qn] = i;
		if ( !vr[i] ) r[++rn] = i;
	}
	fp( i, 1, N ) printf( "%d%c", p[i], "\n "[i < N] );
	fp( i, 1, N ) printf( "%d%c", q[i], "\n "[i < N] );
	fp( i, 1, N ) printf( "%d%c", r[i], "\n "[i < N] );
	return 0;
}
