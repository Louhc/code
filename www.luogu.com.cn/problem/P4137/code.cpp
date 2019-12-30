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

const int _ = 200055;

struct qry{
	int l, r, p;
	bool operator < ( const qry &t )const{ return r < t.r; }
}q[_];

int N, M, n, ans[_];
int a[_], b[_<<1];
int s[_<<3];

void Modify( int c, int l, int r, int x, int y ){
	if ( l == r ) return cmax(s[c], y), void();
	const int mid((l + r) >> 1), ls(c << 1), rs(ls | 1);
	x <= mid ? Modify(ls, l, mid, x, y) : Modify(rs, mid + 1, r, x, y);
	s[c] = min(s[ls], s[rs]);
}
int Query( int c, int l, int r, int x ){
	if ( l == r ) return l;
	const int mid((l + r) >> 1), ls(c << 1), rs(ls | 1);
	return s[ls] >= x ? Query(rs, mid + 1, r, x) : Query(ls, l, mid, x);
}

int main(){
	read(N),read(M), b[++n] = 0;
	fp( i, 1, N ) read(a[i]), b[++n] = a[i], b[++n] = a[i] + 1;
	sort(b + 1, b + n + 1), n = unique(b + 1, b + n + 1) - b - 1;
	fp( i, 1, N ) a[i] = lower_bound(b + 1, b + n + 1, a[i]) - b;
	fp( i, 1, M ) read(q[i].l), read(q[i].r), q[i].p = i;
	sort(q + 1, q + M + 1);
	int j(1);
	cerr << endl;
	fp( i, 1, M ){
		while( j <= q[i].r ) Modify(1, 1, n, a[j], j), ++j;
		ans[q[i].p] = b[Query(1, 1, n, q[i].l)];
	} fp( i, 1, M ) printf( "%d\n", ans[i] );
	return 0;
}