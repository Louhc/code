#include<bits/stdc++.h>
#define u32 unsigned
#define i64 long long
#define u64 unsigned long long
#define f80 long double
#define rgt register
#define getchar() ( p1 == p2 && ( p2 = bf + fread( bf, 1, 1 << 21, stdin ), p1 = bf ) == p2 ? EOF : *p1++ )
using namespace std;
#define MAXN 100005
#define MAXM 500005

char bf[1 << 21], *p1, *p2;
template<typename T>
inline void read( rgt T &x ){ x = 0; rgt char t, flg(0);
	for ( t = getchar(); !isdigit(t); t = getchar() ) flg = t == '-';
	for ( ; isdigit(t); t = getchar() ) x = x * 10 + ( t & 15 ); x = flg ? -x : x;
}

clock_t __t_bg, __t_ed;
struct node{
	i64 v; int w; node(){} node( i64 x, int y ):v(x), w(y){}
	bool operator < ( const node &t )const{ return v > t.v; }
};
#define pi pair<node, int>
int N, M, K, T, itr[MAXN]; node dis[MAXN][2]; char vis[MAXN];
int hd[MAXN], nxt[MAXM], to[MAXM], val[MAXM], tot;
inline void add( int x, int y, int z ){ nxt[++tot] = hd[x], hd[x] = tot, to[tot] = y, val[tot] = z; }

priority_queue<pi> Q;

signed main(){
	__t_bg = clock();
	read(T);
	while( T-- ){
		read(N), read(M), read(K), memset( hd, 0, sizeof hd ), tot = 0;
		for ( rgt int i = 1, x, y, z; i <= M; ++i )
			read(x), read(y), read(z), add(x,y,z);
		memset( dis, 0x7f, sizeof dis ), memset( vis, 0, sizeof vis );
		for ( rgt int i = 1; i <= K; ++i ) read(itr[i]), Q.push(make_pair(dis[itr[i]][0] = node(0, itr[i]), itr[i]));
		while( !Q.empty() ){
			rgt int u(Q.top().second), w(Q.top().first.w);
			rgt i64 t(Q.top().first.v); Q.pop();
			if ( vis[u] >= 2 ) continue;
			++vis[u];
			for ( rgt int i = hd[u], v; i; i = nxt[i] ){
				v = to[i];
				if ( w != dis[v][0].w ){
					if ( dis[v][0].v > t + val[i] ) dis[v][1] = dis[v][0], dis[v][0] = node( t + val[i], w ), Q.push(make_pair(dis[v][0], v));
					else if ( dis[v][1].v > t + val[i] ) dis[v][1] = node( t + val[i], w ), Q.push(make_pair(dis[v][1], v));
				} else if ( dis[v][0].v > t + val[i] ) dis[v][0].v = t + val[i], Q.push(make_pair(dis[v][0], v));
			}
		} rgt i64 ans(LONG_LONG_MAX);
		for ( rgt int i = 1; i <= K; ++i ) ans = min( ans, dis[itr[i]][1].v );
		printf( "%lld\n", ans );
	}
	__t_ed = clock(), fprintf( stderr, "time: %.5lfs\n", double( __t_ed - __t_bg ) / CLOCKS_PER_SEC );
	return 0;
}