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

const int MAXN = 5e5 + 15;
int N, M;
vector<int> e[MAXN];
int d[MAXN];
bool in[MAXN];

namespace solver1{
	void solve( int u = 1 ){
		d[u] = 1, printf( "%d ", u );
		for ( int v : e[u] ) if ( !d[v] ) solve(v);
	}
}
namespace solver2{
	int op, ed, o;
	bool DFS_C( int u, int fa ){
		for ( int v : e[u] ) if ( v != fa ){
			if ( d[v] ) return op = v, ed = u, in[u] = 1;
			d[v] = d[u] + 1;
			if ( DFS_C( v, u ) ) return d[u] >= d[op] ? in[u] = 1 : 1;
		} else fa = 0;
		return 0;
	}
	void DFS1( int u ){
		d[u] = 1, printf( "%d ", u );
		for ( int v : e[u] ) if ( !d[v] ) DFS1(v);
	}
	void DFS2( int u, int l ){
		d[u] = 1, printf( "%d ", u );
		int flg(0), t(1e9);
		for ( int v : e[u] ) if ( !d[v] ){
			if ( !in[v] || flg ){
				if ( flg ){ t = v; break; }
				else DFS1(v);
			} else flg = v;
		} if ( o && t == 1e9 && l < flg ) return o = 0, void();
		for ( int v : e[u] ) if ( !d[v] )
			in[v] ? DFS2(v, t == 1e9 ? l : t) : DFS1(v);
	}
	void DFS( int u ){
		d[u] = 1, printf( "%d ", u );
		for ( int v : e[u] ) if ( !d[v] )
			in[v] ? DFS2(v, 1e9) : DFS(v);
	}
	void solve(){
		DFS_C(1, 0), memset( d, 0, sizeof d ), o = 1;
		if ( in[1] ) DFS2(1, 1e9); else DFS(1);
		
		fp( i, 1, N ) if ( !d[i] ) cerr << i << endl;
	}
}

signed main(){
//	freopen( "in", "r", stdin );
//	freopen( "out", "w", stdout );	
	read(N), read(M); int x, y;
	fp( i, 1, M ) read(x), read(y), e[x].push_back(y), e[y].push_back(x);
	fp( i, 1, N ) sort( e[i].begin(), e[i].end() );
	if ( M < N ) solver1::solve();
	else solver2::solve();
	return 0;
}

