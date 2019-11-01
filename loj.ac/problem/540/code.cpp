#include<bits/stdc++.h>
using namespace std;
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )

int N, t, c;
int a[188], cnt;
bool vis[505][505];

signed main(){
	scanf( "%d", &N ), c = 1;
	fd( i, 181, 1 ){
		t = i * ( i + 1 ) * ( i + 2 ) / 6;
		while( N >= t ){
			N -= t;
			fp( j, 0, i + 1 )
				fp( k, j + 1, i + 1 )
					vis[j + c][k + c] = 1;
			c += i + 1;
		}
	}
	printf( "%d\n", c );
	fp( i, 1, c ) fp( j, i + 1, c ) printf( "%d%c", vis[i][j], "\n "[j < c] );
	return 0;
}

