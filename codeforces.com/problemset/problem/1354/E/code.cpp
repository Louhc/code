#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define open(s) freopen( s".in", "r", stdin ), freopen( s".out", "w", stdout )
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline bool cmax( T &x, T y ){ return x < y ? x = y, 1 : 0; }
template<typename T> inline bool cmin( T &x, T y ){ return y < x ? x = y, 1 : 0; }

const int _ = 5e3 + 55, __ = 2e5 + 55;
int N, M, n1, n2, n3, vis[_];
int hd[_], nxt[__], to[__], tot(1);
bitset<_> f[_]; int n;
vector<int> v1[_], v2[_];
inline void addedge( int x, int y ){
	nxt[++tot] = hd[x], hd[x] = tot, to[tot] = y;
}

void DFS( int u, int c ){
	vis[u] = c; (c == 1 ? v1[n] : v2[n]).push_back(u);
	go( i, hd[u] ) if ( !vis[v] ) DFS(v, 3 - c); else if ( c + vis[v] != 3 ) printf("NO\n"), exit(0);
}

bool ans[_];

int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	scanf( "%d%d%d%d%d", &N, &M, &n1, &n2, &n3 ); int x, y;
	fp( i, 1, M ) scanf( "%d%d", &x, &y ), addedge(x, y), addedge(y, x);
	f[0][0] = 1;
	fp( i, 1, N ) if ( !vis[i] )
		++n, DFS(i, 1), f[n] = (f[n - 1] << v1[n].size()) | (f[n - 1] << v2[n].size());
	if ( !f[n][n2] ) return printf("NO\n"), 0;
	fd( i, n, 1 ){
		if ( n2 >= v1[i].size() && f[i - 1][n2 - v1[i].size()] ){
			for ( int j : v1[i] ) ans[j] = 1; n2 -= v1[i].size();
		} else if ( n2 >= v2[i].size() && f[i - 1][n2 - v2[i].size()] ){
			for ( int j : v2[i] ) ans[j] = 1; n2 -= v2[i].size();
		}
	}
	printf("YES\n");
	fp( i, 1, N ){
		if ( ans[i] ) printf("2");
		else if ( n1 ) --n1, printf("1");
		else printf("3");
	} printf("\n");
	return 0;
}