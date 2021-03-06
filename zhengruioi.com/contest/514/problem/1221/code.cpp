#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define u32 unsigned
#define open(s) freopen( s".in", "r", stdin ), freopen( s".out", "w", stdout )
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline void cmax( T &x, T y ){ x < y ? x = y : x; }
template<typename T> inline void cmin( T &x, T y ){ y < x ? x = y : x; }

const u32 _ = 3e5 + 55;
int N, Q, fa[_], sn[_], tp[_], sg[_], num;
int hd[_], nxt[_], to[_], tot; 
u32 w[_], d[_], d1[_], d2[_], sz[_], r[_], f[_], c[_];

inline void addedge( int x, int y ){
	nxt[++tot] = hd[x], hd[x] = tot, to[tot] = y;
}

inline void Add( int x, u32 y ){ for ( ; x <= N; x += x & -x ) c[x] += y; }
inline u32 Get( int x ){ u32 ans(0); for ( ; x; x -= x & -x ) ans += c[x]; return ans; }

u32 DFS( int u ){
	u32 sum(0), t; sz[u] = 1;
	go( i, hd[u] ){
		sum += t = DFS(v), r[u] -= sz[v] * t,
		d2[u] += d1[v], sz[u] += sz[v];
		if ( sz[v] > sz[sn[u]] ) sn[u] = v;
	} r[u] += sz[u] * sum + w[u] * (sz[u] + 1),
	f[fa[u]] += sz[u] * d1[u];
	return sum + w[u];
}
void DFS2( int u ){
	sg[u] = ++num; if ( sn[u] ) tp[sn[u]] = tp[u], DFS2(sn[u]);
	go( i, hd[u] ) if ( !sg[v] ) tp[v] = v, DFS2(v);
}

signed main(){
//	freopen( "data.in", "r", stdin );
//	freopen( "data.out", "w", stdout );
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> Q;
	fp( i, 2, N ) cin >> fa[i], addedge(fa[i], i), ++d1[fa[i]];
	fp( i, 1, N ) cin >> w[i];
	DFS(1), tp[1] = 1, DFS2(1);
	int opt, x; u32 y, t, ans;
	while( Q-- ){
		cin >> opt >> x;
		if ( opt & 1 ){
			cin >> y,
			d[x] += y,
			r[x] += y * (2 + sz[x] * (d1[x] + d2[x]) - f[x]);
			Add(sg[x], t = y * (1 + d1[x] + d2[x]));
			for ( int p = tp[x]; p > 1; p = tp[fa[p]] )
				r[fa[p]] += t * (sz[fa[p]] - sz[p]);
		} else {
			ans = r[x] + d[fa[fa[x]]] * (sz[x] + 1) + d[fa[x]] * (d1[x] * sz[x] + 2);
			if ( sn[x] ) ans += (Get(sg[sn[x]] + sz[sn[x]] - 1) - Get(sg[sn[x]] - 1)) * (sz[x] - sz[sn[x]]);
			printf( "%u\n", ans );
		}
	}
	return 0;
}
