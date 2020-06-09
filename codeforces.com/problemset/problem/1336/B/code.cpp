#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline bool cmax( T &x, T y ){ return x < y ? x = y, 1 : 0; }
template<typename T> inline bool cmin( T &x, T y ){ return y < x ? x = y, 1 : 0; }

const int _ = 1e5 + 55;
int T, a[_], b[_], c[_];
i64 ans;

i64 sqr( i64 x ){ return x * x; }

void work( int *a, int *b, int *c ){
	int j(1), k(1);
	fp( i, 1, a[0] ){
		while( j < b[0] && b[j + 1] <= a[i] ) ++j;
		while( k < c[0] && c[k] < a[i] ) ++k;
		// cerr << a[i] << " " << b[j] << " " << c[k] << " " << sqr(a[i] - b[j]) + sqr(a[i] - c[k]) + sqr(b[j] - c[k]) << endl;
		cmin(ans, sqr(a[i] - b[j]) + sqr(a[i] - c[k]) + sqr(b[j] - c[k]));
	}
}

int main(){
	scanf( "%d", &T );
	while( T-- ){
		scanf( "%d%d%d", a, b, c );
		fp( i, 1, a[0] ) scanf( "%d", a + i );
		fp( i, 1, b[0] ) scanf( "%d", b + i );
		fp( i, 1, c[0] ) scanf( "%d", c + i );
		sort(a + 1, a + a[0] + 1);
		sort(b + 1, b + b[0] + 1);
		sort(c + 1, c + c[0] + 1);
		ans = 3e18;
		work(a, b, c);
		work(a, c, b);
		work(b, a, c);
		work(b, c, a);
		work(c, a, b);
		work(c, b, a);
		printf( "%lld\n", ans );
	}
	return 0;
}
