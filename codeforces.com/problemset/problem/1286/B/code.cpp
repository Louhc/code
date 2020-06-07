#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline bool cmax( T &x, T y ){ return x < y ? x = y, 1 : 0; }
template<typename T> inline bool cmin( T &x, T y ){ return y < x ? x = y, 1 : 0; }

const int _ = 2005;
int N, c[_], x;
vector<int> e[_];
int o[_][_], n[_], ans[_];

void DFS( int u ){
	for ( int v : e[u] ){
		DFS(v);
		fp( j, 1, n[v] ){
			if ( n[u] == c[u] ) o[u][++n[u]] = u;
			o[u][++n[u]] = o[v][j];
		}
	}
	if ( n[u] == c[u] ) o[u][++n[u]] = u;
	if ( n[u] < c[u] ) printf("NO\n"), exit(0);
}

int main(){
	scanf( "%d", &N );
	fp( i, 1, N ) scanf( "%d%d", &x, c + i ), e[x].push_back(i);
	DFS(e[0][0]);
	fp( i, 1, N ) ans[o[e[0][0]][i]] = i;
	printf( "YES\n" );
	fp( i, 1, N ) printf( "%d%c", ans[i], "\n "[i < N] );
	return 0;
}