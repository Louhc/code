#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline void cmax( T &x, T y ){ x < y ? x = y : x; }
template<typename T> inline void cmin( T &x, T y ){ y < x ? x = y : x; }

int N, M, Q, n;
const int MAXN = 2005, mod = 666623333;

struct node{
	int l, r;
	bool operator < ( const node &t )const{
		return l == t.l ? r > t.r : l < t.l;
	}
}a[MAXN];

inline int Pow( int x, int y = mod - 2 ){ int ans(1); for ( ; y; y >>= 1, x = 1ll * x * x % mod ) if ( y & 1 ) ans = 1ll * ans * x % mod; return ans; }

int f[MAXN], l[MAXN], r[MAXN], p[MAXN], ans;

signed main(){
	scanf( "%d%d%d", &N, &M, &Q );
	fp( i, 1, Q ) scanf( "%d%d", &a[i].l, &a[i].r );
	sort( a + 1, a + Q + 1 ), n = 1;
	fp( i, 2, Q ){
		while ( a[i].r <= a[n].r ) --n;
		a[++n] = a[i];
	}
	l[N + 1] = n + 1;
	fp( i, 1, n ) r[a[i].l] = i, l[a[i].r] = i;
	fd( i, N, 1 ) if ( !l[i] ) l[i] = l[i + 1];
	fp( i, 1, N ) if ( !r[i] ) r[i] = r[i - 1];
	
	f[0] = 1;
	fp( k, 1, M - 1 ){
		int s(1), j(0), t(1ll * k * Pow(M) % mod);
		p[0] = 1, p[1] = (1 + mod - t) % mod;
		fp( i, 2, N ) p[i] = 1ll * p[i - 1] * p[1] % mod;
		fp( i, 1, N ){
			while( r[j] + 1 < l[i] ) s = ( s + mod - 1ll * f[j] * p[i - j - 1] % mod ) % mod, ++j;
			f[i] = 1ll * s * t % mod, s = ( 1ll * s * p[1] + f[i] ) % mod;
			if ( r[i] >= n ) ans = ( ans + 1ll * f[i] * p[N - i] ) % mod;
		}
	}
	printf( "%d\n", ( mod - ans + M ) % mod );
	return 0;
}

