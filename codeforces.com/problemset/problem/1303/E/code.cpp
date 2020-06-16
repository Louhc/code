#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline bool cmax( T &x, T y ){ return x < y ? x = y, 1 : 0; }
template<typename T> inline bool cmin( T &x, T y ){ return y < x ? x = y, 1 : 0; }

int T, N, M;
char s[405], t[405];
int f[405][405], g[405][26];

int main(){
	scanf("%d", &T);
	while( T-- ){
		scanf("%s", s + 1), N = strlen(s + 1);
		scanf("%s", t + 1), M = strlen(t + 1);
		memset(g, 0x7f, sizeof g);
		fd( i, N, 1 ){ g[i][s[i] - 'a'] = i; fp( j, 0, 25 ) g[i - 1][j] = g[i][j]; }
		bool flg = 0;
		fp( k, 1, M ){
			fp( i, 0, k ) fp( j, 0, M - k ) f[i][j] = 0x7f7f7f7f;
			f[0][0] = 0;
			fp( i, 0, k )
				fp( j, 0, M - k ){
					if ( i && f[i - 1][j] < N ) cmin(f[i][j], g[f[i - 1][j] + 1][t[i] - 'a']);
					if ( j && f[i][j - 1] < N ) cmin(f[i][j], g[f[i][j - 1] + 1][t[k + j] - 'a']);
				}
			if ( f[k][M - k] <= N ){ flg = 1; break; }
		}
		printf(flg ? "YES\n" : "NO\n");
	}
	return 0;
}
