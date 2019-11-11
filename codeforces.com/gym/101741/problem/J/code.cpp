#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define open(s) freopen( s".in", "r", stdin ), freopen( s".out", "w", stdout )
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define getchar() ( p1 == p2 && ( p1 = bf, p2 = bf + fread( bf, 1, 1 << 21, stdin ), p1 == p2 ) ? EOF : *p1++ )
char bf[1 << 21], *p1, *p2;
template<class T> inline void read( T &x ){
	x = 0; char t(getchar()), flg(0);
	while( t < 48 || t > 57 ) flg = t == '-', t = getchar();
	while( t > 47 && t < 58 ) x = x * 10 + (t & 15), t = getchar();
	flg ? x = -x : x;
}

const int MAXN = 2e5 + 15, mod = 1e9 + 7;
int N, M, Q, a[MAXN], ans[MAXN]; vector<int> v;
int q[MAXN][2], f[MAXN][20];
inline int dec( int x ){ return x >= mod ? x - mod : x; }
inline int dc( int x ){ return x >= M ? x - M : x; }

void CDQ( int l, int r, vector<int> v ){
	if ( l == r ){ for ( int i : v ) ans[i] = 1 + (a[l] == 0); return; }
	fp( i, l, r ) memset( f[i], 0, 80 );
	const int mid((l + r) >> 1);
	++f[mid][0];
	fp( i, mid + 1, r ) fp( j, 0, M - 1 ) f[i][j] = dec(f[i - 1][j] + f[i - 1][dc(j + a[i])]);
	++f[mid][dc(M - a[mid])];
	fd( i, mid - 1, l ) fp( j, 0, M - 1 ) f[i][j] = dec(f[i + 1][j] + f[i + 1][dc(j + a[i])]);
	vector<int> L, R;
	for ( int i : v ){
		if ( q[i][0] <= mid && q[i][1] > mid ){
			ans[i] = (i64)f[q[i][0]][0] * f[q[i][1]][0] % mod;
			fp( j, 1, M - 1 ) ans[i] = ( ans[i] + (i64)f[q[i][0]][j] * f[q[i][1]][M - j] ) % mod;
		} else if ( q[i][1] <= mid ) L.push_back(i); else R.push_back(i);
	} if ( L.size() ) CDQ( l, mid, L ); if ( R.size() ) CDQ( mid + 1, r, R );
}

int main(){
	read(N), read(M);
	fp( i, 1, N ) read(a[i]), a[i] %= M;
	read(Q);
	fp( i, 1, Q ) read(q[i][0]), read(q[i][1]), v.push_back(i);
	CDQ( 1, N, v );
	fp( i, 1, Q ) printf( "%d\n", ans[i] );
	return 0;
}
