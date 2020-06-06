#include<bits/stdc++.h>
using namespace std;
inline bool cmin( int &x, int y ){ return x > y ? x = y, 1 : 0; }
inline bool cmax( int &x, int y ){ return x < y ? x = y, 1 : 0; }
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[b]); i; v = to[i = nxt[i]] )
#define i64 long long

const int _ = 1e5 + 55;
int N;

int main(){
	scanf( "%d", &N );
	if ( ((N * (N + 1)) & 3) == 0 ){
		printf("Yes\n");
		printf("1 2\n");
		printf( "%d %d ", N - 1, 1 );
		fp( i, 3, N ) printf( "%d ", i );
	} else if ( N > 2 ) {
		int t = N % 2 == 0 ? N / 2 : N;
		printf("Yes\n");
		printf("%d %d\n%d ", 1, t, N - 1 );
		fp( i, 1, N ) if ( i != t ) printf( "%d ", i );
	} else printf( "No\n" );
	return 0;
}