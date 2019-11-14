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

const int MAXN = 1e6 + 25;
int N; char s1[MAXN<<1], s2[MAXN<<1];
int r1, r2;

int solve( char *s ){
	int i(1), j(2), k(0);
	while( i <= N && j <= N ){
		k = 0; while( k < N && s[i + k] == s[j + k] ) ++k;
		if ( k == N ) return 1;
		if ( s[i + k] > s[j + k] )
			i += k + 1, i += i == j;
		else
			j += k + 1, j += i == j;
	} return min(i, j);
}

signed main(){
	scanf( "%s", s1 + 1 ), scanf( "%s", s2 + 1 );
	N = strlen(s1 + 1); fp( i, 1, N ) s1[i + N] = s1[i], s2[i + N] = s2[i];
	r1 = solve(s1), r2 = solve(s2);
	fp( i, 0, N - 1 ) if ( s1[r1 + i] != s2[r2 + i] ) return !printf("No\n");
	printf("Yes\n"), fwrite(s1 + r1, 1, N, stdout);
	return 0;
}
