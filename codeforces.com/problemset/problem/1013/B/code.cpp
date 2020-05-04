#include<bits/stdc++.h>
using namespace std;
#define fp(i, b, e) for ( int i = b, I = e; i <= I; ++i )
#define fd(i, b, e) for ( int i = b, I = e; i >= I; --i )
#define go(i, b) for ( int i = b, v = to[b]; i; v = to[i = nxt[i]] )
#define i64 long long
inline bool cmin( int &x, int y ){ return x > y ? x = y, 1 : 0; }
inline bool cmax( int &x, int y ){ return x < y ? x = y, 1 : 0; }

const int _ = 1e5 + 55;

int N, x;
int a[_], b[_], ans(1e9);

int main(){
	scanf( "%d%d", &N, &x );
	fp( i, 1, N ) scanf( "%d", a + i );
	fp( i, 0, 1e5 ) b[i] = 1e9;
	fp( i, 1, N ){
		cmin(ans, b[a[i]]);
		cmin(ans, b[a[i] & x] + 1);
		cmin(b[a[i]], 0);
		cmin(b[a[i] & x], 1);
	}
	printf( "%d\n", ans == 1e9 ? -1 : ans );
	return 0;
}