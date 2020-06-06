#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define open(s) freopen( s".in", "r", stdin ), freopen( s".out", "w", stdout )
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline bool cmax( T &x, T y ){ return x < y ? x = y, 1 : 0; }
template<typename T> inline bool cmin( T &x, T y ){ return y < x ? x = y, 1 : 0; }

const int _ = 1e5 + 55;
int N; i64 K;
i64 a[_], res[_];

inline i64 f( i64 a, i64 x ){
	return a - 3 * x * x + 3 * x - 1;
}

inline i64 calc( i64 a, i64 b, i64 c ){
	if ( (long double)b * b - (long double)4 * a * c < 0 ) return 0;
	return max( 0ll, (i64)((-b + sqrt((long double)b * b - (long double)4 * a * c)) / (a * 2)) );
}

inline i64 get( i64 s ){
	i64 sum(0);
	fp( i, 1, N ) sum += min(calc(3, -3, 1 + s - a[i]), a[i]);
	return sum;
}

int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> K;
	i64 l(1e18), r(-1e18), mid, ans;
	fp( i, 1, N ) cin >> a[i], cmin(l, f(a[i], a[i])), cmax(r, f(a[i], 0));
	while( l <= r ){
		mid = (l + r) >> 1;
		if ( get(mid) >= K ) l = mid + 1, ans = mid;
		else r = mid - 1;
	}
	i64 sum(get(ans));
	fp( i, 1, N ){
		res[i] = min(calc(3, -3, 1 + ans - a[i]), a[i]);
		if ( f(a[i], res[i]) == ans && res[i] > 0 && sum > K )
			--sum, --res[i];
	}
	fp( i, 1, N ) printf( "%lld ", res[i] );
	return 0;
}