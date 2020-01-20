#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define open(s) freopen( s".in", "r", stdin ), freopen( s".out", "w", stdout )
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline void cmax( T &x, T y ){ x < y ? x = y : x; }
template<typename T> inline void cmin( T &x, T y ){ y < x ? x = y : x; }

const int _ = 20;
int N, M, f[1 << _];
bool flg;
int a1[1 << _], n1;
int a2[1 << _], n2;

int main(){
	srand(time(0));
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N, M = (1 << N) - 1; flg = 1;
	fp( i, 0, N - 1 ) cin >> f[1 << i];
	fp( i, 1, M ){
		f[i] = f[i & -i] ^ f[i ^ (i & -i)], flg &= f[i] < 2;
		if ( f[i] == 1 ) a1[++n1] = i; else a2[++n2] = i;
	}
	if ( flg ){
		if ( n1 == n2 ){
			printf( "%d\n", n1 * 2 - 1 );
			fp( i, 1, n1 ) printf( "%d %d ", a1[i], a2[i] ); 
		} else if ( n1 > n2 ){
			printf( "%d\n", n2 << 1 );
			fp( i, 1, n2 ) printf( "%d %d ", a1[i], a2[i] );
			fp( i, n2 + 1, n1 ) printf( "%d ", a1[i] );
		} else if ( n1 < n2 ){
			printf( "%d\n", n1 << 1 );
			fp( i, 1, n1 ) printf( "%d %d ", a2[i], a1[i] );
			fp( i, n1 + 1, n2 ) printf( "%d ", a2[i] );
		}
		return 0;
	}
	fp( i, 1, M ) a1[i] = i;
	double T(5e10); int ans(0), s(0);
	fp( i, 1, M - 1 ) ans += f[a1[i + 1]] ^ f[a1[i]];
	while( T > 5e-10 ){
		int x, y, cur; x = rand() % M + 1, y = rand() % M + 1, cur = ans;
		if ( x > 1 && x - 1 != y ) cur = cur - (f[a1[x]] ^ f[a1[x - 1]]) + (f[a1[y]] ^ f[a1[x - 1]]);
		if ( x < M && x + 1 != y ) cur = cur - (f[a1[x]] ^ f[a1[x + 1]]) + (f[a1[y]] ^ f[a1[x + 1]]);
		if ( y > 1 && y - 1 != x ) cur = cur - (f[a1[y]] ^ f[a1[y - 1]]) + (f[a1[x]] ^ f[a1[y - 1]]);
		if ( y < M && y + 1 != x ) cur = cur - (f[a1[y]] ^ f[a1[y + 1]]) + (f[a1[x]] ^ f[a1[y + 1]]);
		if ( exp((cur - ans) / T) * RAND_MAX > rand() ) ans = cur, swap(a1[x], a1[y]);
		T *= .999995;
	}
	printf( "%d\n", ans );
	fp( i, 1, M ) printf( "%d ", a1[i] );
	return 0;
}