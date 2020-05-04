#include<bits/stdc++.h>
using namespace std;
#define fp(i, b, e) for ( int i = b, I = e; i <= I; ++i )
#define fd(i, b, e) for ( int i = b, I = e; i >= I; --i )
#define go(i, b) for ( int i = b, v = to[b]; i; v = to[i = nxt[i]] )
#define i64 long long
inline bool cmin( int &x, int y ){ return x > y ? x = y, 1 : 0; }
inline bool cmax( int &x, int y ){ return x < y ? x = y, 1 : 0; }

int N, a[100], b[100], x;

int main(){
	scanf( "%d", &N );
	fp( i, 1, N ) scanf( "%d", a + i );
	fp( i, 1, N ) scanf( "%d", b + i );
	fp( i, 1, N ) x += a[i] - b[i];
	if ( x < 0 ) printf("No\n");
	else printf("Yes\n");
	return 0;
}