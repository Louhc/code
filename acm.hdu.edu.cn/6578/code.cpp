#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define open(s) freopen( s".in", "r", stdin ), freopen( s".out", "w", stdout )
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline bool cmax( T &x, T y ){ return x < y ? x = y, 1 : 0; }
template<typename T> inline bool cmin( T &x, T y ){ return y < x ? x = y, 1 : 0; }

struct node{
	int l, s;
};

const int mod = 998244353, _ = 105;

int T, N, M, ans;
vector<node> v[_];
int f[2][_][_][_];

inline void add( int &x, int y ){
	x += y, x >= mod ? x -= mod : x;
}

bool check( int a, int b, int c, int d ){
	for ( auto w : v[a] ) if ( (int)(w.l <= a) + (w.l <= b) + (w.l <= c) + (w.l <= d) != w.s ) return 0;
	return 1;
}

int main(){
	scanf( "%d", &T );
	while( T-- ){
		scanf( "%d%d", &N, &M );
		fp( i, 1, N ) v[i].clear();
		int x; node y; ans = 0;
		fp( i, 1, M ) scanf( "%d%d%d", &y.l, &x, &y.s ), v[x].push_back(y);
		f[0][0][0][0] = 1;
		fp( i, 0, N ){
			int cur = i & 1, nxt = !cur;
			fp( j, 0, i ) fp( k, 0, j ) fp( q, 0, k ) f[nxt][j][k][q] = 0;
			fp( j, 0, max(i - 1, 0) ) fp( k, 0, max(j - 1, 0) ) fp( q, 0, max(k - 1, 0) ){
				if ( !check(i, j, k, q) || !f[cur][j][k][q] ){
					f[cur][j][k][q] = 0; continue;
				}
				if ( i == N ){
					add(ans, f[cur][j][k][q]); continue;
				}
				add( f[nxt][i][j][k], f[cur][j][k][q] );
				add( f[nxt][i][j][q], f[cur][j][k][q] );
				add( f[nxt][i][k][q], f[cur][j][k][q] );
				add( f[nxt][j][k][q], f[cur][j][k][q] );
			}
		}
		printf( "%d\n", ans );
	}
	return 0;
}