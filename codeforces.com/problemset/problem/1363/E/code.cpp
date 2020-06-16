#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline bool cmax( T &x, T y ){ return x < y ? x = y, 1 : 0; }
template<typename T> inline bool cmin( T &x, T y ){ return y < x ? x = y, 1 : 0; }

const int _ = 2e5 + 55;
int N; i64 ans;
int a[_], b[_], c[_], s[_][2];
vector<int> e[_];

void DFS( int u, int fa ){
	if ( b[u] != c[u] ) ++s[u][b[u]];
	for ( int v : e[u] ) if ( v != fa )
		cmin(a[v], a[u]), DFS(v, u);
	if ( s[u][0] > s[u][1] ) s[fa][0] += s[u][0] - s[u][1];
	else s[fa][1] += s[u][1] - s[u][0];
	ans += min(s[u][0], s[u][1]) * 2ll * a[u];
}

int main(){
	scanf( "%d", &N );
	fp( i, 1, N ) scanf( "%d%d%d", a + i, b + i, c + i );
	int x, y;
	fp( i, 1, N - 1 ) scanf( "%d%d", &x, &y ), e[x].push_back(y), e[y].push_back(x);
	DFS(1, 0);
	cout << (!s[0][0] && !s[0][1] ? ans : -1ll);
	return 0;
}