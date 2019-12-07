#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define f80 long double
#define rgt register
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline bool cmax( T &x, T y ){ return x < y ? x = y, 1 : 0; }
template<typename T> inline bool cmin( T &x, T y ){ return y < x ? x = y, 1 : 0; }
//#define getchar() ( p1 == p2 && ( p1 = bf, p2 = bf + fread( bf, 1, 1 << 21, stdin ), p1 == p2 ) ? EOF : *p1++ )
char bf[1 << 21], *p1(bf), *p2(bf);
template<typename T>
inline void read( T &x ){ char t(getchar()), flg(0); x = 0;
	for ( ; !isdigit(t); t = getchar() ) flg = t == '-';
	for ( ; isdigit(t); t = getchar() ) x = x * 10 + ( t & 15 );
	flg ? x = -x : x;
}

int N = 100, M = 300;
set<pair<int, int> > S;

struct edge{
	int x, y;
	bool operator < ( const edge &t )const{ return y == t.y ? x < t.x : y < t.y; }
	edge( int a = 0, int b = 0 ){
		x = a, y = b;
	}
};

struct G{
	int n;
	edge e[10000];
	set<edge> S;
	bool ins( int x, int y ){
		if ( S.count(edge(x, y)) ) return 0;
		if ( x == y ) return 0;
		e[++n] = edge(x, y);
		S.insert(edge(x, y));
		return 1;
	}
	void print(){
		fp( i, 1, n ){
			printf( "%d %d\n", e[i].x, e[i].y );
		}
	}
}g1, g2;

signed main(){
	srand(time(0));
//	freopen( "input.txt", "w", stdout );
	printf( "%d %d\n", N, M );
	fp( i, 2, N ) g1.ins(i, rand() % (i - 1) + 1);
	fp( i, 1, N - 1 ) g2.ins(i, N - rand() % (N - i));	
	fp( i, 1, M - N + 1 ){
		while( !g1.ins(rand() % N + 1, rand() % N + 1));
		while( !g2.ins(rand() % N + 1, rand() % N + 1));
	} g1.print(), g2.print();
	return 0;
}


