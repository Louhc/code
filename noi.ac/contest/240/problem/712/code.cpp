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
// #define getchar() ( p1 == p2 && ( p1 = bf, p2 = bf + fread( bf, 1, 1 << 21, stdin ), p1 == p2 ) ? EOF : *p1++ )
char bf[1 << 21], *p1(bf), *p2(bf);
template<typename T>
inline void read( T &x ){ char t(getchar()), flg(0); x = 0;
	for ( ; !isdigit(t); t = getchar() ) flg = t == '-';
	for ( ; isdigit(t); t = getchar() ) x = x * 10 + ( t & 15 );
	flg ? x = -x : x;
}

const int MAXN = 200005;
int N, M, s[MAXN];
vector<int> v[MAXN];
#define pb push_back

signed main(){
	read(N), read(M); int x, y;
	fp( i, 1, M ) read(x), read(y), x != y ? x < y ? v[x].pb(y) : v[y].pb(x), 1 : s[x] ^= 1;
	fp( i, 1, N ){
		sort( v[i].begin(), v[i].end() );
		for ( auto j : v[i] ) if ( j < i ){
			if ( );
		} else{
			;
		}
	}
	return 0;
}
