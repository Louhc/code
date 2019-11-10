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

const int MAXN = 1e5 + 15;
int T, L, A, B; char s[MAXN]; int len; f80 ans;
int f[MAXN], xa[26], xb[26], fa[26], fb[26], v[26];
inline int Get( char t ){ return t == 'a' || t == 'e' || t == 'i' || t == 'o' || t == 'u'; }
inline bool check( char *str, int n ){
	fp( i, 1, n ) f[i] = f[i - 1] + Get(str[i]);
	int t(-1e9); f[1] = 2 * f[1] - 1;
	fp( i, 2, n ){ cmax( t, f[i - 2] ); if ( (f[i] = f[i] * 2 - i) < t ) return 0; }
	return 1;
}

signed main(){
	scanf( "%d", &T );
	while( T-- ){
		scanf( "%d", &L ), ans = 0, A = B = 0;
		fp( i, 1, L ){
			scanf( "%s", s + 1 ), len = strlen(s + 1);
			if ( check(s, len) ){ ++A;
				fp( j, 1, len ) ++fa[s[j] - 'a'], v[s[j] - 'a'] = 1;
				fp( j, 0, 25 ) xa[j] += v[j], v[j] = 0;
			} else{ ++B;
				fp( j, 1, len ) ++fb[s[j] - 'a'], v[s[j] - 'a'] = 1;
				fp( j, 0, 25 ) xb[j] += v[j], v[j] = 0;
			}
		}
		fp( i, 0, 25 ){
			if ( xa[i] ) ans += log(xa[i]) - log(fa[i]) * A, xa[i] = fa[i] = 0;
			if ( xb[i] ) ans -= log(xb[i]) - log(fb[i]) * B, xb[i] = fb[i] = 0;
		} if ( ans > log(1e7) ) printf("Infinity\n"); else printf("%.10Lf\n", exp(ans));
	}
	return 0;
}
