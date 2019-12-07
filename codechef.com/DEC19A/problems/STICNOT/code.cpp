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

const int _ = 100015;
int T, N;
int a[_], b[_];

signed main(){
	read(T);
	while( T-- ){
		read(N); int x, y;
		fp( i, 1, N - 1 ) read(x), read(y), read(b[i]);
		sort(b + 1, b + N), b[N] = b[N - 1];
		fp( i, 1, N ) read(a[i]);
		sort(a + 1, a + N + 1); int t(1); bool flg(1);
		fp( i, 1, N ){
			while( b[i] > a[t] && t <= N ) ++t;
			if ( t > N ){
				printf( "%d\n", N - i + 1 ), flg = 0; break;
			} else ++t;
		} if ( flg ) printf("0\n");
	}
	return 0;
}
