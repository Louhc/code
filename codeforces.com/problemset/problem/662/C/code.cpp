#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(e), I(e); i >= I; --i )
template<class T> inline bool cmax( T &x, T y ){ return x < y ? x = y, 1 : 0; }
template<class T> inline bool cmin( T &x, T y ){ return x > y ? x = y, 1 : 0; }
#define getchar() (p1 == p2 && (p1 = bf, p2 = bf + fread(bf, 1, 1 << 21, stdin), p1 == p2 ) ? EOF : *p1++ )
char bf[1 << 21], *p1, *p2;
template<class T> inline void read( T &x ){
    x = 0; char t(getchar()), flg(0);
    while( t > 57 || t < 48 ) flg = t == '-', t = getchar();
    while( t < 58 && t > 47 ) x = x * 10 + (t & 15), t = getchar();
    flg ? x = -x : x;
}

const int _ = 1<<20;
int N, M, n;
int a[_];
i64 A[_], B[_];

void FWT( i64 *a, bool opt ){ i64 X, Y;
	for ( int i = 1; i < n; i <<= 1 ) for ( int j = 0, sj(i << 1); j < n; j += sj ) fp( k, j, j + i - 1 )
		X = a[k], Y = a[k + i], a[k] = X + Y, a[k + i] = X - Y,
		opt ? a[k] >>= 1, a[k + i] >>= 1 : 0;
}

int main(){
	read(N), read(M), n = 1 << N;
	fp( i, 0, N - 1 ) fp( j, 1, M ){
		int t; while( (t = getchar()) != '0' && t != '1' );
		a[j] |= (t & 1) << i;
	} fp( i, 1, M ) ++A[a[i]];
	fp( i, 0, n - 1 ) B[i] = B[i >> 1] + (i & 1);
	fp( i, 0, n - 1 ) cmin( B[i], N - B[i] );
	FWT(A, 0), FWT(B, 0);
	fp( i, 0, n - 1 ) A[i] *= B[i];
	FWT(A, 1); i64 ans = 1e18;
	fp( i, 0, n - 1 ) cmin(ans, A[i]);
	cout << ans << endl;
	return 0;
}