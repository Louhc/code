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

const int _ = 4e7 + 15;
int N, type;
i64 a[_]; int b[_], q[_], hd, tl;
#define calc(x) ((a[x] << 1) - a[b[x]])

const int bs = 1e9;
struct node{
	i64 a[4]; node(){ a[0] = a[1] = a[2] = a[3] = 0; }
	node( i64 x ){ fp( i, 0, 3 ) a[i] = x % bs, x /= bs; }
	void print(){
		int i(3); while( i && !a[i] ) --i;
		printf( "%lld", a[i] ); while( --i >= 0 ) printf( "%09lld", a[i] );
	}
	void add_sqr( node t ){
		fp( i, 0, 1 ) fp( j, 0, 1 ) a[i + j] += t.a[i] * t.a[j];
		fp( i, 0, 2 ) a[i + 1] += a[i] / bs, a[i] %= bs;
	}
};

signed main(){
	read(N), read(type);
	if ( !type ) fp( i, 1, N ) read(a[i]), a[i] += a[i - 1];
	else{
		int x, y, z, b1, b2, b3, m, l, r, p, q(1);
		read(x), read(y), read(z), read(b1), read(b2), read(m);
		fp( i, 1, m ){
			read(p), read(l), read(r);
			fp( j, q, p ) a[j] = a[j - 1] + b1 % (r - l + 1) + l, b3 = ((i64)x * b2 + (i64)y * b1 + z) & 1073741823, b1 = b2, b2 = b3;
			q = p + 1;
		}
	} q[hd = tl = 1] = 0;
	fp( i, 1, N ){
		while( hd < tl && calc(q[hd + 1]) <= a[i] ) ++hd;
		b[i] = q[hd];
		while( hd <= tl && calc(i) < calc(q[tl]) ) --tl;
		q[++tl] = i;
	} node ans(0); for ( int i = N; i; i = b[i] ) ans.add_sqr(node(a[i] - a[b[i]]));
	ans.print();
	return 0;
}
