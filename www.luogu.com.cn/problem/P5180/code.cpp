#include<bits/stdc++.h>
using namespace std;
#define fp(i, b, e) for ( int i = b, I = e; i <= I; ++i )
#define fd(i, b, e) for ( int i = b, I = e; i >= I; --i )
#define go(i, b) for ( int i = b, v = to[b]; i; v = to[i = nxt[i]] )
#define i64 long long
inline bool cmin( int &x, int y ){ return x > y ? x = y, 1 : 0; }
inline bool cmax( int &x, int y ){ return x < y ? x = y, 1 : 0; }

const int _ = 2e5 + 55;
int N, M;
int h[_], rh[_], th[_], nxt[_*10], to[_*10], tot;
int dfn[_], id[_], anc[_], num, semi[_];
int fa[_], mn[_];
int f[_][20], dep[_];
int ans[_];

int find( int x ){
	if ( !fa[x] ) return x;
	int t = fa[x]; fa[x] = find(fa[x]);
	if ( dfn[semi[mn[x]]] > dfn[semi[mn[t]]] ) mn[x] = mn[t];
	return fa[x];
}

inline void addedge( int *hd, int x, int y ){
	nxt[++tot] = hd[x], hd[x] = tot, to[tot] = y;
}
void DFS( int u ){
	id[dfn[u] = ++num] = u;
	go( i, h[u] ) if ( !dfn[v] )
		anc[v] = u, DFS(v);
}

int LCA( int x, int y ){
	if ( dep[x] < dep[y] ) x ^= y ^= x ^= y;
	fd( i, 17, 0 ) if ( dep[f[x][i]] > dep[y] ) x = f[x][i];
	if ( dep[x] > dep[y] ) x = f[x][0];
	fd( i, 17, 0 ) if ( f[x][i] != f[y][i] ) x = f[x][i], y = f[y][i];
	return x == y ? x : f[x][0];
}

void Build( int u ){
	if ( u > 1 ) addedge(th, f[u][0] = LCA(anc[u], semi[u]), u);
	dep[u] = dep[f[u][0]] + 1;
	fp( i, 1, 17 ) f[u][i] = f[f[u][i - 1]][i - 1];
	go( i, h[u] ) if ( v > 1 && !f[v][0] ) Build(v);;
}
void dfs( int u ){
	ans[u] = 1;
	go( i, th[u] ) dfs(v), ans[u] += ans[v];
}

int main(){
	scanf( "%d%d", &N, &M ); int x, y;
	fp( i, 1, M ) scanf( "%d%d", &x, &y ), addedge(h, x, y), addedge(rh, y, x);
	fp( i, 1, N ) semi[i] = mn[i] = i;
	DFS(1);
	fd( i, N, 2 ){
		int u = id[i], res = N;
		if ( !u ) continue;
		go( j, rh[u] ){
			if ( !dfn[v] ) continue;
			if ( dfn[v] < dfn[u] ) cmin(res, dfn[v]);
			else find(v), cmin(res, dfn[semi[mn[v]]]);
		}
		semi[u] = id[res], fa[u] = anc[u];
	}
	Build(1), dfs(1);
	fp( i, 1, N ) printf( "%d ", ans[i] );
	return 0;
}