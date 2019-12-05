#include<bits/stdc++.h>
using namespace std;
#if __cplusplus >= 201103L
template<class ...Args> inline int err( Args ...args ){ return fprintf( stderr, args... ); }
#else
#define err(...) 1
#endif
#define i64 long long
#define f80 long double
#define rgt register
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline bool cmax( T &x, T y ){ return x < y ? x = y, 1 : 0; }
template<typename T> inline bool cmin( T &x, T y ){ return y < x ? x = y, 1 : 0; }
#define getchar() ( p1 == p2 && ( p1 = bf, p2 = bf + fread( bf, 1, 1 << 21, stdin ), p1 == p2 ) ? EOF : *p1++ )
char bf[1 << 21], *p1(bf), *p2(bf);
template<typename T>
inline void read( T &x ){ char t(getchar()), flg(0); x = 0;
	for ( ; !isdigit(t); t = getchar() ) flg = t == '-';
	for ( ; isdigit(t); t = getchar() ) x = x * 10 + ( t & 15 );
	flg ? x = -x : x;
}

const int mod = 1e9 + 7;
int N, n, a[20][20];
vector<pair<int, int> > e[20];
inline void addedge( int x, int y ){
	--a[x][y], --a[y][x], ++a[x][x], ++a[y][y];
}
inline void swp( int &x, int &y ){ x^=y^=x^=y; }
inline int Pow( int x, int y = mod - 2 ){ int ans(1); for ( ; y; y >>= 1, x = 1ll * x * x % mod ) if ( y & 1 ) ans = 1ll * ans * x % mod; return ans; }

int calc(){
	int ans(1);
	fp( i, 1, n ) fp( j, 1, n ) if ( a[i][i] < 0 ) a[i][i] += mod;
	fp( i, 1, n ){
		int t(-1);
		fp( j, i, n ) if ( a[j][i] ){
			t = j; break;
		} if ( t == -1 ) return 0;
		if ( t != i ){
			fp( j, i, n ) swp( a[i][j], a[t][j] );
			ans = mod - ans;
		} ans = 1ll * ans * a[i][i] % mod;
		t = Pow(a[i][i]);
		fp( j, i, n ) a[i][j] = 1ll * a[i][j] * t % mod;
		fp( j, i + 1, n )
			fd( k, n, i ) a[j][k] = ( a[j][k] + mod - 1ll * a[i][k] * a[j][i] % mod ) % mod;
	} return ans % mod;
}

signed main(){
	read(N), n = N - 1;
	fp( i, 1, N - 1 ){
		int M, x, y; read(M);
		fp( j, 1, M ) read(x), read(y), e[i].push_back(make_pair(x, y));
	} int ans(0);
	fp( i, 1, (1 << n) - 1 ){
		int ct(0);
		memset( a, 0, sizeof a ); 
		fp( j, 1, n ) if ( ( i >> (j - 1) ) & 1 ){
			++ct;
			fp( k, 0, (int)e[j].size() - 1 )
				addedge( e[j][k].first, e[j][k].second );
		} ans = ( ans + ( ( n - ct ) & 1 ? mod - calc() : calc() ) ) % mod;
	} printf( "%d\n", ans );
	return 0;
}

