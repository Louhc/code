#include<bits/stdc++.h>
using namespace std;
#define P 998244353
#define p 998244352
#define MAXN 4000005
#define rgt register
#define LL long long
#define getchar() ( ( p1 == p2 ? p2 = bf + fread( bf, 1, 1 << 21, stdin ), p1 = bf : p1 ) == p2 ? EOF : *p1++ )
char bf[1 << 21], *p1, *p2;
template<typename T>
inline void read( rgt T &x ){ x = 0; rgt char t(getchar()), flg(0);
	for ( ; !isdigit(t); t = getchar() ) flg = t == '-';
	for ( ; isdigit(t); t = getchar() ) x = x * 10 + ( t & 15 );
	flg ? x = -x : 0;
}

int N, M, w, f[MAXN];
int a[MAXN], b[MAXN];
inline LL Pow( LL x, LL y ){ LL ans(1); for ( ; y; y >>= 1, x = x * x % P ) ( y & 1 ) ? ans = ans * x % P : 0; return ans; }
#define inv(x) Pow( x, P - 2 )
inline int dec( int x ){ return x > P ? x - P : x; }
inline int rec( int x ){ return x < 0 ? x + P : x; }

void NTT( int *a, int opt ){ rgt int o(opt == 1 ? 3 : 332748118);
	for ( rgt int i = 1; i < N; ++i ) f[i] > i ? swap( a[f[i]], a[i] ) : void();
	for ( rgt int len = 1, pn, cur; len < N; len <<= 1 ){
		cur = len << 1, pn = Pow( o, p / cur );
		for ( rgt int i = 0, w; i < N; i += cur ){ w = 1;
			for ( rgt int j = 0, x, y; j < len; ++j, w = ( 1ll * w * pn ) % P )
				x = a[i + j], y = 1ll * a[i + j + len] * w % P,
				a[i + j] = dec( x + y ), a[i + j + len] = rec( x - y );
		}
	} if ( opt == -1 ){ for ( rgt int i = 0, t(inv(N)); i < N; ++i ) a[i] = ( (LL)a[i] * t ) % P;  }
}

signed main(){
	read(N), read(M);
	for ( rgt int i = 0; i <= N; ++i ) read(a[i]);
	for ( rgt int i = 0; i <= M; ++i ) read(b[i]);
	M += N, N = 1, w = -1; while( N <= M ) ++w, N <<= 1;
	for ( rgt int i = 1; i < N; ++i ) f[i] = ( f[i >> 1] >> 1 ) | ( ( i & 1 ) << w );
	NTT( a, 1 ), NTT( b, 1 );
	for ( rgt int i = 0; i < N; ++i ) a[i] = 1ll * a[i] * b[i] % P;
	NTT( a, -1 ); for ( rgt int i = 0; i <= M; ++i ) printf( "%d ", a[i] ); 
	return 0;
}