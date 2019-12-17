#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define rgt register
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline bool cmax( T &x, T y ){ return x < y ? x = y, 1 : 0; }
template<typename T> inline bool cmin( T &x, T y ){ return y < x ? x = y, 1 : 0; }
#define getchar() ( p1 == p2 && ( p1 = bf, p2 = bf + fread( bf, 1, 1 << 21, stdin ), p1 == p2 ) ? EOF : *p1++ )
char bf[1 << 21], *p1(bf), *p2(bf);
template<typename T>
inline void read( T &x ){ char t(getchar()), flg(0); x = 0;
	for ( ; !isdigit(t); t = getchar() ) flg = t == '-';
	for ( ; isdigit(t); t = getchar() ) x = x * 10 + ( t & 15 );
	flg ? x = -x : x;
}

const int _ = 300055;
int T, N;
int hd[_], nxt[_<<1], to[_<<1], tot;
int sz[_], f[_][20], sn1[_], sn2[_];
int _sz[_];

inline void addedge( int x, int y ){
	nxt[++tot] = hd[x], hd[x] = tot, to[tot] = y,
	nxt[++tot] = hd[y], hd[y] = tot, to[tot] = x;
}

void DFS1( int u, int fa ){
	sz[u] = 1, sn1[u] = sn2[u] = 0;
	go( i, hd[u] ) if ( fa ^ v ){
		DFS1(v, u), sz[u] += sz[v];
		if ( sz[v] > sz[sn1[u]] ) sn2[u] = sn1[u], sn1[u] = v;
		else if ( sz[v] > sz[sn2[u]] ) sn2[u] = v;
	} f[u][0] = sn1[u]; fp( i, 1, 18 ) f[u][i] = f[f[u][i - 1]][i - 1];
}

i64 ans;
inline int get( int x, int n ){ return max(_sz[f[x][0]], n - _sz[x]) <= (n >> 1) ? x : 0; }

void DFS2( int u, int fa ){
	go( j, hd[u] ) if ( v != fa ){
		_sz[u] = N - _sz[v];
		if ( _sz[fa] > _sz[sn1[u]] || (sn1[u] == v && _sz[fa] > _sz[sn2[u]]) ) f[u][0] = fa;
		else if ( sn1[u] == v ) f[u][0] = sn2[u]; else f[u][0] = sn1[u];
		fp( i, 1, 18 ) f[u][i] = f[f[u][i - 1]][i - 1];
		int n, t;
		n = _sz[v] >> 1, t = v;
		fd( i, 18, 0 ) if ( _sz[f[f[t][i]][0]] > n ) t = f[t][i];
		if ( _sz[f[t][0]] > n ) t = f[t][0];
		ans += get(t, _sz[v]) + get(f[t][0], _sz[v]);
		n = _sz[u] >> 1, t = u;
		fd( i, 18, 0 ) if ( _sz[f[f[t][i]][0]] > n ) t = f[t][i];
		if ( _sz[f[t][0]] > n ) t = f[t][0];
		ans += get(t, _sz[u]) + get(f[t][0], _sz[u]);
		DFS2(v, u);
	}
	_sz[u] = sz[u], f[u][0] = sn1[u]; // ¸Ä»ØÈ¥ 
	fp( i, 1, 18 ) f[u][i] = f[f[u][i - 1]][i - 1];
}

signed main(){
	read(T); int x, y;
	while( T-- ){
		ans = 0, memset( hd, 0, sizeof hd ), tot = 1;
		read(N); fp( i, 2, N ) read(x), read(y), addedge(x, y);
		DFS1(1, 0), memcpy( _sz, sz, sizeof sz ), DFS2(1, 0);
		printf( "%lld\n", ans );
	}
	return 0;
}


