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

const int MAXN = 5e5 + 15;
int n(1), ans, dep[MAXN];
int ch[MAXN][26], fail[MAXN], len[MAXN], tot(-1);
int s[MAXN], p, q;
inline int newnode( int x ){ return len[++tot] = x, tot; }
inline int getfail( int x, int n ){ while( s[n] != s[n - len[x] - 1] ) x = fail[x]; return x; }

signed main(){
	newnode(0), newnode(-1), fail[0] = p = 1, s[0] = 19260817;
	while( (s[n] = getchar()) >= 'a' && s[n] <= 'z' ){
		s[n] = (s[n] - 'a' + dep[p]) % 26;
		// s[n] = (s[n] - 'a');
		q = getfail(p, n);
		if ( !ch[q][s[n]] ){
			p = newnode(len[q] + 2),
			fail[p] = ch[getfail(fail[q], n)][s[n]],
			ch[q][s[n]] = p, dep[p] = dep[fail[p]] + 1;
		} p = ch[q][s[n]], ++n, printf( "%d ", dep[p] );
	}
	return 0;
}
