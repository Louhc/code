#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline bool cmax( T &x, T y ){ return x < y ? x = y, 1 : 0; }
template<typename T> inline bool cmin( T &x, T y ){ return y < x ? x = y, 1 : 0; }

const int _ = 505;
int N, M, Q; char s[_][_];
int s1[_][_], s2[_][_], s3[_][_], s4[_][_];
int sum[_][_][_ >> 1];

inline int get( int x, int y, int xx, int yy, int k ){ return sum[xx][yy][k] - sum[x - 1][yy][k] - sum[xx][y - 1][k] + sum[x - 1][y - 1][k]; }

int main(){
	scanf( "%d%d%d", &N, &M, &Q );
	fp( i, 1, N ) scanf( "%s", s[i] + 1 );
	fd( i, N, 1 ) fd( j, M, 1 ) if ( s[i][j] == 'R' ) s1[i][j] = min(min(s1[i + 1][j], s1[i][j + 1]), s1[i + 1][j + 1]) + 1;
	fd( i, N, 1 ) fd( j, M, 1 ) if ( s[i][j] == 'G' ) s2[i][j] = min(min(s2[i + 1][j], s2[i][j + 1]), s2[i + 1][j + 1]) + 1;
	fd( i, N, 1 ) fd( j, M, 1 ) if ( s[i][j] == 'Y' ) s3[i][j] = min(min(s3[i + 1][j], s3[i][j + 1]), s3[i + 1][j + 1]) + 1;
	fd( i, N, 1 ) fd( j, M, 1 ) if ( s[i][j] == 'B' ) s4[i][j] = min(min(s4[i + 1][j], s4[i][j + 1]), s4[i + 1][j + 1]) + 1;
	fp( i, 1, N - 1 ) fp( j, 1, M - 1 ) fp( k, 1, min(N, M) >> 1 )
		if ( s1[i][j] >= k && s2[i][j + k] >= k && s3[i + k][j] >= k && s4[i + k][j + k] >= k ){
			sum[i][j][k] = 1; break;
		}
	fp( i, 1, N ) fp( j, 1, M ) fp( k, 1, min(N, M) >> 1 ) sum[i][j][k] += sum[i][j - 1][k] + sum[i - 1][j][k] - sum[i - 1][j - 1][k];
	int x, y, xx, yy, cnt(0);
	while( Q-- ){
		scanf( "%d%d%d%d", &x, &y, &xx, &yy );
		int l(1), r(min(yy - y + 1, xx - x + 1) >> 1), mid, ans(0);
		while( l <= r ){
			mid = (l + r) >> 1;
			if ( get(x, y, xx - (mid << 1) + 1, yy - (mid << 1) + 1, mid) ) l = mid + 1, ans = mid;
			else r = mid - 1;
		}
		printf( "%d\n", ans * ans * 4 );
	}
	return 0;
}
