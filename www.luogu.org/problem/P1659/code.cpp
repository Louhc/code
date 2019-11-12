#include<bits/stdc++.h>
using namespace std;
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define i64 long long

const int MAXN = 1e6 + 15, mod = 19930726;
int N, r[MAXN], c[MAXN]; i64 K;
char s[MAXN];
int Pow( int x, int y ){ int ans(1); for ( ; y; y >>= 1, x = 1ll * x * x % mod ) if ( y & 1 ) ans = 1ll * ans * x % mod; return ans; }

int main(){
	scanf( "%d%lld", &N, &K ), scanf( "%s", s + 1 ), s[0] = '@';
	int mo(0), mr(0);
	fp( i, 1, N ){
		if ( i < mr ) r[i] = min( r[(mo << 1) - i], mr - i + 1 );
		else r[i] = 1;
		while( s[i + r[i]] == s[i - r[i]] ) ++r[i];
		if ( i + r[i] - 1 > mr ) mr = i + r[i] - 1, mo = i;
		++c[r[i]];
	} int ans(1), cur(0);
	fd( i, (N + 1) >> 1, 2 ){
		cur += c[i];
		if ( K <= cur ){
			ans = 1ll * ans * Pow((i << 1) - 1, K) % mod; break;
		} else ans = 1ll * ans * Pow((i << 1) - 1, cur) % mod, K -= cur;
	} printf( "%d\n", ans );
	return 0;
}