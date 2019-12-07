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

const int _ = 1e5 + 15;
int T, N, n;
int p[_][2], b[_<<2], s[_<<2];

signed main(){
	read(T);
	while( T-- ){
		read(N), n = 0;
		fp( i, 1, N ) read(p[i][0]), read(p[i][1]), --p[i][1], b[++n] = p[i][0], b[++n] = p[i][1], b[++n] = p[i][1] + 1;
		sort(b + 1, b + n + 1), n = unique(b + 1, b + n + 1) - b - 1, memset(s + 1, 0, n << 2); int l(1e9), r(-1e9);
		fp( i, 1, N ){
			p[i][0] = lower_bound(b + 1, b + n + 1, p[i][0]) - b;
			p[i][1] = lower_bound(b + 1, b + n + 1, p[i][1]) - b;
			++s[p[i][0]], --s[p[i][1] + 1], cmin(l, p[i][1]), cmax(r, p[i][0]);
		} fp( i, 1, n ) s[i] += s[i - 1];
		int ans(1e9);
		fp( i, l + 1, r - 1 ) cmin(ans, s[i]);
		printf( "%d\n", ans == 1e9 ? -1 : ans );
	}
	return 0;
}


