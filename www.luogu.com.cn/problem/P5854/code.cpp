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

const int _ = 1e7 + 55;
int N, p[_], s[_], tp, l[_], r[_];
i64 ans1, ans2;

int main(){
	read(N);
	fp( i, 1, N ) read(p[i]);
	fp( i, 1, N ){
		while( tp && p[s[tp]] > p[i] ) l[i] = s[tp--];
		if ( tp ) r[s[tp]] = i;
		s[++tp] = i;
	}
	fp( i, 1, N ) ans1 ^= (i64)i * (l[i] + 1);
	fp( i, 1, N ) ans2 ^= (i64)i * (r[i] + 1);
	cout << ans1 << " " << ans2 << endl;
	return 0;
}