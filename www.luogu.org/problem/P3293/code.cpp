#include<bits/stdc++.h>
using namespace std;
#if __cplusplus >= 201103L
template<class ...Args> inline int err( Args ...args ){ return fprintf( stderr, args... ); }
#else
#define err(...) 1
#endif
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

const int MAXN = 2e5 + 5, MAXM = MAXN << 5;
int N, M, n;
int a[MAXN], T[MAXN];
int s[MAXM], ls[MAXM], rs[MAXM], tot;

void Ins( int &c, int l, int r, int x ){
	const int t(++tot);
	s[t] = s[c] + 1, ls[t] = ls[c], rs[t] = rs[c], c = t;
	if ( l == r ) return;
	const int mid = ( l + r ) >> 1;
	x <= mid ? Ins( ls[c], l, mid, x ) : Ins( rs[c], mid + 1, r, x );
}
int Query( int o, int c, int l, int r, int L, int R ){
	if ( l > R || L > r || !c ) return 0;
	if ( L <= l && r <= R ) return s[c] - s[o];
	const int mid = ( l + r ) >> 1;
	return Query( ls[o], ls[c], l, mid, L, R ) + Query( rs[o], rs[c], mid + 1, r, L, R );
}

signed main(){
	read(N), read(M);
	fp( i, 1, N ) read(a[i]), cmax( n, a[i] );
	fp( i, 1, N ) T[i] = T[i - 1], Ins( T[i], 1, n, a[i] );
	while( M-- ){
		int b, x, l, r, res(0), t(0), d; read(b), read(x), read(l), read(r);
		fd( i, 17, 0 ){
			d = !(( b >> i ) & 1);
			if ( Query( T[l - 1], T[r], 1, n, t + (d << i) - x, t + ((d + 1) << i) - 1 - x ) )
				t |= d << i, res |= 1 << i;
			else t |= (!d) << i;
		} printf( "%d\n", res );
	}
	return 0;
}


