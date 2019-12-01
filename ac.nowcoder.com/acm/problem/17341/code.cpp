#pragma GCC optimize("Ofast")
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

const int MAXN = 1e5 + 15, mod = 1e9 + 7;
int T, N, M;
int tr[MAXN<<2], tg[MAXN<<2];
int b[MAXN];
inline int Pow( int x, int y ){ int ans(1); for ( ; y; y >>= 1, x = 1ll * x * x % mod ) if ( y & 1 ) ans = 1ll * ans * x % mod; return ans; }
struct node{
	int x, y, z;
	bool operator < ( const node &t )const{
		return y < t.y;
	}
}a[MAXN];

inline int dec( int x ){ return x >= mod ? x - mod : x; }
#define tag( c, x ) tr[c] = (i64)tr[c] * x % mod, tg[c] = (i64)tg[c] * x % mod
#define pushdown(c) tg[c] > 1 ? tag(ls, tg[c]), tag(rs, tg[c]), tg[c] = 1 : 1
#define pushup(c) tr[c] = dec(tr[ls] + tr[rs])

void Build( int c, int l, int r ){
	const int mid((l + r) >> 1), ls(c << 1), rs(ls | 1);
	if ( l == r ) return tr[c] = b[l] - b[l - 1], void();
	Build( ls, l, mid ), Build( rs, mid + 1, r ), tg[c] = 1, pushup(c);
}

void Modify( int c, int l, int r, int x, int y ){
	const int mid((l + r) >> 1), ls(c << 1), rs(ls | 1);
	if ( r <= x ) return tag(c, y), void();
	if ( l > x ) return;
	pushdown(c), Modify( ls, l, mid, x, y ),
	Modify( rs, mid + 1, r, x, y ), pushup(c);
}

int main(){
	read(T);
	while( T-- ){
		read(N); int x, y;
		fp( i, 1, N ) read(a[i].x), read(a[i].y), read(x), read(y), b[i] = a[i].x, a[i].z = dec(mod + 1 - 1ll * x * Pow(y, mod - 2) % mod);
		sort( b + 1, b + N + 1 ), M = unique(b + 1, b + N + 1) - b - 1;
		Build( 1, 1, M ), sort( a + 1, a + N + 1 );
		int ans(0);
		fd( i, N, 1 ){
			Modify( 1, 1, M, lower_bound(b + 1, b + M + 1, a[i].x) - b, a[i].z );
			ans = (ans + (i64)(b[M] + mod - tr[1]) * (a[i].y - a[i - 1].y)) % mod;
		} printf( "%d\n", ans );
	}
	return 0;
}