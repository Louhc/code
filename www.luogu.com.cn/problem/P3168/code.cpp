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

const int MAXN = 100005;
int M, N, b[MAXN], n, T[MAXN], ls[MAXN*40], rs[MAXN*40], s[MAXN*40], tot; i64 v[MAXN*40];
struct node{
	int x, p, d;
	bool operator < ( const node &t )const{ return x < t.x; }
}a[MAXN<<1];

void Ins( int o, int &c, int l, int r, int x, int d ){
	if ( c <= o ) c = ++tot, ls[c] = ls[o], rs[c] = rs[o], s[c] = s[o], v[c] = v[o];
	if ( d > 0 ) ++s[c], v[c] += b[x]; else --s[c], v[c] -= b[x];
	if ( l == r ) return;
	const int mid((l + r) >> 1);
	if ( x <= mid ) Ins( ls[o], ls[c], l, mid, x, d );
	else Ins( rs[o], rs[c], mid + 1, r, x, d );
}
i64 Query( int c, int l, int r, int k ){
	if ( l == r ) return (i64)k * b[l];
	const int mid((l + r) >> 1);
	if ( s[ls[c]] >= k ) return Query( ls[c], l, mid, k );
	return Query( rs[c], mid + 1, r, k - s[ls[c]] ) + v[ls[c]];
}

signed main(){
	read(M), read(N);
	fp( i, 1, M ){
		int S, E, P, p((i << 1) - 1), q(i << 1);
		read(S), read(E), read(P), b[i] = P;
		a[p].x = S, a[p].p = P, a[p].d = 1,
		a[q].x = E + 1, a[q].p = P, a[q].d = -1;
	} sort( b + 1, b + M + 1 ), n = unique( b + 1, b + M + 1 ) - b - 1;
	fp( i, 1, M ) a[i << 1].p = a[(i << 1) - 1].p = lower_bound( b + 1, b + n + 1, a[i << 1].p ) - b;
	sort( a + 1, a + M * 2 + 1 ), a[M * 2 + 1].x = 1e9; int j(1);
	fp( i, 1, N ){ T[i] = T[i - 1]; while( a[j].x <= i ) Ins( T[i - 1], T[i], 1, n, a[j].p, a[j].d ), ++j; }
	i64 pre(1), X, A, B, C; int K;// return 0;
	while( N-- ){
		read(X), read(A), read(B), read(C), K = 1 + ( A * pre + B ) % C;
		printf( "%lld\n", pre = s[T[X]] <= K ? v[T[X]] : Query( T[X], 1, n, K ) );
	}
	return 0;
}


