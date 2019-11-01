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

int N, K; i64 ans(1); 
int s[20];

signed main(){
	scanf( "%d%d", &N, &K );
	fp( i, 1, N ) ans = ans * i;
	while( ans % 10 == 0 ) ans /= 10;
	fp( i, 1, K ) s[i] = ans % 10, ans /= 10;
	while( !ans && !s[K] ) --K;
	fd( i, K, 1 ) putchar(s[i] | '0');
	return 0;
}

