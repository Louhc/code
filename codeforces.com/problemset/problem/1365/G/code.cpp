#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline bool cmax( T &x, T y ){ return x < y ? x = y, 1 : 0; }
template<typename T> inline bool cmin( T &x, T y ){ return y < x ? x = y, 1 : 0; }

int N, cnt;
int s[1 << 13], a[13][1005];
i64 sum, ans[1005];

int main(){
	cin >> N;
	fp( i, 0, (1 << 13) - 1 ){
		s[i] = s[i >> 1] + (i & 1);
		if ( s[i] != 6 ) continue;
		++cnt;
		fp( j, 0, 12 ) if ( i & (1 << j) ) a[j][cnt] = 1, ++a[j][0];
		if ( cnt >= N ) break;
	}
	fp( i, 0, 12 ){
		if ( a[i][0] < 1 || a[i][0] >= N ) continue;
		cout << "? " << a[i][0];
		fp( j, 1, N ) if ( a[i][j] ) cout << " " << j;
		cout << endl;
		cin >> sum;
		fp( j, 1, N ) if ( !a[i][j] ) ans[j] |= sum;
	}
	cout << "!";
	fp( i, 1, N ) cout << " " << ans[i];
	cout << endl;
	return 0;
}
