#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline bool cmax( T &x, T y ){ return x < y ? x = y, 1 : 0; }
template<typename T> inline bool cmin( T &x, T y ){ return y < x ? x = y, 1 : 0; }

int N = 5;
int a[105];

int main(){
	while( 1 ){
		fp( i, 1, N ) cin >> a[i];
		int ans1(0), ans2(0);
		fp( i, 1, N ) ans1 += a[i] * (a[i] - 1) * (a[i] - 2) / 6, ans2 += a[i] * a[i + 1] * a[i + 2];
		cout << ans1 << " " << ans2 << endl;
	}
	return 0;
}
