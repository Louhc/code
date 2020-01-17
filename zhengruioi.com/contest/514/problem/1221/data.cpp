#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define open(s) freopen( s".in", "r", stdin ), freopen( s".out", "w", stdout )
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline void cmax( T &x, T y ){ x < y ? x = y : x; }
template<typename T> inline void cmin( T &x, T y ){ y < x ? x = y : x; }

int N = 3e5, Q = N;
mt19937 mt(time(0));

int main(){
	freopen( "data.in", "w", stdout );
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cout << N << " " << Q << endl;
	fp( i, 2, N ) cout << (mt() & 1 ? i - 1 : (mt() % min(i - 1, 10) + 1) ) << " "; cout << endl;
	fp( i, 1, N ) cout << mt() << endl;
	fp( i, 1, Q ){
		if ( mt() & 1 ){
			cout << 1 << " " << mt() % N + 1 << " " << mt() << endl;
		} else{
			cout << 2 << " " << mt() % N + 1 << endl;
		}
	}
	return 0;
}

