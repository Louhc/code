#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define open(s) freopen( s".in", "r", stdin ), freopen( s".out", "w", stdout )
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline bool cmax( T &x, T y ){ return x < y ? x = y, 1 : 0; }
template<typename T> inline bool cmin( T &x, T y ){ return y < x ? x = y, 1 : 0; }

int T, N, M;
int f[105][105][2][2][2][2];
int a[105][105];

int main(){
	scanf( "%d", &T );
	while( T-- ){
		scanf( "%d%d", &N, &M );
		memset(a, 0, sizeof a);
		int l, r, x;
		fp( i, 1, M ) scanf( "%d%d%d", &l, &r, &x ), a[l][r] = x;
	}
	return 0;
}