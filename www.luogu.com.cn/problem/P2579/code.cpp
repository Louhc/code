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

const int mod = 10000;
int N, M, S, E, K, NF;

struct matrix{
	int a[55][55];
	matrix(){ memset( a, 0, sizeof a ); }
	matrix operator * ( matrix t ){
		matrix r;
		fp( i, 0, N ) fp( k, 0, N ) fp( j, 0, N )
			r.a[i][j] = ( r.a[i][j] + a[i][k] * t.a[k][j] ) % mod;
		return r;
	}
}a[13], ans;

signed main(){
	read(N), read(M), read(S), read(E), read(K), --N;
	int x, y; fp( i, 1, M ) read(x), read(y), a[1].a[x][y] = ++a[1].a[y][x];
	fp( i, 2, 12 ) a[i] = a[1];
	read(NF);
	fp( i, 1, NF ){
		int T, x; read(T);
		fp( j, 0, T - 1 ){
			read(x);
			for ( int k = j; k <= 12; k += T )
				fp( l, 0, N ) a[k].a[l][x] = 0;
		}
	} a[0] = a[1];
	fp( i, 2, 12 ) a[0] = a[0] * a[i];
	ans.a[S][S] = 1;
	for ( int i = K / 12; i; i >>= 1, a[0] = a[0] * a[0] ) if ( i & 1 ) ans = ans * a[0];
	fp( i, 1, K % 12 ) ans = ans * a[i];
	printf( "%d\n", ans.a[S][E] );
	return 0;
}
