#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define open(s) freopen( s".in", "r", stdin ), freopen( s".out", "w", stdout )
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline bool cmax( T &x, T y ){ return x < y ? x = y, 1 : 0; }
template<typename T> inline bool cmin( T &x, T y ){ return y < x ? x = y, 1 : 0; }

const int _ = 2e5 + 55, __ = 5e5 + 55;
int N;
i64 a[_], b[_];
char ans[__]; int n, cnt;

bool check(){ fp( i, 1, N ) if ( b[i] <= 0 ) return 0; return 1; }
bool up(){ fp( i, 1, N - 1 ) if ( b[i + 1] <= b[i] ) return 0; return 1; }
bool down(){ fp( i, 1, N - 1 ) if ( b[i] <= b[i + 1] ) return 0; return 1; }

int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N;
	fp( i, 1, N ) cin >> a[i];
	fp( i, 1, N ) cin >> b[i];
	if ( N == 1 ) return printf( a[1] == b[1] ? "SMALL\n0\n" : "IMPOSSIBLE\n" ), 0;
	if ( N == 2 ){
		i64 x(b[1]), y(b[2]), s(0);
		while( x && y ){
			if ( y == a[1] ) swap(x, y); if ( x == a[1] && y >= a[2] && (y - a[2]) % x == 0 ){ s += (y - a[2]) / x, y = a[2]; break; }
			if ( y == a[2] ) swap(x, y); if ( x == a[2] && y >= a[1] && (y - a[1]) % x == 0 ){ s += (y - a[1]) / x, y = a[1], swap(x, y); break; }
			if ( x > y ) swap(x, y);
			s += y / x, y %= x;
		}
		if ( x != a[1] || y != a[2] ) return printf( "IMPOSSIBLE\n"), 0;
		else if ( s > 2e5 ) return printf( "BIG\n%lld\n", s ), 0;
	}
	while( check() ){
		int flg = 1; fp( i, 1, N ) if ( a[i] != b[i] ){ flg = 0; break; }
		if ( !flg ){ flg = 2; fp( i, 1, N ) if ( a[i] != b[N - i + 1] ){ flg = 0; break; } }
		if ( flg ){
			if ( flg == 2 && cnt <= 2e5 ) ans[++n] = 'R';
			if ( cnt <= 2e5 ){
				printf( "SMALL\n%d\n", n );
				fd( i, n, 1 ) putchar(ans[i]); putchar('\n');
			}
			else printf("BIG\n%d\n", cnt );
			return 0;
		} else if ( up() ){
			++cnt; if ( cnt <= 2e5 ) ans[++n] = 'P'; fd( i, N, 2 ) b[i] -= b[i - 1];
		} else if ( down() ){
			++cnt; if ( cnt <= 2e5 ) ans[++n] = 'R', ans[++n] = 'P'; reverse(b + 1, b + N + 1); fd( i, N, 2 ) b[i] -= b[i - 1];
		} else break;
	}
	printf( "IMPOSSIBLE\n");
	return 0;
}