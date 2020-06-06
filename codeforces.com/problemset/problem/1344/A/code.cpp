#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define open(s) freopen( s".in", "r", stdin ), freopen( s".out", "w", stdout )
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline bool cmax( T &x, T y ){ return x < y ? x = y, 1 : 0; }
template<typename T> inline bool cmin( T &x, T y ){ return y < x ? x = y, 1 : 0; }

const int _ = 2e5 + 55;
int T, N, x;
unordered_set<int> S;

int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> T;
	while( T-- ){
		cin >> N; bool flg(0); S.clear();
		fp( i, 0, N - 1 ) cin >> x, x = ((x + i) % N + N) % N, flg = flg || S.count(x), S.insert(x);
		printf( flg ? "NO\n" : "YES\n" );
	}
	return 0;
}