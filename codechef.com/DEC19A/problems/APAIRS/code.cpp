#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define fp( i, b, e ) for ( int i(b), I(e); i <= e; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= e; --i )

const int mod = 1e9 + 7;
int T; i64 L, R;
int f[10][30][30][30], a[30][10], b[30][10];
// f[x][i][j][k]
// j elements < x
// j elements = x

inline int dec( int x ){ return x >= mod ? x - mod : x; }

void get( int n, int c, int t1, int t2, int x, int **a ){
	fp( i, c, n )
}

void calc( i64 x, int **a ){
	memset( a, 0, sizeof a );
	if ( !x ) return;
	int w[30], n(0), t1, t2;
	while( x ) w[++n] = x % 10, x /= 10;
	fp( i, 1, n ){
		fp( j, 0, w[i] - 1 ) fp( x, 0, 9 ){
			t1 = j > x, t2 = j == x + s[x];
			fp( k, 1, i - 1 ) t1 += w[k] > x, t2 += w[k] == x;
		}
	}
}

int main(){
	fp( x, 0, 9 ){
		f[x][0][0][0] = 1;
		fp( i, 1, 18 ) fp( j, 0, i ) fp( k, 0, i - j )
			f[x][i][j][k] = ((j ? (i64)f[x][i - 1][j - 1][k] * (9 - x) : 0) + (k ? f[x][i - 1][j][k - 1] : 0) + (i64)f[x][i - 1][j][k] * x) % mod;
	}
	cin >> T;
	while( T-- ){
		cin >> L >> R;
		calc(L - 1, a), calc(R, b);
		int ans(0);
		fp( i, 1, 18 ) fp( x, 0, 9 ) fp( j, 1, 18 ) fp( y, 0, 9 ){
			ans = dec( ans + (i64)a[i][x] * a[j][y] % mod * abs(x - y) % mod );
			ans = dec( ans + (i64)b[i][x] * b[j][y] % mod * abs(x - y) % mod );
			ans = dec( ans + mod - (i64)a[i][x] * b[j][y] % mod * abs(x - y) % mod );
			ans = dec( ans + mod - (i64)b[i][x] * a[j][y] % mod * abs(x - y) % mod );
		} printf( "%d\n", ans );
	}
	return 0;
}