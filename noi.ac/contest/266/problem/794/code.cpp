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
// #define getchar() ( p1 == p2 && ( p1 = bf, p2 = bf + fread( bf, 1, 1 << 21, stdin ), p1 == p2 ) ? EOF : *p1++ )
char bf[1 << 21], *p1(bf), *p2(bf);
template<typename T>
inline void read( T &x ){ char t(getchar()), flg(0); x = 0;
	for ( ; !isdigit(t); t = getchar() ) flg = t == '-';
	for ( ; isdigit(t); t = getchar() ) x = x * 10 + ( t & 15 );
	flg ? x = -x : x;
}

const int MAXN = 3e5 + 15;
#define pi pair<i64, i64>
pi p[MAXN]; int c(1); i64 line, ans;
struct node{
	i64 x, l, r;
	node(){} node( i64 a, i64 b, i64 c ):x(a), l(b), r(c){}
	bool operator < ( const node &t )const{ return l == t.l ? r < t.r : l < t.l; }
}a[MAXN<<3]; int n;
void Merge(){
	const int m = n; sort( a + 1, a + m + 1 ), n = 1;
	fp( i, 2, m ){
		if ( a[i].l <= a[n].r + 1 ) cmax( a[n].r, a[i].r );
		else a[++n] = a[i];
	}
}
void MoveUp(){
	const int m = n; n = 0;
	fp( i, 1, m ){
		++a[i].l, --a[i].r;
		if ( a[i].l <= a[i].r ) a[++n] = a[i];
	}
}
int N;

signed main(){
	read(N);
	fp( i, 1, N ) read(p[i].first), read(p[i].second);
	sort( p + 1, p + N + 1 );
	while( 1 ){
		if ( !n ){
			if ( c > N ) break;
			line = p[c].first;
		} while( c <= N && p[c].first == line ) a[++n] = node(p[c].first, p[c].second, p[c].second + 1), ++c;
		Merge();
		fp( i, 1, n ) ans += (a[i].r - a[i].l + 1) >> 1;
		MoveUp(); ++line;
	} printf( "%lld\n", ans );
	return 0;
}

