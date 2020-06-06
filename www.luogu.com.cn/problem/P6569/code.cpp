#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define open(s) freopen( s".in", "r", stdin ), freopen( s".out", "w", stdout )
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline bool cmax( T &x, T y ){ return x < y ? x = y, 1 : 0; }
template<typename T> inline bool cmin( T &x, T y ){ return y < x ? x = y, 1 : 0; }

const int _ = 105;
int N, M, Q;
unsigned f[_];

struct node{
	bool v[_][_];
	inline node operator * ( const node &t ){
		node ans;
		memset(ans.v, 0, sizeof ans.v);
		fp( i, 1, N ) fp( k, 1, N ) fp( j, 1, N )
			ans.v[i][j] ^= v[i][k] & t.v[k][j];
		return ans;
	}
}p[_], o;

bool v[_], vv[_];

int main(){
	scanf( "%d%d%d", &N, &M, &Q );
	fp( i, 1, N ) scanf( "%u", f + i ), o.v[i][i] = 1;
	int x, y; unsigned a, ans;
	fp( i, 1, M ) scanf( "%d%d", &x, &y ), p[0].v[x][y] = p[0].v[y][x] = 1;
	fp( i, 1, 31 ) p[i] = p[i - 1] * p[i - 1];
	while( Q-- ){
		scanf( "%u", &a ); ans = 0;
		memset( v, 0, sizeof v ), v[1] = 1;
		fp( t, 0, 31 ) if ( (a >> t) & 1 ){
			memcpy( vv, v, sizeof v ), memset( v, 0, sizeof v );
			fp( j, 1, N ) fp( i, 1, N ) v[i] ^= vv[j] & p[t].v[j][i];
		}
		fp( i, 1, N ) if ( v[i] ) ans ^= f[i];
		printf( "%u\n", ans );
	}
	return 0;
}