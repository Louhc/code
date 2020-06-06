#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define go( i, b ) for ( int i(b), v(to[b]); i; v = to[i = nxt[i]] )

const int _ = 1e5 + 55;
int N, M, Q, S, num;
int w[_<<2];
int hd[10 * _], nxt[_ * 25], to[_ * 25], val[_ * 25], tot;
priority_queue<pair<i64, int> > q;
i64 d[10 * _]; bool vis[10 * _];

void addedge( int x, int y, int z = 0 ){
	nxt[++tot] = hd[x], hd[x] = tot, to[tot] = y, val[tot] = z;
}

void Build( int c, int l, int r ){
	w[c] = ++num;
	if ( l == r ) return addedge(w[c], l), addedge(l, w[c] + M);
	const int mid((l + r) >> 1), ls(c << 1), rs(ls | 1);
	Build(ls, l, mid), Build(rs, mid + 1, r);
	addedge(w[c], w[ls]), addedge(w[ls] + M, w[c] + M);
	addedge(w[c], w[rs]), addedge(w[rs] + M, w[c] + M);
}

void Add1( int c, int l, int r, int L, int R, int x, int y ){
	if ( L <= l && r <= R ) return addedge(x, w[c], y);
	if ( l > R || L > r ) return;
	const int mid((l + r) >> 1), ls(c << 1), rs(ls | 1);
	Add1(ls, l, mid, L, R, x, y), Add1(rs, mid + 1, r, L, R, x, y);
}

void Add2( int c, int l, int r, int L, int R, int x, int y ){
	if ( L <= l && r <= R ) return addedge(w[c] + M, x, y);
	if ( l > R || L > r ) return;
	const int mid((l + r) >> 1), ls(c << 1), rs(ls | 1);
	Add2(ls, l, mid, L, R, x, y), Add2(rs, mid + 1, r, L, R, x, y);
}


int main(){
	scanf( "%d%d%d", &N, &Q, &S );
	num = N, M = N * 3;
	int opt, x, y, z, w;
	Build(1, 1, N);
	while( Q-- ){
		scanf( "%d", &opt );
		if ( opt == 1 ){
			scanf( "%d%d%d", &x, &y, &w );
			addedge(x, y, w);
		} else if ( opt == 2 ){
			scanf( "%d%d%d%d", &x, &y, &z, &w );
			Add1(1, 1, N, y, z, x, w);
		} else {
			scanf( "%d%d%d%d", &x, &y, &z, &w );
			Add2(1, 1, N, y, z, x, w);
		}
	}
	memset(d, 0x7f, sizeof d);
	q.push(make_pair(d[S] = 0, S));
	while( !q.empty() ){
		int u(q.top().second); q.pop();
		if ( vis[u] ) continue;
		vis[u] = 1;
		go( i, hd[u] ) if ( !vis[v] && d[v] > d[u] + val[i] )
			d[v] = d[u] + val[i], q.push(make_pair(-d[v], v));
	}
	fp( i, 1, N ) printf( "%lld ", d[i] >= 1e18 ? -1ll : d[i] );
	return 0;
}