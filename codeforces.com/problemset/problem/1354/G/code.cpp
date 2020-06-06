#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define open(s) freopen( s".in", "r", stdin ), freopen( s".out", "w", stdout )
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline bool cmax( T &x, T y ){ return x < y ? x = y, 1 : 0; }
template<typename T> inline bool cmin( T &x, T y ){ return y < x ? x = y, 1 : 0; }

int T, N, K;
string s;

int seed;
int rnd(){ return seed = (seed * 996ll + (seed >> 4) + (seed ^ 138904613)) % 998244353; }

int main(){
	seed = 120200528;
	cin >> T;
	while( T-- ){
		cin >> N >> K;
		bool flg(0);
		fp( i, 1, 30 ){
			cout << "? " << 1 << " " << 1 << endl << 1 << endl << rnd() % (N - 1) + 2 << endl;
			cin >> s; if ( s[0] == 'W' ) exit(-1);
			if ( s[0] == 'S' ){ cout << "! 1" << endl, flg = 1; break; }
		}
		if ( flg ) continue;
		int len(1);
		while( len + len < N ){
			cout << "? " << len << " " << len << endl;
			fp( i, 1, len ) cout << i << " "; cout << endl;
			fp( i, 1, len ) cout << i + len << " "; cout << endl;
			cin >> s; if ( s[0] == 'W' ) exit(-1);
			if ( s[0] == 'F' ) break;
			len <<= 1;
		}
		int l(1), r(min(N - len, len)), mid, ans(0);
		while( l <= r ){
			mid = (l + r) >> 1;
			cout << "? " << mid << " " << mid << endl;
			fp( i, 1, mid ) cout << i << " "; cout << endl;
			fp( i, 1, mid ) cout << i + len << " "; cout << endl;
			cin >> s; if ( s[0] == 'W' ) exit(-1);
			if ( s[0] == 'E' ) ans = mid, l = mid + 1;
			else r = mid - 1;
		} cout << "! " << len + ans + 1 << endl;
	}
	return 0;
}