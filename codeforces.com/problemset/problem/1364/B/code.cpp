#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline bool cmax( T &x, T y ){ return x < y ? x = y, 1 : 0; }
template<typename T> inline bool cmin( T &x, T y ){ return y < x ? x = y, 1 : 0; }

const int _ = 1e5 + 55;
int T, N, M;
int a[_], b[_];

int main(){
	cin >> T;
	while( T-- ){
		cin >> N; M = 0;
		fp( i, 1, N ) cin >> a[i];
		int x(1), y(2); i64 ans(abs(a[1] - a[2]));
		b[M = 1] = 1;
		fp( i, 3, N ){
			if ( (a[x] > a[y] && a[y] > a[i]) || (a[x] < a[y] && a[y] < a[i]) )
				ans = ans - abs(a[x] - a[y]) + abs(a[i] - a[x]), y = i;
			else
				b[++M] = y, x = y, y = i, ans += abs(a[x] - a[y]);
		}
		b[++M] = y;
		printf( "%d\n", M );
		fp( i, 1, M ) printf( "%d ", a[b[i]] );
		printf("\n");
	}
	return 0;
}