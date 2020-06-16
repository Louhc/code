#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline bool cmax( T &x, T y ){ return x < y ? x = y, 1 : 0; }
template<typename T> inline bool cmin( T &x, T y ){ return y < x ? x = y, 1 : 0; }

const int _ = 1e5 + 55;
int N;
int a[_], b[_];
queue<int> Q;

int main(){
	cin >> N;
	fp( i, 1, N ) cin >> a[i];
	fd( i, N, 1 ){
		if ( a[i] != a[i - 1] ){
			b[i] = a[i - 1];
			fp( j, a[i - 1] + 1, a[i] - 1 ) Q.push(j);
		}
		else {
			if ( Q.size() ) b[i] = Q.front(), Q.pop();
			else b[i] = N;
		}
	}
	if ( Q.size() ) printf("-1");
	else fp( i, 1, N ) printf( "%d ", b[i] );
	return 0;
}