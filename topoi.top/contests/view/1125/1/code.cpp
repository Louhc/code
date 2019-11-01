#include<bits/stdc++.h>
using namespace std;
#define i64 long long
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
const int MAXN = 2e5 + 5;
int d[1000005];
int s[MAXN<<2], mx[MAXN<<2], ml[MAXN<<2], mr[MAXN<<2];

int Find( int c, int l, int r ){
	if ( l == r ) return l;
	const int mid((l + r) >> 1), ls(c << 1), rs(ls | 1);
	if ( s[ls] < mid - l + 1 && mx[ls] == mx[c] ) return Find( ls, l, mid );
	if ( mr[ls] + 1 < ml[rs] && ( ( ml[rs] - mr[ls] ) >> 1 ) == mx[c] ) return ( mr[ls] + ml[rs] ) >> 1;
	if ( s[rs] < r - mid && mx[rs] == mx[c] ) return Find( rs, mid + 1, r );
	return 0;
}

void Ins( int c, int l, int r, int w ){
	if ( l == r ) return s[c] = 1, mx[c] = 0, ml[c] = mr[c] = l, void();
	const int mid((l + r) >> 1), ls(c << 1), rs(ls | 1);
	if ( w <= mid ) Ins( ls, l, mid, w );
	else Ins( rs, mid + 1, r, w );
	ml[c] = ml[ls] ? ml[ls] : ml[rs],
	mr[c] = mr[rs] ? mr[rs] : mr[ls],
	mx[c] = max( mx[ls], mx[rs] );
	if ( ml[rs] && mr[ls] ) cmax( mx[c], ( ml[rs] - mr[ls] ) >> 1 );
	s[c] = s[ls] + s[rs];
}

void Del( int c, int l, int r, int w ){
	if ( l == r ) return s[c] = mx[c] = 0, ml[c] = mr[c] = 0, void();
	const int mid((l + r) >> 1), ls(c << 1), rs(ls | 1);
	if ( w <= mid ) Del( ls, l, mid, w );
	else Del( rs, mid + 1, r, w );
	ml[c] = ml[ls] ? ml[ls] : ml[rs],
	mr[c] = mr[rs] ? mr[rs] : mr[ls],
	mx[c] = max( mx[ls], mx[rs] );
	if ( ml[rs] && mr[ls] ) cmax( mx[c], ( ml[rs] - mr[ls] ) >> 1 );
	s[c] = s[ls] + s[rs];
}

signed main(){
	read(N), read(M);
	while( M-- ){
		int a, b, t;
		read(a), read(b);
		if ( a & 1 ){
			if ( !ml[1] ) t = 1;
			else if ( ml[1] > 1 && ml[1] - 1 >= mx[1] && ( !mr[1] || N - mr[1] <= ml[1] - 1 ) ) t = 1;
			else if ( mr[1] < N && N - mr[1] > mx[1] ) t = N;
			else t = Find(1, 1, N);
			d[b] = t, Ins(1, 1, N, t), printf( "%d\n", t );
		} else Del(1, 1, N, d[b]), d[b] = 0;
	}
	return 0;
}

