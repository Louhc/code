#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline bool cmax( T &x, T y ){ return x < y ? x = y, 1 : 0; }
template<typename T> inline bool cmin( T &x, T y ){ return y < x ? x = y, 1 : 0; }

const int _ = 1e5 + 55;
int N, M, K;
vector<int> e[_];

namespace Tree{
	vector<int> a[2];
	void DFS( int u, int fa, int o ){
		a[o].push_back(u);
		for ( int v : e[u] ) if ( v != fa ) DFS(v, u, o ^ 1);
	}
	void solve(){
		DFS(1, 0, 0);
		if ( a[0].size() >= ((K + 1) >> 1) ){
			printf("1\n"); for ( int i = 0; i < ((K + 1) >> 1); ++i ) printf( "%d ", a[0][i] );
		} else {
			printf("1\n"); for ( int i = 0; i < ((K + 1) >> 1); ++i ) printf( "%d ", a[1][i] );
		}
	}
}

namespace Circle{
	int o[_], rk[_], n, b;
	bool vis[_];
	void DFS( int u, int fa ){
		o[rk[u] = ++n] = u, vis[u] = 1;
		for ( int v : e[u] ) if ( v != fa ){
			if ( vis[v] ) b = rk[v]; else DFS(v, u);
			if ( b ) return;
		} --n;
	}
	int lp[_]; bool in[_];
	void solve(){
		DFS(1, 0);
		fp( i, b, n ) lp[o[i]] = o[i - 1], in[o[i]] = 1;
		lp[o[b]] = o[n];
		fp( u, 1, N ) for ( int v : e[u] ) if ( in[u] && in[v] && lp[u] != v && lp[v] != u ){
			for ( int i = u; i != v; i = lp[i] ) in[i] = 0;
			in[u] = in[v] = 1, lp[u] = v;
		}
		int cnt(0);
		fp( i, 1, N ) cnt += in[i], in[i] ? b = i : 0;
		if ( cnt <= K ){
			printf( "2\n%d\n%d ", cnt, b ); for ( int i = lp[b]; i != b; i = lp[i] ) printf( "%d ", i );
		} else {
			printf( "1\n" ); int x(b); fp( i, 1, ((K + 1) >> 1) ) printf( "%d ", x ), x = lp[lp[x]];
		}
	}
}

int main(){
	scanf( "%d%d%d", &N, &M, &K ); int x, y;
	fp( i, 1, M ) scanf( "%d%d", &x, &y ), e[x].push_back(y), e[y].push_back(x);
	if ( M == N - 1 ) Tree::solve();
	else Circle::solve();
	return 0;
}
