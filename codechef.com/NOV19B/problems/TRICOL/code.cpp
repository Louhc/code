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

int N, M, cnt;
int X, Y, P, Q;
char s[666], r[666], ans[666];
int a[9999], b[9999], c[9999];
const char w[] = "RGB";

inline int calc1(){ int ans(0); fp( i, 1, M ) ans += r[a[i]] == r[b[i]] || r[a[i]] == r[c[i]] || r[b[i]] == r[c[i]]; return ans; }
inline int calc2(){ int ans(0); fp( i, 1, N ) ans += r[i] != s[i]; return ans; }
inline int sqr( int x ){ return x * x; }
inline int calc(){ return sqr(calc1()) + calc2() * X; }

signed main(){
	srand(20030131);
	scanf( "%d%d%d%d%d%d", &N, &M, &X, &Y, &P, &Q );
	scanf( "%s", s + 1 );
	fp( i, 1, N ) scanf( "%*d%*d" );
	fp( i, 1, M ) scanf( "%d%d%d", a + i, b + i, c + i );
	memcpy( ans, s, sizeof s ), memcpy( r, s, sizeof s );
	int mn(calc()), cur;
	while( clock() < 4.9 * CLOCKS_PER_SEC ){
		memcpy( r, ans, sizeof r );
		fp( i, 1, rand() % min( P, 25 ) + 1 ) r[rand() % N + 1] = w[rand() % 3];
		if ( mn > (cur = calc()) ) mn = cur, memcpy( ans, r, sizeof r );
	} memcpy( r, ans, sizeof r );
	printf( "%d 0\n", calc2() );
	printf( "%s\n", ans + 1 );
	return 0;
}