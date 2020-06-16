#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline bool cmax( T &x, T y ){ return x < y ? x = y, 1 : 0; }
template<typename T> inline bool cmin( T &x, T y ){ return y < x ? x = y, 1 : 0; }

const int _ = 2055;
int T, N;
char s[_], t[_];
int ss[_][26], st[_][26], f[_][_];

int main(){
	scanf( "%d", &T );
	while( T-- ){
		scanf( "%d", &N ), scanf( "%s", s + 1 ), scanf( "%s", t + 1 );
		fp( i, 1, N ){
			fp( j, 0, 25 ) ss[i][j] = ss[i - 1][j], st[i][j] = st[i - 1][j];
			++ss[i][s[i] - 'a'], ++st[i][t[i] - 'a'];
		}
		bool flg(0);
		fp( i, 0, 25 ) if ( ss[N][i] != st[N][i] ){ flg = 1, printf("-1\n"); break; }
		if ( flg ) continue;
		fp( i, 1, N ) memset(f[i], 0x3f, (N + 1) << 2);
		fp( i, 1, N ) fp( j, i, N ){
			cmin(f[i][j], f[i - 1][j] + 1);
			if ( s[i] == t[j] ) cmin(f[i][j], f[i - 1][j - 1]);
			if ( ss[i][t[j] - 'a'] < st[j][t[j] - 'a'] ) cmin(f[i][j], f[i][j - 1]);
		} printf("%d\n", f[N][N]);
	}
	return 0;
}
