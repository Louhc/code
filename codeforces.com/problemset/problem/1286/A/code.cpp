#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline bool cmax( T &x, T y ){ return x < y ? x = y, 1 : 0; }
template<typename T> inline bool cmin( T &x, T y ){ return y < x ? x = y, 1 : 0; }

const int _ = 105;
int N;
int a[_], f[_][_][2];

int main(){
	scanf( "%d", &N );
	fp( i, 1, N ) scanf( "%d", a + i );
	memset(f, 0x3f, sizeof f), f[0][0][0] = f[0][0][1] = 0;
	fp( i, 1, N ){
		fp( j, 0, min(i, N >> 1) ){
			if ( !a[i] ) f[i][j][0] = min(f[i - 1][j - 1][0], f[i - 1][j - 1][1] + 1), f[i][j][1] = min(f[i - 1][j][0] + 1, f[i - 1][j][1]);
			else if ( a[i] & 1 ) f[i][j][0] = 1e9, f[i][j][1] = min(f[i - 1][j][0] + 1, f[i - 1][j][1]);
			else f[i][j][0] = min(f[i - 1][j - 1][0], f[i - 1][j - 1][1] + 1), f[i][j][1] = 1e9;
		}
	}
	printf( "%d\n", min(f[N][N >> 1][0], f[N][N >> 1][1]) );
	return 0;
}