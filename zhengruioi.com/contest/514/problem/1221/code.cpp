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
/*
d 增加的权值
d1 x的儿子数
d2 x的孙子数
sz x的大小
r x的答案(不包括某些贡献
f 儿子节点 sz[y] * d1[y] 之和
*/
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
	open("data");
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> Q;
	fp( i, 2, N ) cin >> fa[i], addedge(fa[i], i), ++d1[fa[i]];
	fp( i, 1, N ) cin >> w[i];
	DFS(1), tp[1] = 1, DFS2(1);
	while( Q-- ){
		int opt, x; u32 y;
		cin >> opt >> x;
		if ( opt & 1 ){
			cin >> y, d[x] += y,
			r[x] += y * (2 + sz[x] * (d1[x] + d2[x]) - f[x]);
			Add(x, y);
		} else {
			u32 ans(r[x] + d[fa[fa[x]]] * (sz[x] + 1) + d[fa[x]] * (d1[x] * sz[x] + 2));
			// 原有的贡献 + 爷爷的贡献 + 爸爸的贡献
			if ( sn[x] ) ans += (Get(sg[sn[x]] + sz[sn[x]] - 1) - Get(sg[sn[x]])) * (1 + d1[x] + d2[x]) * (sz[x] - sz[sn[x]]);
			// 重儿子子树内的贡献
			cout << ans << endl;
		}
	}
	return 0;
}
