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

const int MAXN = 1e5 + 5;
int N, Q, a[MAXN], pre[MAXN << 1]; i64 ans[MAXN];
struct node{ i64 s, h, t1, t2; }tr[MAXN << 2];
struct qry{ int l, r, w; bool operator < ( const qry &t )const{ return r < t.r; } }q[MAXN];
inline void pushup( int c ){ const int ls(c << 1), rs(ls | 1); tr[c].s = max( tr[ls].s, tr[rs].s ), tr[c].h = max( tr[ls].h, tr[rs].h ); }
inline void pushdown( int c ){
	const int ls(c << 1), rs(ls | 1);
	cmax( tr[ls].h, tr[ls].s + tr[c].t2 ), cmax( tr[rs].h, tr[rs].s + tr[c].t2 );
	cmax( tr[ls].t2, tr[ls].t1 + tr[c].t2 ), cmax( tr[rs].t2, tr[rs].t1 + tr[c].t2 );
	tr[ls].s += tr[c].t1, tr[rs].s += tr[c].t1;
	tr[ls].t1 += tr[c].t1, tr[rs].t1 += tr[c].t1; tr[c].t1 = tr[c].t2 = 0;
}
void Add( int c, int l, int r, int L, int R, int x ){
	if ( L <= l && r <= R ) return cmax( tr[c].h, tr[c].s += x ), cmax( tr[c].t2, tr[c].t1 += x ), void();
	if ( L > r || l > R ) return;
	const int mid((l + r) >> 1), ls(c << 1), rs(ls | 1);
	pushdown(c), Add( ls, l, mid, L, R, x ), Add( rs, mid + 1, r, L, R, x ), pushup(c);
}
i64 Query( int c, int l, int r, int L, int R ){
	if ( L <= l && r <= R ) return tr[c].h;
	if ( L > r || l > R ) return 0;
	const int mid((l + r) >> 1), ls(c << 1), rs(ls | 1);
	pushdown(c); return max( Query( ls, l, mid, L, R ), Query( rs, mid + 1, r, L, R ) );
}

signed main(){
	read(N); fp( i, 1, N ) read(a[i]);
	read(Q); fp( i, 1, Q ) read(q[i].l), read(q[i].r), q[i].w = i;
	sort( q + 1, q + Q + 1 ); int c(1);
	fp( i, 1, Q ){
		while( c <= q[i].r ) Add( 1, 1, N, pre[a[c] + MAXN] + 1, c, a[c] ), pre[a[c] + MAXN] = c, ++c;
		ans[q[i].w] = Query( 1, 1, N, q[i].l, q[i].r );
	} fp( i, 1, Q ) printf( "%lld\n", ans[i] );
	return 0;
}

