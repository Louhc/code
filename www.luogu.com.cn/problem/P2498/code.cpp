#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define open(s) freopen( s".in", "r", stdin ), freopen( s".out", "w", stdout )
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline void cmax( T &x, T y ){ x < y ? x = y : x; }
template<typename T> inline void cmin( T &x, T y ){ y < x ? x = y : x; }
#define getchar() ( p1 == p2 && ( p1 = bf, p2 = bf + fread( bf, 1, 1 << 21, stdin ), p1 == p2 ) ? EOF : *p1++ )
char bf[1 << 21], *p1(bf), *p2(bf);
template<typename T>
inline void read( T &x ){ char t(getchar()), flg(0); x = 0;
        for ( ; !isdigit(t); t = getchar() ) flg = t == '-';
        for ( ; isdigit(t); t = getchar() ) x = x * 10 + ( t & 15 );
        flg ? x = -x : x;
}

const int _ = 3015;
int N, R, C;
int a[_][2];

double sqr( int x ){ return 1. * x * x; }
double dist( int x, int y, int xx, int yy ){ return sqr(x - xx) +sqr(y - yy); }
inline bool check( double r ){
	double t(4 * r * r); static queue<int> Q; static bool vis[_];
	while( !Q.empty() ) Q.pop(); memset( vis, 0, sizeof vis );
	fp( i, 1, N ) if ( a[i][0] < r || C - a[i][1] < r ) Q.push(i), vis[i] = 1;
	while( !Q.empty() ){
		int u(Q.front()); Q.pop();
		if ( R - a[u][0] < r || a[u][1] < r ) return 0;
		fp( v, 1, N ) if ( !vis[v] && dist(a[u][0], a[u][1], a[v][0], a[v][1]) < t )
			vis[v] = 1, Q.push(v);
	} return 1;
}

int main(){
	// open("data");
	read(N), read(R), read(C), --R, --C;
	fp( i, 1, N ) read(a[i][0]), read(a[i][1]), --a[i][0], --a[i][1];
	double l(0), r(min(R, C)), mid;
	fp( i, 0, 60 ){
		mid = (l + r) / 2;
		if ( check(mid) ) l = mid;
		else r = mid;
	} printf( "%.2f\n", l );
	return 0;
}