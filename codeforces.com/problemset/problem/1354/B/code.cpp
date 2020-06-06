#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define open(s) freopen( s".in", "r", stdin ), freopen( s".out", "w", stdout )
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline bool cmax( T &x, T y ){ return x < y ? x = y, 1 : 0; }
template<typename T> inline bool cmin( T &x, T y ){ return y < x ? x = y, 1 : 0; }

int T, c[3], ans;
char s[200005];

int main(){
	scanf( "%d", &T );
	while( T-- ){
		scanf( "%s", s + 1 ), c[0] = c[1] = c[2] = 0, ans = 1e9;
		for ( int i = 1, j = 0; s[i] != '\0'; ++i ){
			while( s[j + 1] != '\0' && (!c[0] || !c[1] || !c[2]) ) ++c[s[++j] - '1'];
			if ( !c[0] || !c[1] || !c[2] ) break;
			cmin(ans, j - i + 1), --c[s[i] - '1'];
		} printf( "%d\n", ans >= 1e9 ? 0 : ans );
	}
	return 0;
}