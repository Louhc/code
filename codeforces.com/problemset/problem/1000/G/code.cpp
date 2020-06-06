#include<bits/stdc++.h>
using namespace std;
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[b]); i; v = to[i = nxt[i]] )
#define i64 long long

const int _ = 3e5 + 55;
int N, Q, a[_];
int hd[_], nxt[_<<1], to[_ << 1], val[_ << 1], tot(1);
i64 vn[_], ve[_]; int fa[_][20], dep[_];
i64 f[_], sf[_], g[_];

inline void addedge( int x, int y, int z ){
	nxt[++tot] = hd[x], hd[x] = tot, to[tot] = y, val[tot] = z;
}


void DFS( int u ){
	vn[u] = vn[fa[u][0]] + a[u], dep[u] = dep[fa[u][0]] + 1;
	fp( i, 1, 18 ) fa[u][i] = fa[fa[u][i - 1]][i - 1];
	go( i, hd[u] ) if ( v != fa[u][0] ){
		ve[v] = ve[u] + val[i], fa[v][0] = u, DFS(v);
		f[v] = max(0ll, sf[v] + a[v] - 2 * val[i]);
		sf[u] += f[v];
	}
}
void DFS1( int u ){
	go( i, hd[u] ) if ( v != fa[u][0] ){
		g[v] = max(0ll, g[u] + sf[u] - f[v] + a[u] - (2 * val[i]));
		DFS1(v);
	}
}
void DFS2( int u ){
	go( i, hd[u] ) if ( v != fa[u][0] ){
		f[v] += f[u], sf[v] += sf[u], DFS2(v);
	}
}

int LCA( int x, int y ){
	if ( dep[x] < dep[y] ) x^=y^=x^=y;
	fd( i, 18, 0 ) if ( dep[fa[x][i]] > dep[y] ) x = fa[x][i];
	if ( dep[x] > dep[y] ) x = fa[x][0];
	fd( i, 18, 0 ) if ( fa[x][i] != fa[y][i] ) x = fa[x][i], y = fa[y][i];
	return x != y ? fa[x][0] : x;
}

int main(){
	scanf( "%d%d", &N, &Q );
	fp( i, 1, N ) scanf( "%d", a + i );
	int x, y, z;
	fp( i, 1, N - 1 ) scanf( "%d%d%d", &x, &y, &z ), addedge(x, y, z), addedge(y, x, z);
	DFS(1); DFS1(1); DFS2(1);
	while( Q-- ){
		scanf( "%d%d", &x, &y );
		z = LCA(x, y);
		i64 ans(vn[x] + vn[y] - vn[z] - vn[fa[z][0]] - (ve[x] + ve[y] - 2 * ve[z]));
		ans += sf[x] + sf[y] - sf[z] - sf[fa[z][0]] + g[z];
		ans -= f[x] + f[y] - 2 * f[z];
		printf( "%lld\n", ans );
	}
	return 0;
}