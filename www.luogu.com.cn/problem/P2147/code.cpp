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

int N, M;
namespace LCT{
	const int _ = 1e4 + 55;
	int ch[_][2], f[_]; bool tg[_];
	inline void swp( int &x, int &y ){
		x^=y^=x^=y;
	}
	inline void flip( int x ){
		swp( ch[x][0], ch[x][1] ), tg[x] ^= 1;
	}
	inline void pushdown( int x ){
		if ( tg[x] ) tg[x] = 0, ch[x][0] ? flip(ch[x][0]) : void(), ch[x][1] ? flip(ch[x][1]) : void();
	}
	inline int check( int x ){
		return ch[f[x]][0] == x || ch[f[x]][1] == x;
	}
	inline int get( int x ){
		return ch[f[x]][1] == x;
	}
	inline void rotate( int x ){
		int y(f[x]), z(f[y]), t(get(x)), o(ch[x][!t]);
		f[x] = z; if ( check(y) ) ch[z][get(y)] = x;
		ch[y][t] = o; if ( o ) f[o] = y;
		f[y] = x, ch[x][!t] = y;
	}
	inline void splay( int x ){
		static int S[_], tp; int y = S[tp = 1] = x;
		while( check(y) ) S[++tp] = y = f[y];
		while( tp ) pushdown(S[tp--]);
		while( check(x) ) y = f[x], check(y) ? rotate(get(x) == get(y) ? y : x) : void(), rotate(x);
	}
	inline void access( int x ){
		for ( int y = 0; x; y = x, x = f[x] )
			splay(x), ch[x][1] = y;
	}
	inline void makeroot( int x ){
		access(x), splay(x), flip(x);
	}
	inline int findroot( int x ){
		access(x), splay(x);
		while( ch[x][0] ) pushdown(x), x = ch[x][0];
		splay(x); return x;
	}
	inline void split( int x, int y ){
		makeroot(x), access(y), splay(y);
	}
	inline void link( int x, int y ){
		makeroot(x), f[x] = y;
	}
	inline  void cut( int x, int y ){
		split(x, y), ch[y][0] = f[x] = 0;
	}
} using namespace LCT;

int main(){
	read(N), read(M);
	while( M-- ){
		char t(getchar()); while( t > 'Z' || t < 'A' ) t = getchar();
		int x, y; read(x), read(y);
		if ( t == 'Q' ) printf( findroot(x) == findroot(y) ? "Yes\n" : "No\n" );
		else if ( t == 'C' ) link(x, y); else if ( t == 'D' ) cut(x, y);
	}
	return 0;
}