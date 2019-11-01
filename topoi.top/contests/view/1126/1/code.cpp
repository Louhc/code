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

const int MAXN = 1e5 + 5;
int N, K;
int a[15][MAXN];
int l(0), r(1e9), mid, ans;

int cnt;
void DFS( int c, int v ){
	if ( c > N ) return --cnt, void();
	fp( i, 1, a[c][0] ) if ( v + a[c][i] <= mid ){
		DFS( c + 1, v + a[c][i] ); if ( cnt <= 0 ) return;
	} else break;
}

signed main(){
	read(N), read(K);
	fp( i, 1, N ){
		read(a[i][0]);
		fp( j, 1, a[i][0] ) read(a[i][j]);
		sort( a[i] + 1, a[i] + a[i][0] + 1 );
	}
	while( l <= r ){
		mid = ( l + r ) >> 1;
		cnt = K, DFS(1, 0);
		if ( cnt > 0 ) l = mid + 1;
		else r = mid - 1, ans = mid;
	} printf( "%d\n", ans );
	return 0;
}

