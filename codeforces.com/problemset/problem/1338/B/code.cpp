#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define open(s) freopen( s".in", "r", stdin ), freopen( s".out", "w", stdout )
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline bool cmax( T &x, T y ){ return x < y ? x = y, 1 : 0; }
template<typename T> inline bool cmin( T &x, T y ){ return y < x ? x = y, 1 : 0; }

const int _ = 1e5 + 55;
int N, d[_];
vector<int> e[_];

void DFS( int u, int fa ){
	for ( int v : e[u] ) if ( v != fa ) d[v] = 1 - d[u], DFS(v, u);
}

int main(){
	scanf( "%d", &N ); int x, y, ans(N - 1);
	fp( i, 2, N ) scanf( "%d%d", &x, &y ), e[x].push_back(y), e[y].push_back(x);
	fp( i, 1, N ) if ( e[i].size() == 1 ){ DFS(i, 0); break; }
	bool flg(1);
	fp( i, 1, N ) if ( e[i].size() == 1 && d[i] == 1 ){ flg = 0; break; }
	if ( flg ) printf("1 "); else printf("3 ");
	fp( u, 1, N ){
		int cur(0);
		for ( int v : e[u] ) cur += e[v].size() == 1;
		if ( cur ) ans -= cur - 1;
	} printf( "%d\n", ans );
	return 0;
}