#include<bits/stdc++.h>
using namespace std;
// #pragma GCC optimize(2)
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define go( i, b ) for ( register int i(b), v(to[b]); i; v = to[i = nxt[i]] )
void cmax( int &x, int y ){ x < y ? x = y, 1 : 0; }

const int _ = 1e5 + 55;
int N, a[_];
int hd[_], nxt[_<<1], to[_<<1], tot;
bool vis[_*3];
set<int> S;

void addedge( int x, int y ){
	nxt[++tot] = hd[x], hd[x] = tot, to[tot] = y;
}

int ans;
int DFS( int u, int fa, int o ){
	vis[u] = 1;
	int mx(1);
	go( i, hd[u] ) if ( v != fa && a[v] % o == 0 ){
		int t = DFS(v, u, o);
		cmax(ans, mx + t);
		cmax(mx, t + 1);
	} return mx;
}

int main(){
	freopen("gtree4.in", "r", stdin);
	scanf( "%d", &N ); int x, y;
	fp( i, 2, N ) scanf( "%d%d", &x, &y ), addedge(x, y), addedge(y, x);
	fp( i, 1, N ) scanf( "%d", a + i );
	fp( i, 1, N ){
		int x = a[i];
		for ( register int j = 2; j * j <= x; ++j ){
			if ( x % j == 0 ){
				S.insert(j);
				while( x % j == 0 ) x /= j;
			}
		} if ( x > 1 ) S.insert(x);
	}
	int ti = clock();
	for ( register int x : S ){
		fp( i, 1, N ) vis[i] = 0;
		fp( i, 1, N ) if ( !vis[i] && a[i] % x == 0 ) DFS(i, 0, x);
	} printf( "%d\n", ans );
	cerr << clock() - ti << endl;
	return 0;
}