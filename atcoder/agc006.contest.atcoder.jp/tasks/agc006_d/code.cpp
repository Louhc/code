#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#define rgt register
#define open(s) freopen( s".in", "r", stdin ), freopen( s".out", "w", stdout )
#define fp( i, b, e ) for ( rgt int i(b), i##end(e); i <= i##end; ++i )
#define fd( i, b, e ) for ( rgt int i(b), i##end(e); i >= i##end; --i )
template<class T> inline bool cmin( T &x, T y ){ return x > y ? x = y, 1 : 0; }
template<class T> inline bool cmax( T &x, T y ){ return x < y ? x = y, 1 : 0; }
// #define getchar() ( p1 == p2 && ( p1 = bf, p2 = bf + fread( bf, 1, 1 << 21, stdin ), p1 == p2 ) ? EOF : *p1++ )
char bf[1 << 21], *p1, *p2;
template<class T> inline void read( T &x ){
	x = 0; char t(getchar()), flg(0);
	while( t < 48 || t > 57 ) flg = t == '-', t = getchar();
	while( t > 47 && t < 58 ) x = x * 10 + ( t & 15 ), t = getchar();
	flg ? x = -x : x;
}

const int MAXN = 1e5 + 5;
int N, M;
int a[MAXN << 1];

bool check( int x ){
	fp( i, 0, N - 2 ){
		if ( ( a[N - i] >= x && a[N - i - 1] >= x ) || ( a[N + i] >= x && a[N + i + 1] >= x ) ) return 1;
		if ( ( a[N - i] < x && a[N - i - 1] < x ) || ( a[N + i] < x && a[N + i + 1] < x ) ) return 0;
	} return a[1] >= x;
}

int main(){
	read(N); fp( i, 1, M = N * 2 - 1 ) read(a[i]);
	int mid, l(1), r(2 * N - 1), ans(-1);
	while( l <= r ) check(mid = (l + r) >> 1) ? l = mid + 1, ans = mid : r = mid - 1;
	printf( "%d\n", ans );
	return 0;
}