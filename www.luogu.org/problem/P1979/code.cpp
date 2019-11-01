#include<bits/stdc++.h>
using namespace std;
#if __cplusplus >= 201103L
template<class ...Args> inline int err( Args ...args ){ return fprintf( stderr, args... ); }
#else
#define err(...) 1
#endif
#define i64 long long
#define f80 long double
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

const int dx[] = { 1, -1, 0, 0 }, dy[] = { 0, 0, 1, -1 };
int N, M, T;
int a[35][35], hd[4005], nxt[100005], to[100005], val[100005], tot;
int dis[4005]; bool vis[4005];
inline int ID( int x, int y ){ return ( ( x - 1 ) * M + y - 1 ) << 2; }
inline void addedge( int x, int y, int z ){ nxt[++tot] = hd[x], hd[x] = tot, to[tot] = y, val[tot] = z; }
struct node{ int x, y; node(){} node( int a, int b ):x(a), y(b){} };
queue<node> Q; queue<int> q; int d[35][35];
inline void calc( int ax, int ay, int bx, int by ){ // 指定棋子位置(ax,ay),空白棋子位置(bx,by)
	memset( d, -1, sizeof d );
	Q.push(node(bx, by)), d[ax][ay] = 1, d[bx][by] = 0;
	while( Q.size() ){
		node t(Q.front()), c; Q.pop();
		fp( i, 0, 3 ){
			c.x = t.x + dx[i], c.y = t.y + dy[i];
			if ( a[c.x][c.y] && d[c.x][c.y] == -1 )
				d[c.x][c.y] = d[t.x][t.y] + 1, Q.push(c);
		}
	}
}
inline void Add( int ax, int ay, int dr ){
	int t(ID(ax, ay)|dr);
	fp( i, 0, 3 ){
		int tx(ax + dx[i]), ty(ay + dy[i]), c(ID(ax, ay)|i);
		if ( !a[tx][ty] || d[tx][ty] <= 0 ) continue;
		addedge( t, c, d[tx][ty] );
	}
}

signed main(){
	read(N), read(M), read(T);
	fp( i, 1, N ) fp( j, 1, M ) read(a[i][j]);
	fp( i, 1, N ) fp( j, 1, M ) if ( a[i][j] ){
		if ( a[i + 1][j] ) calc(i, j, i + 1, j), Add(i, j, 0), addedge( ID(i,j)|0, ID(i+1,j)|1, 1 );
		if ( a[i - 1][j] ) calc(i, j, i - 1, j), Add(i, j, 1), addedge( ID(i,j)|1, ID(i-1,j)|0, 1 );
		if ( a[i][j + 1] ) calc(i, j, i, j + 1), Add(i, j, 2), addedge( ID(i,j)|2, ID(i,j+1)|3, 1 );
		if ( a[i][j - 1] ) calc(i, j, i, j - 1), Add(i, j, 3), addedge( ID(i,j)|3, ID(i,j-1)|2, 1 );
	}
	while( T-- ){
		int ex, ey, sx, sy, tx, ty;
		read(ex), read(ey), read(sx), read(sy), read(tx), read(ty);
		if ( sx == tx && sy == ty ){ printf("0\n"); continue; }
		calc(sx, sy, ex, ey), memset( dis, 0x3f, sizeof dis );
		fp( i, 0, 3 ){
			int tx(sx + dx[i]), ty(sy + dy[i]), t(ID(sx,sy)|i);
			if ( d[tx][ty] >= 0 ) dis[t] = d[tx][ty], q.push(t), vis[t] = 1;
		}
		while( !q.empty() ){
			int u(q.front()); q.pop(); vis[u] = 0;
			go( i, hd[u] ) if ( dis[v] > dis[u] + val[i] ){
				dis[v] = dis[u] + val[i]; if ( !vis[v] ) q.push(v), vis[v] = 1;
			}
		} int res(min(min(dis[ID(tx,ty)|0], dis[ID(tx,ty)|1]), min(dis[ID(tx,ty)|2], dis[ID(tx,ty)|3])));
		printf( "%d\n", res >= 1e9 ? -1 : res );
	}
	return 0;
}


