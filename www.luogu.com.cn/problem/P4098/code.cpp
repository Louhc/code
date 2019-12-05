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
int N, ans;
int a[MAXN], b[MAXN];
int lp[MAXN], rp[MAXN];
int tr[MAXN<<6][2], sz[MAXN<<6], tot, T[MAXN];

bool cmp( int x, int y ){ return a[x] < a[y]; }
int query( int x, int l, int r ){
	int ans(0), t1(T[l]), t2(T[r]);
	fd( i, 30, 0 ){
		const int d = ( x >> i ) & 1;
		if ( sz[tr[t2][d ^ 1]] - sz[tr[t1][d ^ 1]] == 0 ) t1 = tr[t1][d], t2 = tr[t2][d];
		else ans |= 1 << i, t1 = tr[t1][d ^ 1], t2 = tr[t2][d ^ 1];
	} return ans;
}

signed main(){
	read(N), rp[N + 1] = N + 1;
	fp( i, 1, N ) read(a[i]), b[i] = i, lp[i] = i - 1, rp[i] = i + 1;
	fp( i, 1, N ){
		int t1 = T[i] = ++tot, t2 = T[i - 1]; sz[t1] = sz[t2] + 1;
		fd( j, 30, 0 ){
			const int d = (a[i] >> j) & 1;
			tr[t1][d] = ++tot, tr[t1][d ^ 1] = tr[t2][d ^ 1];
			t1 = tr[t1][d], t2 = tr[t2][d], sz[t1] = sz[t2] + 1;
		}
	} sort( b + 1, b + N + 1, cmp );
	fp( ti, 1, N ){
		const int i = b[ti];
		cmax( ans, query(a[i], lp[lp[i]], rp[i] - 1) );
		cmax( ans, query(a[i], lp[i], rp[rp[i]] - 1) );
		rp[lp[i]] = rp[i], lp[rp[i]] = lp[i];
	} printf( "%d\n", ans );
	return 0;
}

