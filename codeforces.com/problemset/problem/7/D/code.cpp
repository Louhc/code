#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define open(s) freopen( s".in", "r", stdin ), freopen( s".out", "w", stdout )
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline bool cmax( T &x, T y ){ return x < y ? x = y, 1 : 0; }
template<typename T> inline bool cmin( T &x, T y ){ return y < x ? x = y, 1 : 0; }

const int _ =  5e6 + 55;
char s[_<<1];
int n, r[_ << 1], f[_];

int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> s; n = strlen(s);
	fd( i, n - 1, 0 ) s[i << 1 | 1] = s[i], s[i << 1] = '^';
	s[n <<= 1] = '^';
	int o(0), mx(0);
	fp( i, 0, n ){
		if ( i >= mx ) r[i] = 1;
		else r[i] = min(r[(o << 1) - i], mx - i + 1);
		while( i >= r[i] && i + r[i] <= n && s[i - r[i]] == s[i + r[i]] ) ++r[i];
		if ( cmax(mx, i + r[i] - 1) ) o = i;
	} i64 ans(0);
	fp( i, 1, n >> 1 ) ans += f[i] = r[i] == i + 1 ? f[i >> 1] + 1 : 0;
	cout << ans << endl;
	return 0;
}