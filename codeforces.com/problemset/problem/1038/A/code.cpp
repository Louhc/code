#include<bits/stdc++.h>
using namespace std;
inline bool cmin( int &x, int y ){ return x > y ? x = y, 1 : 0; }
inline bool cmax( int &x, int y ){ return x < y ? x = y, 1 : 0; }
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[b]); i; v = to[i = nxt[i]] )
#define i64 long long

const int _ = 1e5 + 55;
int N, K; char s[_];
int c[26];

int main(){
	scanf( "%d%d", &N, &K );
	scanf( "%s", s );
	for ( int i = 0; s[i] != '\0'; ++i )
		++c[s[i] - 'A'];
	int ans(1e9);
	fp( i, 0, K - 1 ) cmin(ans, c[i]);
	printf( "%d\n", ans * K );
	return 0;
}