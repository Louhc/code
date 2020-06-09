#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline bool cmax( T &x, T y ){ return x < y ? x = y, 1 : 0; }
template<typename T> inline bool cmin( T &x, T y ){ return y < x ? x = y, 1 : 0; }

const int _ = 2e5 + 55;
int N, K, dep[_], sz[_], fa[_]; i64 ans;
vector<int> e[_];
priority_queue<pair<int, int> > Q;

void DFS( int u ){
	sz[u] = 1;
	for ( int v : e[u] ) if ( v != fa[u] ){
		dep[v] = dep[u] + 1;
		fa[v] = u;
		DFS(v);
		sz[u] += sz[v];
	}
}

int Get( int x ){
	return sz[x] - dep[x] - 1;
	// return 1ll * (sz[x] - 1) * (dep[x] + 1) - 1ll * sz[x] * dep[x];
}

int main(){
	scanf( "%d%d", &N, &K ); int x, y;
	fp( i, 2, N ) scanf( "%d%d", &x, &y ), e[x].push_back(y), e[y].push_back(x);
	DFS(1);
	Q.push(make_pair(Get(1), 1));
	fp( i, 1, N - K ){
		int u(Q.top().second); ans += Q.top().first; Q.pop();
		for ( int v : e[u] ) if ( v != fa[u] ) Q.push(make_pair(Get(v), v));
	} printf( "%lld\n", ans );
	return 0;
}
