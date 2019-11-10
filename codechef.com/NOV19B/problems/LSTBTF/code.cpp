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

int T, N, n;
int f[5005];
char ot[1010005]; int p(-1);

string get( int x ){
	string s("");
	fp( i, 1, f[x] ) fp( j, 2, 9 ) if ( f[x - j * j + 1] + 1 == f[x] ){
		x = x - j * j + 1, s += (char)('0' + j); break;
	} return s;
}

signed main(){
	scanf( "%d", &T );
	memset( f, 0x3f, sizeof f ); f[0] = 0;
	fp( j, 2, 9 ) fp( i, j * j - 1, 5000 ) cmin( f[i], f[i - j * j + 1] + 1 );
	while( T-- ){
		scanf( "%d", &N );
		n = 1; while( n * n < N ) ++n;
		string r("-1"), t; int x;
		while( (x = n * n - N) <= 5e3 ){
			if ( f[x] < 1e9 ){
				if ( r == "-1" || f[x] < r.size() ) r = get(x);
				else if ( f[x] == r.size() ) cmin( r, get(x) );
			} ++n;
		} fp( i, 1, N - r.size() ) ot[++p] = '1';
		fp( i, 0, (int)r.size() - 1 ) ot[++p] = r[i];
		ot[++p] = '\n';
	} fwrite( ot, 1, p + 1, stdout );
	return 0;
}
