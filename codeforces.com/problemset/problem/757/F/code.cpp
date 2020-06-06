#include<bits/stdc++.h>
using namespace std;
#define fp(i, b, e) for ( int i = b, I = e; i <= I; ++i )
#define fd(i, b, e) for ( int i = b, I = e; i >= I; --i )
#define go(i, b) for ( int i = b, v = to[b]; i; v = to[i = nxt[i]] )
#define i64 long long
template<class T> inline bool cmin( T &x, T y ){ return x > y ? x = y, 1 : 0; }
template<class T> inline bool cmax( T &x, T y ){ return x < y ? x = y, 1 : 0; }

const int _ = 2e5 + 55;
int N, M, S, a[_], s[_], n, ans;
int hd[_], nxt[_<<2], to[_<<2], val[_<<2], tot(1);
vector<int> e[_];
int f[_][20], in[_], dep[_];
i64 d[_];
queue<int> Q;
priority_queue<pair<i64, int> > q; bool vis[_];

void addedge( int x, int y, int z ){
	nxt[++tot] = hd[x], hd[x] = tot, to[tot] = y, val[tot] = z;
}
int LCA( int x, int y ){
	if ( dep[x] < dep[y] ) swap(x, y);
	fd( i, 17, 0 ) if ( dep[f[x][i]] > dep[y] ) x = f[x][i];
	if ( dep[x] > dep[y] ) x = f[x][0];
	fd( i, 17, 0 ) if ( f[x][i] != f[y][i] ) x = f[x][i], y = f[y][i];
	return x == y ? x : f[x][0];
}

int main(){
	scanf( "%d%d%d", &N, &M, &S );
	int x, y, z;
	fp( i, 1, M ) scanf( "%d%d%d", &x, &y, &z ), addedge(x, y, z), addedge(y, x, z);
	
	memset(d, 0x3f, sizeof d);
	q.push(make_pair(0, S)), d[S] = 0;
	while( q.size() ){
		int u(q.top().second); q.pop();
		if ( vis[u] ) continue;
		vis[u] = 1;
		go( i, hd[u] ) if ( cmin(d[v], d[u] + val[i]) ) q.push(make_pair(-d[v], v));
	}
	
	fp( u, 1, N ) go( i, hd[u] ) if ( d[u] + val[i] == d[v] ) e[u].push_back(v), ++in[v];
	Q.push(S);
	while( Q.size() ){
		int u(Q.front()); Q.pop(); a[++n] = u, s[u] = 1;
		dep[u] = dep[f[u][0]] + 1;
		fp( i, 1, 17 ) f[u][i] = f[f[u][i - 1]][i - 1];
		for ( int v : e[u] ){
			f[v][0] = !f[v][0] ? u : LCA(f[v][0], u);
			if ( !--in[v] ) Q.push(v);
		}
	}
	fd( i, n, 2 ) cmax(ans, s[a[i]]), s[f[a[i]][0]] += s[a[i]];
	printf( "%d\n", ans );
	return 0;
}