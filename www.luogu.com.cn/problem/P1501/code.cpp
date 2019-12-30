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

namespace LCT{
	const int _ = 2e5 + 55;
	int ch[_][2], f[_], v[_]; unsigned t1[_], t2[_], s[_]; bool tg[_];
	inline void pushup( int x ){
		s[x] = s[ch[x][0]] + s[ch[x][1]] + v[x];
	}
	inline void swp( int &x, int &y ){
		x ^= y ^= x ^= y;
	}
	inline void flip( int x ){
		tg[x] ^= 1, swp( ch[x][0], ch[x][1] );
	}
	inline void pushdown( int x ){
		if ( tg[x] ) tg[x] = 0, ch[x][0] ? flip(ch[x][0]) : void(), ch[x][1] ? flip(ch[x][1]) : void();
	}
	inline int get( int x ){
		return ch[f[x]][1] == x;
	}
	inline int check( int x ){
		return ch[f[x]][0] == x || ch[f[x]][1] == x;
	}
	inline void rotate( int x ){
		int y(f[x]), z(f[y]), t(get(x)), o(ch[x][!t]);
		f[x] = z; if ( check(y) ) ch[z][get(y)] = x;
		f[y] = x, ch[x][!t] = y;
		ch[y][t] = o; if ( o ) f[o] = y;
		pushup(y), pushup(x);
	}
	inline void splay( int x ){
		static int S[_], tp; int y = S[tp = 1] = x;
		while( check(y) ) S[++tp] = y = f[y];
		while( tp ) pushdown(S[tp--]);
		while( check(x) ) y = f[x], check(y) ? rotate(get(x) == get(y) ? y : x) : void(), rotate(x);
	}
	inline void access( int x ){
		for ( int y = 0; x; y = x, x = f[x] )
			splay(x), ch[x][1] = y, pushup(x);
	}
	inline void makeroot( int x ){
		access(x), splay(x), flip(x);
	}
	inline void split( int x, int y ){
		makeroot(x), access(y), splay(y);
	}
	inline int findroot( int x ){
		access(x), splay(x);
		while( ch[x][0] ) pushdown(x), x = ch[x][0];
		splay(x);
		return x;
	}
	inline void link( int x, int y ){
		makeroot(x); if ( findroot(y) != x ) f[x] = y;
	}
	inline void cut( int x, int y ){
		split(x, y); if ( findroot(y) == x && f[y] == x && !ch[y][0] ) f[y] = ch[x][1] = 0, pushup(x);
	}
} using namespace LCT;

int N, M;

int main(){
	read(N), read(M);
	fp( i, 1, N ) read(v[i]), s[i] = v[i];
	while( M-- ){
		char opt(getchar()); while( opt > 'Z' || opt < 'A' ) opt = getchar();
		if ( opt == 'M' ) x = findroot(x), ;
	}
	return 0;
}