#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define open(s) freopen( s".in", "r", stdin ), freopen( s".out", "w", stdout )
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline void cmax( T &x, T y ){ x < y ? x = y : x; }
template<typename T> inline void cmin( T &x, T y ){ y < x ? x = y : x; }

const int _ = 2e3 + 55;
int N, M, Q;
char str[_][_];
int s1[_][_], s2[_][_], vis[_][_];

int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> M >> Q;
	fp( i, 1, N ) cin >> (str[i] + 1);
	fp( i, 1, N ) fp( j, 1, M ){
		s1[i][j] = (str[i][j] & 1) + s1[i][j - 1];
		s2[i][j] = (str[i][j] & 1) + s2[i - 1][j];
	}
	fp( T, 1, Q ){
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		c -= a, d -= b;
	}
	return 0;
}