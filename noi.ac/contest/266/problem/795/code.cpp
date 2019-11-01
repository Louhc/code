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

const int MAXN = 5e5 + 15;
int N, M; i64 b[MAXN];
struct node{
	i64 a, b;
	bool operator < ( const node &t )const{ return b < t.b; }
}a[MAXN];

i64 tr[MAXN << 2]; int s[MAXN << 2];
void Ins( int c, int l, int r, int x, i64 y ){
	++s[c], tr[c] += y;
	if ( l == r ) return;
	const int ls(c << 1), rs(ls | 1), mid((l + r) >> 1);
	x <= mid ? Ins( ls, l, mid, x, y ) : Ins( rs, mid + 1, r, x, y );
}
int Query( int c, int l, int r, i64 k ){
	if ( tr[c] < k ) return N + 1;
	if ( k == 0 ) return 0;
	if ( l == r ) return ( k - 1 ) / b[l] + 1;
	const int mid((l + r) >> 1), ls(c << 1), rs(ls | 1);
	if ( tr[rs] >= k ) return Query( rs, mid + 1, r, k );
	return s[rs] + Query( ls, l, mid, k - tr[rs] );
}

signed main(){
	read(N);
	fp( i, 1, N ) read(a[i].a), read(a[i].b), a[i].b += a[i].a, b[i] = a[i].a;
	sort( a + 1, a + N + 1 ); int ans(N + 1);
	sort( b + 1, b + N + 1 ), M = unique( b + 1, b + N + 1 ) - b - 1;
	fp( i, 1, N ){
		Ins(1, 1, M, lower_bound( b + 1, b + M + 1, a[i].a ) - b, a[i].a );
		cmin( ans, Query( 1, 1, M, a[i].b ) );
	} printf( "%d\n", ans > N ? -1 : ans );
	return 0;
}

