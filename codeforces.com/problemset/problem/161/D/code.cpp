#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define open(s) freopen( s".in", "r", stdin ), freopen( s".out", "w", stdout )
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline void cmax( T &x, T y ){ x < y ? x = y : x; }
template<typename T> inline void cmin( T &x, T y ){ y < x ? x = y : x; }

const int _ = 5e4 + 55;
int N, K;
int hd[_], nxt[_<<1], to[_<<1], tot;
int sg[_], num, rv[_], sz[_], dep[_];
int s[_<<1]; i64 ans;

inline void addedge( int x, int y ){
	nxt[++tot] = hd[x], hd[x] = tot, to[tot] = y;
}

void DFS( int u, int fa ){
	rv[sg[u] = ++num] = u, sz[u] = 1, dep[u] = dep[fa] + 1;
	go( i, hd[u] ) if ( v != fa ) DFS(v, u), sz[u] += sz[v];
}

void DSU( int u, int fa, bool keep ){
	int sn(0);
	go( i, hd[u] ) if ( sz[v] < sz[u] ) if ( sz[sn] < sz[u] ) sn = v;
	go( i, hd[u] ) if ( v != fa && v != sn ) DSU(v, u, 0);
	if ( sn ) DSU(sn, u, 1);
	go( i, hd[u] ) if ( v != fa && v != sn ){
		fp( j, sg[v], sg[v] + sz[v] - 1 ) if ( dep[rv[j]] - dep[u] <= K ) ans += s[(dep[u] << 1) + K - dep[rv[j]]];
		fp( j, sg[v], sg[v] + sz[v] - 1 ) ++s[dep[rv[j]]];
	} ans += s[dep[u] + K], ++s[dep[u]];
	if ( !keep ) fp( i, sg[u], sg[u] + sz[u] - 1 ) --s[dep[rv[i]]];
}

int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> K; int x, y;
	fp( i, 1, N - 1 ) cin >> x >> y, addedge(x, y), addedge(y, x);
	DFS(1, 0);
	DSU(1, 0, 1);
	cout << ans << endl;
	return 0;
}