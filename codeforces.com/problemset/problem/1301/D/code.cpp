#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline bool cmax( T &x, T y ){ return x < y ? x = y, 1 : 0; }
template<typename T> inline bool cmin( T &x, T y ){ return y < x ? x = y, 1 : 0; }

int N, M, K;
string a[3005];
int b[3005], n;

int main(){
	cin >> N >> M >> K;
	if ( K > 4 * N * M - 2 * N - 2 * M ) return printf("NO\n"), 0;
	printf("YES\n");
	if ( M > 1 ) a[++n] = "R", b[n] = M - 1;
	if ( M > 1 ) a[++n] = "L", b[n] = M - 1;
	fp( i, 1, N - 1 ){
		if ( M > 1 ) a[++n] = "DRU", b[n] = M - 1;
		a[++n] = "D", b[n] = 1;
		if ( M > 1 ) a[++n] = "L", b[n] = M - 1;
	}
	if ( N > 1 ) a[++n] = "U", b[n] = N - 1;
	fp( i, 1, n ){
		if ( K <= b[i] * a[i].size() ){
			if ( a[i].size() == 1 ) b[n = i] = K;
			else{
				b[n = i] = K / 3;
				if ( K % 3 ){
					if ( K < 3 ) a[n = i] = a[i].substr(0, K % 3), b[i] = 1;
					else a[n = i + 1] = a[i].substr(0, K % 3), b[i + 1] = 1;
				}
			} break;
		} else K -= b[i] * a[i].size();
	}
	cout << n << endl;
	fp( i, 1, n ) cout << b[i] << " " << a[i] << endl;
	return 0;
}
