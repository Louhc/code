#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define u32 unsigned
#define open(s) freopen( s".in", "r", stdin ), freopen( s".out", "w", stdout )
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline bool cmax( T &x, T y ){ return x < y ? x = y, 1 : 0; }

u32 s;
inline u32 get(){ return s ^= s << 13, s ^= s >> 17, s ^= s << 5; }

const int _ = 5e5 + 55;
int N, Q, fa[_][20], lg[_], lastans; i64 ans;
int hd[_], nxt[_], to[_], tot;
int d[_], sn[_], tp[_], len[_], *f[_], pool[_ << 1], *p = pool;
inline void addedge( int x, int y ){
	nxt[++tot] = hd[x], hd[x] = tot, to[tot] = y;
}
void DFS1( int u ){
	fp( i, 1, 18 ) fa[u][i] = fa[fa[u][i - 1]][i - 1];
	len[u] = 1, sn[u] = 0, tp[u] = u;
	go( i, hd[u] ){
		d[v] = d[u] + 1, DFS1(v);
		if ( cmax(len[u], len[v] + 1) ) sn[u] = v;
	} tp[sn[u]] = u;
}

void DFS2( int u ){
	if ( tp[u] == u ){
		f[u] = p + len[u] - 1, p += len[u] << 1, *f[u] = u;
		fp( i, 1, len[u] ) *(f[u] + i) = fa[*(f[u] + i - 1)][0];
		fp( i, 1, len[u] - 1 ) *(f[u] - i) = sn[*(f[u] - i + 1)];
	}
	go( i, hd[u] ){
		if ( tp[v] == u ) tp[v] = tp[u];
		DFS2(v);
	}
}

int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> Q >> s;
	fp( i, 1, N ) cin >> fa[i][0], addedge(fa[i][0], i);
	fp( i, 2, N ) lg[i] = lg[i >> 1] + 1;
	d[to[hd[0]]] = 1, DFS1(to[hd[0]]), DFS2(to[hd[0]]);
	fp( i, 1, Q ){
		int x = (get() ^ lastans) % N + 1, k = (get() ^ lastans) % d[x], t = lg[k];
		if ( k == 0 ){ ans ^= (i64)(lastans = x) * i; continue; }
		k -= 1 << t, x = fa[x][t];
		ans ^= (i64)(lastans = *(f[tp[x]] + d[tp[x]] - d[x] + k)) * i;
	} cout << ans << endl;
	return 0;
}