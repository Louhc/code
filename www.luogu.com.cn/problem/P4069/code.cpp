#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define open(s) freopen( s".in", "r", stdin ), freopen( s".out", "w", stdout )
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline bool cmax( T &x, T y ){ return x < y ? x = y, 1 : 0; }
template<typename T> inline bool cmin( T &x, T y ){ return y < x ? x = y, 1 : 0; }

int N, M;
int hd[_], nxt[_<<1], to[_<<1], val[_<<1], tot;
int fa[_], sz[_], son[_], sg[_], num, tp[_], dep[_]; i64 w[_];

inline void addedge( int x, int y, int z ){
	nxt[++tot] = hd[x], hd[x] = tot, to[tot] = y, val[tot] = z;
}

void DFS1( int u ){
	sz[u] = 1, dep[u] = dep[fa[u]] + 1;
	go( i, hd[u] ) if ( v != fa[u] ){
		fa[v] = u; DFS1(v); sz[u] += sz[v];
		if ( sz[v] > sz[son[u]] ) son[u] = v, w[v] = w[u] + val[i];
	}
}

void DFS2( int u ){
	sg[u] = ++num;
	if ( son[u] ) tp[v] = tp[u], DFS2(v);
	go( i, hd[u] ) if ( !sg[v] ) tp[v] = v, w[v] = 0, DFS2(v);
}

int k[_<<1], b[_<<1];

i64 calc( int i, i64 x ){
	return x * k[i] + b[i];
}

void Modi( int c, int l, int r, int i ){
	const int mid((l + r) >> 1), ls(c << 1), rs(ls | 1);
	if ( k[i] == k[tr[c]] ){
		if ( b[i] > b[tr[c]] ) tr[c] = i;
		return;
	} else if ( k[i] < k[tr[c]] ){
		if ( calc(i, w[mid]) < calc(tr[c], w[mid]) ) Modi(ls, l, mid, i);
		else Modi(rs, mid + 1, r, tr[c]), tr[c] = i;
	} else if ( k[i] > k[tr[c]] ){
		if ( calc(i, w[mid]) < calc(tr[c], w[mid]) ) Modi(rs, mid + 1, r, i);
		else Modi(ls, l, mid, tr[c]), tr[c] = i;
	}
}

void Modify( int c, int l, int r, int L, int R, int i ){
	if ( L <= l && r <= R ) return Modi( c, l, r, i );
	if ( l > R || L > r ) return;
	const int mid((l + r) >> 1), ls(c << 1), rs(ls | 1);
	Modify(ls, l, mid, L, R, i), Modify(rs, mid + 1, r, L, R, i);
}

void Change( int x, int y ){
	while( tp[x] != tp[y] ){
		if ( dep[tp[x]] > dep[tp[y]] ) x = fa[tp[x]];
		else y = fa[tp[y]];
	}
	
}

int main(){
	scanf( "%d%d", &N, &M ); int x, y, z;
	fp( i, 2, N ) scanf( "%d%d%d", &x, &y, &z ), addedge(x, y, z), addedge(y, x, z);
	DFS1(1), DFS2(tp[1] = 1);
	return 0;
}