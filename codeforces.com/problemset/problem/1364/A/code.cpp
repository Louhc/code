#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline bool cmax( T &x, T y ){ return x < y ? x = y, 1 : 0; }
template<typename T> inline bool cmin( T &x, T y ){ return y < x ? x = y, 1 : 0; }

const int _ = 1e5 + 55;
int T, N, x, ans, p;
int a[_];

int main(){
	cin >> T;
	while( T-- ){
		cin >> N >> x; p = 1e9, ans = -1;
		fp( i, 1, N ){
			cin >> a[i], a[i] = (a[i - 1] + a[i]) % x;
			if ( a[i] != 0 && p == 1e9 ) p = i;
		}
		fp( i, 1, N ){
			if ( a[i] == 0 ) cmax(ans, i - p);
			else cmax(ans, i);
		}
		printf( "%d\n", ans );
	}
	return 0;
}