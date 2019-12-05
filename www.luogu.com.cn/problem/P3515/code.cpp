#include<bits/stdc++.h>
using namespace std;
#define i64 long long
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

const int MAXN = 5e5 + 5;
int N, a[MAXN]; double ans[MAXN], sq[MAXN];
int q[MAXN], hd, tl, s[MAXN];

inline double calc( int i, int j ){ return a[j] + sq[i - j]; }
inline int EF( int j1, int j2 ){
	int l(j2), r(N), mid, ans(N + 1);
	while ( l <= r ){
		mid = ( l + r ) >> 1;
		if ( calc(mid, j1) < calc(mid, j2) ) ans = mid, r = mid - 1;
		else l = mid + 1;
	} return ans;
}
inline void work(){
	q[hd = tl = 1] = 1;
	fp( i, 2, N ){
		while( hd < tl && s[hd] <= i ) ++hd;
		cmax( ans[i], calc(i, q[hd]) - a[i] );
		while( hd < tl && s[tl - 1] > EF(q[tl], i) ) --tl;
		s[tl] = EF(q[tl], i), q[++tl] = i;
	}
}

signed main(){
	read(N); fp( i, 1, N ) read(a[i]);
	fp( i, 1, N ) sq[i] = sqrt(i);
	work();
	fp( i, 1, N >> 1 ) swap( a[i], a[N - i + 1] ), swap( ans[i], ans[N - i + 1] );
	work();
	fd( i, N, 1 ) printf( "%d\n", (int)ceil(ans[i]) );
	return 0;
}

