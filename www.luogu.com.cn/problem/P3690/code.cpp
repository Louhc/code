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

const int _ = 1e5 + 55;
int N, M;

struct node *null;
struct node{
	int v, s, tg; node *ch[2], *f;
	inline void pushup(){ s = ch[0]->s ^ ch[1]->s ^ v; }
	inline void flip(){ tg ^= 1, swap(ch[0], ch[1]); }
	inline void pushdown(){ if ( tg ) tg = 0, ch[0] != null ? ch[0]->flip() : void(), ch[1] != null ? ch[1]->flip() : void(); }
	inline int get(){ return f->ch[1] == this; }
	inline int check(){ return f->ch[0] == this || f->ch[1] == this; }
}a[_];

inline void rotate( node *x ){
	int t(x->get()); node *y(x->f), *z(y->f), *o(x->ch[!t]);
	x->f = z; if ( y->check() ) z->ch[y->get()] = x;
	y->f = x, x->ch[!t] = y;
	y->ch[t] = o; if ( o != null ) o->f = y;
	y->pushup(), x->pushup();
}
inline void splay( node *x ){
	static node* stk[_], *y; int tp;
	stk[tp = 1] = y = x; while( y->check() ) stk[++tp] = y = y->f;
	while( tp ) stk[tp--]->pushdown();
	while( x->check() ) y = x->f, y->check() ? rotate(x->get() == y->get() ? y : x) : void(), rotate(x);
	x->pushup();
}
inline void access( node *x ){
	for ( node *y = null; x != null; y = x, x = x->f )
		splay(x), x->ch[1] = y, x->pushup();
}
inline void makeroot( node *x ){
	access(x), splay(x), x->flip();
}
inline node* findroot( node *x ){
	access(x), splay(x);
	while( x->ch[0] != null ) x->pushdown(), x = x->ch[0];
	splay(x);
	return x;
}
inline void split( node *x, node *y ){
	makeroot(x), access(y), splay(y);
}
inline void link( node *x, node *y ){
	makeroot(x); if ( findroot(y) != x ) x->f = y;
}
inline void cut( node *x, node *y ){
	split(x, y); if ( findroot(y) == x && y->f == x && y->ch[0] == null ) y->f = x->ch[1] = null, x->pushup();
}

int main(){
	null = new node(), null->ch[0] = null->ch[1] = null->f = null;
	read(N), read(M);
	fp( i, 1, N ) read(a[i].v), a[i].ch[0] = a[i].ch[1] = a[i].f = null, a[i].s = a[i].v;
	int xxxx;
	while( M-- ){
		int opt, x, y; read(opt), read(x), read(y);
		if ( opt == 0 ) split(a + x, a + y), printf( "%d\n", a[y].s );
		else if ( opt == 1 ) link(a + x, a + y);
		else if ( opt == 2 ) cut(a + x, a + y);
		else splay(a + x), a[x].v = y, a[x].pushup();
	}
	return 0;
}