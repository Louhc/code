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

const int MAXN = 1e5 + 5;
int N, M, K;
int a[MAXN][10];
struct node{
	int w, n; i64 v; node(){}
	node( int x, int y, i64 z ):w(x), n(y), v(z){}
	bool operator < ( const node &t )const{ return v < t.v; }
};
priority_queue<node> Q;
inline i64 calc( int w, int n ){
	i64 c(1), ans(0);
	fp( i, 0, K ) ans += a[w][i] * c, c *= n;
	return ans;
}

signed main(){
	read(N), read(M), read(K);
	fp( i, 1, M ){
		fp( j, 0, K ) read(a[i][j]);
		Q.push(node(i, 1, -calc(i, 1)));
	}
	while( --N ){
		node t(Q.top()); Q.pop();
		t.v = -calc(t.w, ++t.n);
		Q.push(t);
	} printf( "%lld\n", -Q.top().v );
	return 0;
}

