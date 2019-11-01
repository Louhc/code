#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define INF 0x3f3f3f3f
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline void cmax( T &x, T y ){ x < y ? x = y : x; }
template<typename T> inline void cmin( T &x, T y ){ y < x ? x = y : x; }
#define getchar() ( p1 == p2 && ( p1 = bf, p2 = bf + fread( bf, 1, 1 << 21, stdin ), p1 == p2 ) ? EOF : *p1++ )
char bf[1 << 21], *p1(bf), *p2(bf);
template<typename T>
inline void read( T &x ){ char t(getchar()), flg(0); x = 0;
	for ( ; !isdigit(t); t = getchar() ) flg = t == '-';
	for ( ; isdigit(t); t = getchar() ) x = x * 10 + ( t & 15 );
	flg ? x = -x : x;
}

const int MAXN = 1e5 + 5;
struct heap{
	priority_queue<int> Q1, Q2;
	inline void push( int x ){ Q1.push(x); }
	inline void erase( int x ){ Q2.push(x); }
	inline int size(){ return Q1.size() - Q2.size(); }
	inline int top(){
		while( Q2.size() && Q1.top() == Q2.top() ) Q1.pop(), Q2.pop();
		return Q1.size() ? Q1.top() : -1000000000;
	}
//	inline void print(){
//		int a[1000], tp(0);
//		while( size() ) a[++tp] = top(), erase(a[tp]);
//		puts( "================" );
//		fp( i, 1, tp ) printf( "%d ", a[i] ), push(a[i]);
//		puts( "\n================" );
//	}
}h1[MAXN], h2[MAXN], r;

int N, Q, ct;
int hd[MAXN], nxt[MAXN<<1], to[MAXN<<1], tot;
int fa[MAXN], sz[MAXN];
bool vis[MAXN], on[MAXN];

inline void addedge( int x, int y ){ nxt[++tot] = hd[x], hd[x] = tot, to[tot] = y; }

namespace lca{
	int fa[MAXN][18], dep[MAXN];
	void DFS( int u ){
		dep[u] = dep[fa[u][0]] + 1; fp( i, 1, 16 ) fa[u][i] = fa[fa[u][i - 1]][i - 1];
		go( i, hd[u] ) if ( v != fa[u][0] ) fa[v][0] = u, DFS(v);
	} inline int LCA( int x, int y ){
		if ( dep[x] < dep[y] ) swap( x, y );
		fd( i, 16, 0 ) if ( dep[fa[x][i]] > dep[y] ) x = fa[x][i];
		if ( dep[x] > dep[y] ) x = fa[x][0];
		fd( i, 16, 0 ) if ( fa[x][i] != fa[y][i] ) x = fa[x][i], y = fa[y][i];
		return x == y ? x : fa[x][0];
	} inline int dist( int x, int y ){ return dep[x] + dep[y] - ( dep[LCA(x, y)] << 1 ); }
} using lca::dist;

inline int GetAns( int u ){
	if ( h2[u].size() < 2 ) return 0;
	int t1, t2; t1 = h2[u].top(), h2[u].Q1.pop();
	t2 = h2[u].top(), h2[u].push(t1);
	return t1 + t2;
}
int rt, mxp, size;
void findrt( int u, int fa ){
	sz[u] = 1; int t(0);
	go( i, hd[u] ) if ( v != fa && !vis[v] ) 
		findrt(v, u), sz[u] += sz[v], cmax( t, sz[v] );
	cmax( t, size - sz[u] );
	if ( t < mxp ) rt = u, mxp = t;
}
void dfs( int u, int fa, heap *h ){ h->push(dist(u, rt)); go( i, hd[u] ) if ( v != fa && !vis[v] ) dfs( v, u, h ); }
void Build( int u ){
	int t(size); h2[u].push(0), vis[u] = 1;
	if ( fa[u] ) rt = fa[u], dfs(u, 0, &h1[u]), h2[fa[u]].push(h1[u].top());
	go( i, hd[u] ) if ( !vis[v] ){
		size = sz[u] < sz[v] ? t - sz[u] : sz[v],
		mxp = INF, findrt(v, u), fa[rt] = u, Build(rt);
	} r.push(GetAns(u));
}
void Off( int x ){
	int c(x), d, t;
	r.erase(GetAns(x)), h2[x].push(0), r.push(GetAns(x));
	while( fa[c] ){
		t = h1[c].top(), h1[c].push(d = dist(fa[c], x));
		if ( d > t ){
			r.erase(GetAns(fa[c])), h2[fa[c]].erase(t);
			h2[fa[c]].push(d), r.push(GetAns(fa[c]));
		} c = fa[c];
	}
}
void On( int x ){
	int c(x), d, t;
	r.erase(GetAns(x)), h2[x].erase(0), r.push(GetAns(x));
	while( fa[c] ){
		t = h1[c].top(), h1[c].erase(dist(fa[c], x)), d = h1[c].top();
		if ( t != d ){
			r.erase(GetAns(fa[c])), h2[fa[c]].erase(t),
			h2[fa[c]].push(d), r.push(GetAns(fa[c]));
		} c = fa[c];
	}
}

signed main(){
	read(N); int x, y;
	fp( i, 1, N - 1 ) read(x), read(y), addedge( x, y ), addedge( y, x );
	lca::DFS(1), size = N, mxp = INF, findrt(1, 0), Build(rt);
	char opt; read(Q), ct = N;
	while( Q-- ){
		while( (opt = getchar()) != 'C' && opt != 'G' );
		if ( opt == 'G' ) printf( "%d\n", ct < 2 ? ct - 1 : r.top() );
		else{
			read(x);
			if ( on[x] ) Off(x), on[x] = 0, ++ct;
			else On(x), on[x] = 1, --ct;
		}
	}
	return 0;
}

