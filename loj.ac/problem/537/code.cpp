#include<bits/stdc++.h>
using namespace std;
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
template<typename T> inline bool cmax( T &x, T y ){ return x < y ? x = y, 1 : 0; }

const int MAXN = 5e6 + 5;
int N, K, w, ans;
char s[MAXN];
int cnt[1100000], cur;

signed main(){
	scanf( "%s", s + 1 ), N = strlen(s + 1);
	scanf( "%d", &K ), w = (K - 1) * 2;
	fp( i, 1, N ){
		if ( s[i] == 'A' ) s[i] = 0;
		else if ( s[i] == 'T' ) s[i] = 1;
		else if ( s[i] == 'G' ) s[i] = 2;
		else s[i] = 3;
		cur >>= 2, cur |= (int)s[i] << w;
		if ( i >= K ) cmax( ans, ++cnt[cur] );
	} printf( "%d\n", ans );
	return 0;
}

