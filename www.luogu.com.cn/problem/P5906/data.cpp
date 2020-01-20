#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define open(s) freopen( s".in", "r", stdin ), freopen( s".out", "w", stdout )
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline void cmax( T &x, T y ){ x < y ? x = y : x; }
template<typename T> inline void cmin( T &x, T y ){ y < x ? x = y : x; }

int main(){
	freopen( "data.in", "w", stdout );
	ios::sync_with_stdio(0), cin.tie(0);
	srand(time(0));
	int N = 1000, M = 1000;
	cout << N << endl;
	fp( i, 1, N ) cout << rand() % 200 + 1 << " "; cout << endl;
	cout << M << endl;
	fp( i, 1, M ){
		int l = rand() % N + 1, r = rand() % N + 1;
		cout << min(l, r) << " " << max(l, r) << endl;
	}
	return 0;
}