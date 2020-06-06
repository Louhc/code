#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define open(s) freopen( s".in", "r", stdin ), freopen( s".out", "w", stdout )
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline bool cmax( T &x, T y ){ return x < y ? x = y, 1 : 0; }
template<typename T> inline bool cmin( T &x, T y ){ return y < x ? x = y, 1 : 0; }

const int _ = 2e5 + 55;
int N, M, n, ans;
int h[_], rh[_], nxt[_<<1], to[_<<1], tot;
int in[_]; bool vs[_], vis1[_], vis2[_], vis[_];
queue<int> Q;
inline void addedge( int *hd, int x, int y ){
	nxt[++tot] = hd[x], hd[x] = tot, to[tot] = y;
}

bool flg; int o;
void DFS1( int u ){
	vis1[u] = vis[u] = 1;
	go( i, h[u] ) if ( !vis1[v] ){
		if ( v > o ) vs[v] = 1; else flg = 1;
		DFS1(v);
	}
}
void DFS2( int u ){
	vis2[u] = vis[u] = 1;
	go( i, rh[u] ) if ( !vis2[v] ){
		if ( v > o ) vs[v] = 1; else flg = 1;
		DFS2(v);
	}
}

int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> M; int x, y;
	fp( i, 1, M ) cin >> x >> y, addedge(h, x, y), addedge(rh, y, x), ++in[y];
	fp( i, 1, N ) if ( !in[i] ) Q.push(i);
	while( !Q.empty() ){
		int u(Q.front()); Q.pop(); ++n;
		go( i, h[u] ) if ( !--in[v] ) Q.push(v);
	}
	if ( n < N ) return printf( "-1\n" ), 0;
	fp( i, 1, N ){
		flg = vis[i], o = i, DFS1(i), DFS2(i);
		if ( !vs[i] ) ans += !(vs[i] = flg);
	}
	printf( "%d\n", ans );
	fp( i, 1, N ) printf(vs[i] ? "E" : "A");
	return 0;
}