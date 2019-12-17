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

const int _ = 5e5 + 66;
int N, o[_], p[_];
int a[_], b[_]; double f[_];
i64 tr[_<<2], s[_<<2];

bool cmp( int x, int y ){ return f[x] < f[y]; }

void Add( int c, int l, int r, int x, int y, int z ){
	tr[c] += y, s[c] += z; if ( l == r ) return;
	const int mid((l + r) >> 1), ls(c << 1), rs(ls | 1);
	x <= mid ? Add( ls, l, mid, x, y, z ) : Add( rs, mid + 1, r, x, y, z );
}
double ans;
int Get( int c, int l, int r, i64 k ){
	if ( l == r ) return o[l];
	const int mid((l + r) >> 1), ls(c << 1), rs(ls | 1);
	int t(k <= tr[ls] ? Get(ls, l, mid, k) : Get(rs, mid + 1, r, k - tr[ls]));
	ans += k <= tr[ls] ? (s[rs] - f[t] * tr[rs]) : (f[t] * tr[ls] - s[ls]);
	return t;
}

int main(){
	read(N);
	fp( i, 1, N ) read(a[i]);
	fp( i, 1, N ) read(b[i]), a[i] < 0 ? a[i] = -a[i], b[i] = -b[i] : 0, f[i] = -1. * b[i] / a[i], o[i] = i;
	sort(o + 1, o + N + 1, cmp); fp( i, 1, N ) p[o[i]] = i;
	fp( i, 1, N ) Add(1, 1, N, p[i], a[i], -b[i]), ans = 0, Get(1, 1, N, (tr[1] + 1) >> 1), printf("%.8lf\n", ans);
	return 0;
}