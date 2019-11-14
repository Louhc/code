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
#define getchar() ( p1 == p2 && ( p1 = bf, p2 = bf + fread( bf, 1, 1 << 21, stdin ), p1 == p2 ) ? EOF : *p1++ )
char bf[1 << 21], *p1(bf), *p2(bf);
template<typename T>
inline void read( T &x ){ char t(getchar()), flg(0); x = 0;
	for ( ; !isdigit(t); t = getchar() ) flg = t == '-';
	for ( ; isdigit(t); t = getchar() ) x = x * 10 + ( t & 15 );
	flg ? x = -x : x;
}

const int MAXN = 1e5 + 25;
struct node *null, *rt, *pit;
struct node{
	node *ls, *rs; int v, sz, rk;
	inline void maintain(){ sz = ls->sz + rs->sz + 1; }
}pool[MAXN];
inline node *New( int x ){ return pit->ls = pit->rs = null, pit->v = x, pit->sz = 1, pit->rk = rand(), pit++; }
void Splitv( node *c, int v, node *&x, node *&y ){
	if ( c == null ) return x = y = null, void();
	if ( c->v <= v ) x = c, Splitv( c->rs, v, c->rs, y );
	else y = c, Splitv( c->ls, v, x, c->ls ); c->maintain();
}
void Merge( node *&c, node *x, node *y ){
	if ( x == null ) return c = y, void();
	if ( y == null ) return c = x, void();
	if ( x->rk > y->rk ) c = x, Merge( c->rs, c->rs, y );
	else c = y, Merge( c->ls, x, c->ls ); c->maintain();
}

int Q;

inline void Ins( int v ){ node *x, *y, *t; Splitv(rt, v, x, y), Merge(rt, x, t = New(v)), Merge(rt, rt, y); }
inline void Del( int v ){ node *x, *y, *z; Splitv(rt, v - 1, x, y), Splitv(y, v, y, z), Merge(y, y->ls, y->rs), Merge(rt, x, y), Merge(rt, rt, z); }
inline int Qr( int v ){ node *c(rt); int s(0); while( c != null ) c->v < v ? s += c->ls->sz + 1, c = c->rs : c = c->ls; return s + 1; }
inline int Qv( int k ){ node *c(rt); while( c != null ) if ( c->ls->sz + 1 == k ) return c->v; else if ( c->ls->sz >= k ) c = c->ls; else k -= c->ls->sz + 1, c = c->rs; return -1;}
inline int Qpre( int v ){ node *c(rt); int r(-1); while( c != null ) c->v < v ? r = c->v, c = c->rs : c = c->ls; return r; }
inline int Qnxt( int v ){ node *c(rt); int r(-1); while( c != null ) c->v > v ? r = c->v, c = c->ls : c = c->rs; return r; }


signed main(){
	srand(20040817);
	pit = pool, rt = null = new node(),
	rt->ls = rt->rs = null, null->sz = 0;
	read(Q); int opt, x;
	while( Q-- ){
		read(opt), read(x);
		switch( opt ){
			case 1: Ins(x); break;
			case 2: Del(x); break;
			case 3: printf( "%d\n", Qr(x) ); break;
			case 4: printf( "%d\n", Qv(x) ); break;
			case 5: printf( "%d\n", Qpre(x) ); break;
			case 6: printf( "%d\n", Qnxt(x) ); break;
		}
	}
	return 0;
}