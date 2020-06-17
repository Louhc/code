#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define INF 0x7f7f7f7f7f7f7f7fll
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline bool cmax( T &x, T y ){ return x < y ? x = y, 1 : 0; }
template<typename T> inline bool cmin( T &x, T y ){ return y < x ? x = y, 1 : 0; }

const int _ = 2e5 + 55;
int N, M, K; i64 w[_];
struct twr{
	int a, l;
	bool operator < ( const twr &t )const{ return a < t.a; }
}tw[_];

int lg[_];
i64 f1[_][20], f2[_][20];

inline i64 Get( i64 f[_][20], int l, int r ){
	cmax(l, 1), cmin(r, K); if ( l > r ) return 1e18;
	int t(lg[r - l + 1]); return min( f[l][t], f[r - (1 << t) + 1][t] );
}

inline int EF1( int x ){
	int l = 1, r = K, mid, ans(K + 1);
	while( l <= r ){ mid = (l + r) >> 1; if ( tw[mid].a >= x ) ans = mid, r = mid - 1; else l = mid + 1; }
	return ans;
}
inline int EF2( int x ){
	int l = 1, r = K, mid, ans(K + 1);
	while( l <= r ){ mid = (l + r) >> 1; if ( tw[mid].a > x ) r = mid - 1; else ans = mid, l = mid + 1; }
	return ans;
}

int main(){
	scanf( "%d%d", &N, &M );
	fp( i, 2, N ) lg[i] = lg[i >> 1] + 1;
	fp( i, 1, N - 1 ) scanf( "%d", w + i ), w[i] += w[i - 1];
	while( M-- ){
		scanf( "%d", &K );
		fp( i, 1, K ) scanf( "%d%d", &tw[i].a, &tw[i].l );
		sort(tw + 1, tw + K + 1);
		fp( i, 1, K ) f1[i][0] = tw[i].l - w[tw[i].a - 1], f2[i][0] = tw[i].l + w[tw[i].a - 1];
		fp( i, 1, lg[K] ) fp( j, 1, K - (1 << i) + 1 ){
			f1[j][i] = min( f1[j][i - 1], f1[j + (1 << (i - 1))][i - 1] ),
			f2[j][i] = min( f2[j][i - 1], f2[j + (1 << (i - 1))][i - 1] );
		}
		i64 ans(0);
		fp( i, 1, K ){
			int L(tw[i].a), R(tw[i].a), l, r, mid, t, tt;
			l = 1, r = tw[i].a - 1;

			while( l <= r ){
				mid = (l + r) >> 1, t = EF1(mid), tt = EF1(mid + mid - tw[i].a), tt += (tw[tt].a + tw[i].a == mid + mid && f1[tt][0] + w[mid - 1] == f2[i][0] - w[mid - 1]);
				if ( min(Get(f1, tt, t - 1) + w[mid - 1], Get(f2, t, i - 1) - w[mid - 1]) > f2[i][0] - w[mid - 1] )
					L = mid, r = mid - 1;
				else l = mid + 1;
			}

			l = tw[i].a + 1, r = N;
			while( l <= r ){
				mid = (l + r) >> 1, t = EF1(mid), tt = EF2(mid + mid - tw[i].a);
				if ( min(Get(f1, i + 1, t - 1) + w[mid - 1], Get(f2, t, tt) - w[mid - 1]) > f1[i][0] + w[mid - 1] )
					R = mid, l = mid + 1;
				else r = mid - 1;
			}
			ans += R - L + 1;
		}
		printf( "%lld\n", ans );
	}
	return 0;
}
