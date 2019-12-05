#include<bits/stdc++.h>
using namespace std;
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define getchar() ( p1 == p2 && ( p1 = bf, p2 = bf + fread( bf, 1, 1 << 21, stdin ), p1 == p2 ) ? EOF : *p1++ )
char bf[1 << 21], *p1(bf), *p2(bf);
template<typename T>
inline void read( T &x ){ char t(getchar()), flg(0); x = 0;
	for ( ; !isdigit(t); t = getchar() ) flg = t == '-';
	for ( ; isdigit(t); t = getchar() ) x = x * 10 + ( t & 15 );
	flg ? x = -x : x;
}

const int mod = 45989;
int N, M, t, A, B, n;
struct matrix{
	int a[122][122];
	matrix operator * ( matrix t ){
		matrix r; memset( r.a, 0, sizeof r.a );
		fp( i, 0, n ) fp( k, 0, n ) if ( a[i][k] ) fp( j, 0, n )
			r.a[i][j] = ( r.a[i][j] + a[i][k] * t.a[k][j] ) % mod;
		return r;
	}
}r, o;

vector<int> v1[55], v2[55];

int main(){
	read(N), read(M), read(t), read(A), read(B), n = 2 * M;
	int x, y; v2[A].push_back(n);
	fp( i, 0, M - 1 ){
		read(x), read(y);
		for ( int j : v1[x] ) ++o.a[i + M][j];
		for ( int j : v1[y] ) ++o.a[i][j];
		for ( int j : v2[x] ) ++o.a[j][i];
		for ( int j : v2[y] ) ++o.a[j][i + M];
		v1[x].push_back(i), v1[y].push_back(i + M),
		v2[x].push_back(i + M), v2[y].push_back(i);
	} r.a[n][n] = 1; for ( ; t; t >>= 1, o = o * o ) if ( t & 1 ) r = r * o;
	int ans(0); for ( int j : v2[B] ) ans += r.a[n][j];
	printf( "%d\n", ans % mod );
	return 0;
}
