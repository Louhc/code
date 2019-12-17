#include<bits/stdc++.h>
using namespace std;
#define i64 long long
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

const int _ = 1e5 + 15;
int N, M, K;
int u[_<<1], v[_<<1];
vector<int> T[_<<2];

struct node{
	int *x, y; node(){}
	node( int *a, int b ):x(a), y(b){}
}a[_<<4]; int n;

int f[_<<1];
inline void modify( int *x, int y ){ a[++n] = node(x, *x), *x = y; }
inline void goback( int _n ){ while( n > _n ) *a[n].x = a[n].y, --n; }
inline int find( int x ){ return f[x] < 0 ? x : find(f[x]); }

inline void merge( int x, int y ){
	x = find(x), y = find(y);
	if ( x != y ) f[x] > f[y] ? swap(x, y), 1 : 1, modify(f + x, f[x] + f[y]), modify(f + y, x);
}

void Add( int c, int l, int r, int L, int R, int x ){
	if ( L <= l && r <= R ) return void(T[c].push_back(x));
	if ( R < l || r < L ) return;
	const int mid((l + r) >> 1), ls(c << 1), rs(ls | 1);
	Add(ls, l, mid, L, R, x), Add(rs, mid + 1, r, L, R, x);
}

void DFS( int c, int l, int r ){
	int _n(n);
	for ( auto i : T[c] ){
		merge(u[i], v[i] + N), merge(u[i] + N, v[i]);
		if ( find(u[i]) == find(u[i] + N) ){ fp( j, l, r ) printf("No\n"); return goback(_n); }
	} if ( l == r ) printf( "Yes\n" );
	else{ const int mid((l + r) >> 1), ls(c << 1), rs(ls | 1); DFS(ls, l, mid), DFS(rs, mid + 1, r); }
	goback(_n);
}

signed main(){
	memset( f, -1, sizeof f );
	read(N), read(M), read(K); int l, r;
	fp( i, 1, M ) read(u[i]), read(v[i]), read(l), read(r), Add(1, 1, K, l + 1, r, i);
	DFS(1, 1, K);
	return 0;
}

