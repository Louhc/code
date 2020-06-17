#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define rgt register
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline bool cmax( T &x, T y ){ return x < y ? x = y, 1 : 0; }
template<typename T> inline bool cmin( T &x, T y ){ return y < x ? x = y, 1 : 0; }
#define int long long
char bf[1 << 21], *p1 = bf, *p2 = bf;
#define getchar() ( p1 == p2 && (p1 = bf, p2 = bf + fread(bf, 1, 1 << 21, stdin), p1 == p2) ? 0 : *p1++ )
inline int read( int &x ){
	char t(getchar()); x = 0;
	while( t < '0' || t > '9' ) t = getchar();
	while( t >= '0' && t <= '9' ) x = x * 10 + (t & 15), t = getchar();
}

const int _ = 1e6 + 55, mod = 1e9 + 7;
int tr[_ << 2], dt[_ << 2]; int tg[_ << 2];

int dec( int x ){ return x >= mod ? x - mod : x; }

void Build( int c, int l, int r ){
	if ( l == r ) return dt[c] = 1, void();
	const int mid((l + r) >> 1), ls(c << 1), rs(ls | 1);
	Build( ls, l, mid ), Build( rs, mid + 1, r ), dt[c] = dt[ls] + dt[rs];
}

inline void tag( rgt int c, rgt int l, rgt int r, rgt int x ){
	tr[c] = (tr[c] + (dt[c] + 1ll * (r - l + 1) * (x - 1)) % mod * x) % mod, dt[c] = (dt[c] + 2ll * (r - l + 1) * x) % mod, tg[c] = dec(tg[c] + x);
}

inline void pushdown( rgt int c, rgt int l, rgt int r ){
	if ( !tg[c] ) return;
	const rgt int mid((l + r) >> 1), ls(c << 1), rs(ls | 1);
	tag(ls, l, mid, tg[c]), tag(rs, mid + 1, r, tg[c]), tg[c] = 0;
}

void Add( rgt int c, rgt int l, rgt int r, rgt int L, rgt int R ){
	if ( L <= l && r <= R ) return tag(c, l, r, 1);
	if ( l > R || L > r ) return;
	const rgt int mid((l + r) >> 1), ls(c << 1), rs(ls | 1);
	pushdown(c, l, r);
	Add(ls, l, mid, L, R), Add(rs, mid + 1, r, L, R);
	tr[c] = dec(tr[ls] + tr[rs]), dt[c] = dec(dt[ls] + dt[rs]);
}

int N, M, a[_], b[_], l[_];
int ans;
int hd[256], nxt[_], to[_], tot;

int EF( int x ){
	int l = 1, r = M, mid;
	while( l <= r ){
		mid = (l + r) >> 1;
		if ( b[mid] == x ) return mid;
		b[mid] <= x ? (l = mid + 1) : (r = mid - 1);
	} return -1;
}

signed main(){
	read(N);
	Build( 1, 1, N );
	fp( i, 1, N ) read(a[i]), b[i] = a[i];
	fp( t, 0, 3 ){
		fd( j, N, 1 ){
			int c((b[j] >> (t << 3)) & 255);
			nxt[++tot] = hd[c], hd[c] = tot, to[tot] = b[j];
		} int n(0);
		fp( j, 0, 255 ){
			go( k, hd[j] ) b[++n] = v;
			hd[j] = 0;
		} tot = 0;
	}
	fp( i, 1, N ) if ( b[i] != b[i - 1] ) b[++M] = b[i];
	fp( i, 1, N ) a[i] = EF(a[i]);
	fp( i, 1, N ) Add( 1, 1, N, l[a[i]] + 1, i ), l[a[i]] = i, ans = dec(ans + tr[1]);
	printf( "%d\n", ans );
	return 0;
}
