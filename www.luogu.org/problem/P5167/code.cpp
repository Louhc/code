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

const int MAXN = 3e5 + 15;

inline int gcd( int x, int y ){ while( y ) x %= y, x^=y^=x^=y; return x; }
struct node{
	int x, y, z; node(){} node( int a, int b, int c ):x(a), y(b), z(c){}
	inline node operator + ( node t ){ return node( x | t.x, y & t.y, gcd( z, t.z ) ); }
	inline bool operator != ( node t ){ return x != t.x || y != t.y || z != t.z; }
	inline i64 sum(){ return (i64)x + (i64)y + (i64)z; }
}s[MAXN][19];

int T, N, K, lg[MAXN], b[MAXN], q[105], l; i64 g[105], f[MAXN];
inline node get( int l, int r ){ int w(lg[r - l + 1]); return s[l][w] + s[r - (1 << w) + 1][w]; }
inline void Merge( int x ){
	int t(0);
	fp( i, 1, l - 1 ) if ( get(q[i], x) != get(q[i + 1], x) )
		q[++t] = q[i], g[t] = g[i]; else cmax(g[i + 1], g[i]);
	q[++t] = q[l], g[t] = g[l], l = t;
}

signed main(){
	read(T); fp( i, 2, 3e5 ) lg[i] = lg[i >> 1] + 1;
	while( T-- ){
		read(N), read(K);
		fp( i, 1, N ) read(s[i][0].x), s[i][0].y = s[i][0].z = s[i][0].x;
		fp( i, 1, lg[N] ) fp( j, 1, N - (1 << i) + 1 )
			s[j][i] = s[j][i - 1] + s[j + (1 << (i - 1))][i - 1];
		l = 0; fp( i, 0, K - 1 ) read(f[i]);
		fp( i, K, N ){
			q[++l] = i - K + 1, g[l] = f[i - K], Merge(i), f[i] = -1e18;
			fp( j, 1, l ) cmax( f[i], g[j] + get(q[j], i).sum() );
		} printf( "%lld\n", f[N] );
	}
	return 0;
}
