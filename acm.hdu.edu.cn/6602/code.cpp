#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define open(s) freopen( s".in", "r", stdin ), freopen( s".out", "w", stdout )
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline bool cmax( T &x, T y ){ return x < y ? x = y, 1 : 0; }
template<typename T> inline bool cmin( T &x, T y ){ return y < x ? x = y, 1 : 0; }

const int _ = 1e5 + 55;
int N, C, K, ans;
int a[_], ls[_], nx[_], s[_], p[_];
int tr[_<<2], tg[_<<2];

void tag( int c, int x ){
	tg[c] += x, tr[c] += x;
}

void pushdown( int c ){
	if ( !tg[c] ) return;
	const int ls(c << 1), rs(ls | 1);
	tag(ls, tg[c]), tag(rs, tg[c]), tg[c] = 0;
}

void Add( int c, int l, int r, int L, int R, int x ){
	if ( l > R || L > r || L > R ) return;
	if ( L <= l && r <= R ) return tag(c, x);
	const int mid = (l + r) >> 1, ls = c << 1, rs = ls | 1;
	pushdown(c);
	Add(ls, l, mid, L, R, x), Add(rs, mid + 1, r, L, R, x);
	tr[c] = min(tr[ls], tr[rs]);
}

int Get( int c, int l, int r ){
	if ( l == r ) return l;
	const int mid = (l + r) >> 1, ls = c << 1, rs = ls | 1;
	pushdown(c);
	return tr[ls] == 0 ? Get(ls, l, mid) : Get(rs, mid + 1, r);
}

int main(){
	while( ~scanf( "%d%d%d", &N, &C, &K ) ){
		fp( i, 1, N ) scanf( "%d", a + i );
		ans = 0;
		memset(tr, 0, sizeof tr), memset(tg, 0, sizeof tg);
		memset(s, 0, sizeof s), memset(ls, 0, sizeof ls),
		memset(nx, 0, sizeof nx), memset(s, 0, sizeof s), memset(p, 0, sizeof p);
		fp( i, 1, N ){
			if ( !s[a[i]] ) p[a[i]] = i;
			Add( 1, 1, N, ls[a[i]] + 1, i, 1 ), ++s[a[i]];
			if ( s[a[i]] == K ){
				Add( 1, 1, N, 1, p[a[i]], -1 );
			} else if ( s[a[i]] > K ){
				Add( 1, 1, N, p[a[i]] + 1, nx[p[a[i]]], -1 ), p[a[i]] = nx[p[a[i]]];
			}
			nx[ls[a[i]]] = i, ls[a[i]] = i, nx[0] = 0;
			if ( tr[1] == 0 ) cmax(ans, i - Get(1, 1, N) + 1);
		} printf( "%d\n", ans );
	}
	return 0;
}
