#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline bool cmax( T &x, T y ){ return x < y ? x = y, 1 : 0; }
template<typename T> inline bool cmin( T &x, T y ){ return y < x ? x = y, 1 : 0; }

int N;
i64 a[555], ans;

int main(){
	cin >> N;
	fp( i, 1, N ) cin >> a[i];
	fp( i, 1, N ) fp( j, i, N ) fp( k, j, N ) cmax(ans, a[i] | a[j] | a[k]);
	cout << ans << endl;
	return 0;
}
