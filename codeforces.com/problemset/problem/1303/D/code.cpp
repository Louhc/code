#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline bool cmax( T &x, T y ){ return x < y ? x = y, 1 : 0; }
template<typename T> inline bool cmin( T &x, T y ){ return y < x ? x = y, 1 : 0; }

int T, M, x, ans; i64 N;
int f[37], sum[65];

int main(){
	scanf( "%d", &T );
	fp( i, 0, 30 ) f[(1 << i) % 37]  = i;
	while( T-- ){
		scanf( "%lld%d", &N, &M ), ans = 0;
		memset(sum, 0, sizeof sum);
		fp( i, 1, M ) scanf( "%d", &x ), ++sum[f[x % 37]];
		fp( i, 0, 60 ){
			if ( (N >> i) & 1 ) --sum[i];
			if ( sum[i] < 0 ) sum[i] += 2, --sum[i + 1], ++ans;
			sum[i + 1] += sum[i] >> 1;
		}
		if ( sum[61] < 0 ) printf("-1\n");
		else printf("%d\n", ans);
	}
	return 0;
}
