#include<cstdio>
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

int N;
int f[100], g[100];

signed main(){
	f[1] = g[1] = 1;
	printf( "1\n" );
	fp( i, 2, 12 ){
		f[i] = f[i - 1] << 1 | 1, g[i] = 1e9;
		fp( j, 1, i - 1 ) cmin( g[i], (g[j] << 1) + f[i - j] );
		printf( "%d\n", g[i] );
	}
	return 0;
}


