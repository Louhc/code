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

int T, la, lb, n;
char A[100015], B[100015];

signed main(){
	scanf( "%d", &T );
	while( T-- ){
		scanf( "%s", A + 1 ), scanf( "%s", B + 1 );
		la = strlen(A + 1), lb = strlen(B + 1), n = max(la, lb);
		reverse(A + 1, A + la + 1), reverse(B + 1, B + lb + 1);
		fp( i, la + 1, n ) A[i] = '0'; fp( i, lb + 1, n ) B[i] = '0';
		if ( lb == 1 && B[1] == '0' ){ printf("0\n"); continue; }
		int ans(1);
		fp( i, 1, n ){
			if ( A[i] == '1' && B[i] == '1' ){
				int cnt(2); ++i;
				while( i <= n && ((A[i] == '1') ^ (B[i] == '1')) ) ++i, ++cnt;
				cmax( ans, cnt ), --i;
			}
		} printf( "%d\n", ans );
	}
	return 0;
}


