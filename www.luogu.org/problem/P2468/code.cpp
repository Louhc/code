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

int R, C, M;

namespace solver1{
	int n, a[205][205], s[1005][205][205], v[1005][205][205];
	inline int Get( int (*a)[205], int x, int y, int xx, int yy ){
		return a[x][y] + a[xx][yy] - a[x][yy] - a[xx][y];
	}
	void solve(){
		fp( i, 1, R ) fp( j, 1, C )
			read(a[i][j]), cmax( n, a[i][j] );
		fp( k, 1, n ) fp( i, 1, R ) fp( j, 1, C )
			s[k][i][j] = s[k][i - 1][j] + s[k][i][j - 1] - s[k][i - 1][j - 1] + ( a[i][j] >= k ),
			v[k][i][j] = v[k][i - 1][j] + v[k][i][j - 1] - v[k][i - 1][j - 1] + ( a[i][j] >= k ? a[i][j] : 0 );
		int l, r, mid, x, y, xx, yy, h, res;
		while( M-- ){
			read(x), read(y), read(xx), read(yy), read(h), --x, --y;
			res = 0, l = 1, r = n;
			while( l <= r ){
				mid = ( l + r ) >> 1;
				if ( Get(v[mid], x, y, xx, yy) >= h ) res = mid, l = mid + 1;
				else r = mid - 1;
			}
			if ( res ) printf( "%d\n", Get(s[res], x, y, xx, yy) - ( Get(v[res], x, y, xx, yy) - h ) / res );
			else printf( "Poor QLW\n" );
		}
	}
}
namespace solver2{
	const int MAXN = 5e5 + 5, MAXM = 6e6;
	int n, a[MAXN];
	int T[MAXN], ls[MAXM], rs[MAXM], s[MAXM], v[MAXM], tot;
	void Ins( int o, int &c, int l, int r, int x ){
		s[c = ++tot] = s[o] + 1, v[c] = v[o] + x;
		if ( l == r ) return;
		const int mid((l + r) >> 1);
		if ( x <= mid ) Ins( ls[o], ls[c], l, mid, x ), rs[c] = rs[o];
		else Ins( rs[o], rs[c], mid + 1, r, x ), ls[c] = ls[o];
	}
	int Query( int o, int c, int l, int r, int h ){
		if ( l == r ) return ( h - 1 ) / l + 1;
		const int mid((l + r) >> 1);
		if ( v[rs[c]] - v[rs[o]] >= h ) return Query( rs[o], rs[c], mid + 1, r, h );
		return Query( ls[o], ls[c], l, mid, h - v[rs[c]] + v[rs[o]] ) + s[rs[c]] - s[rs[o]];
	}
	void solve(){
		fp( i, 1, C ) read(a[i]), cmax( n, a[i] );
		fp( i, 1, C ) Ins( T[i - 1], T[i], 1, n, a[i] );
		int x, y, h;
		while( M-- ){
			read(x), read(x), read(y), read(y), read(h), --x;
			if ( v[T[y]] - v[T[x]] < h ) printf( "Poor QLW\n" );
			else printf( "%d\n", Query( T[x], T[y], 1, n, h ) );
		}
	}
}

signed main(){
	read(R), read(C), read(M);
	if ( R > 1 ) solver1::solve(); else solver2::solve();
	return 0;
}

