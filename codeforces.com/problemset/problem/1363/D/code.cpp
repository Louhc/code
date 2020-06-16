#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline bool cmax( T &x, T y ){ return x < y ? x = y, 1 : 0; }
template<typename T> inline bool cmin( T &x, T y ){ return y < x ? x = y, 1 : 0; }

int T, N, K, mx, x;
int p[1005], a[1005][1005], ans[1005];
string result;

int main(){
	cin >> T;
	while( T-- ){
		cin >> N >> K;
		fp( i, 1, K ){
			cin >> a[i][0];
			fp( j, 1, a[i][0] ) cin >> x, a[i][x] = 1, p[x] = i;
		}
		cout << "? " << N;
		fp( i, 1, N ) cout << " " << i;
		cout << endl;
		cin >> mx;
		int l(1), r(N), mid, cur;
		while( l < r ){
			mid = (l + r) >> 1;
			cout << "? " << mid - l + 1;
			fp( i, l, mid ) cout << " " << i;
			cout << endl;
			cin >> cur;
			if ( cur >= mx ) r = mid;
			else l = mid + 1;
		}
		fp( i, 1, K ) if ( a[i][l] ){
			cout << "? " << N - a[i][0];
			fp( j, 1, N ) if ( !a[i][j] ) cout << " " << j;
			cout << endl;
			cin >> ans[i];
		} else ans[i] = mx;
		cout << "!";
		fp( i, 1, K ) cout << " " << ans[i];
		cout << endl;
		fp( i, 1, N ) a[p[i]][i] = 0;
		cin >> result;
		if ( result != "Correct" ) return 0;
	}
	return 0;
}
