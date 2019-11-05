#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
template<typename T> inline bool cmin( T &x, T y ){ return y < x ? x = y, 1 : 0; }

int N, p[55];
string s[55], m[55], l[55], ans;
bool cmp( int x, int y ){ return m[x] == m[y] ? l[x] < l[y] : m[x] > m[y]; }

signed main(){
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0), cin >> N;
	fp( i, 1, N ){
		cin >> s[i], m[i] = s[i], l[i] = "", p[i] = i;
		fp( j, 1, s[i].size() ){
			string a = s[i].substr(0, j), b = s[i].substr(j); bool ok(1);
			while( 1 ){
				if ( a > b ){ ok = 0; break; }
				if ( b.substr(0, a.size()) == a ) b = b.substr(a.size()); else break;
			} if ( ok ){ m[i] = a, l[i] = b; break; }
		} string t = m[i]; while( t.size() < 50 ) t += m[i];
		m[i] = t.substr(0, 50), l[i] += 'U';
	} sort( p + 1, p + N + 1, cmp );
	fp( i, 1, N ){
		string t(ans); ans = 'U';
		fp( j, 1, s[p[i]].size() ) cmin( ans, s[p[i]].substr(0, j) + t );
	} cout << ans + '\n';
	return 0;
}
