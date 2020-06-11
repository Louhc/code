#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline bool cmax( T &x, T y ){ return x < y ? x = y, 1 : 0; }
template<typename T> inline bool cmin( T &x, T y ){ return y < x ? x = y, 1 : 0; }

const int _ = 555;
int T, N;
multiset<pair<int, int> > S;
int a[_], b[_];

int main(){
	cin >> T;
	while( T-- ){
		cin >> N;
		fp( i, 1, N ) cin >> a[i];
		fp( i, 1, N ) cin >> b[i];
		if ( (N & 1) && a[(N + 1) >> 1] != b[(N + 1) >> 1] ){
			cout << "No" << endl;
			continue;
		}
		S.clear();
		fp( i, 1, N >> 1 ) S.insert(make_pair(min(a[i], a[N - i + 1]), max(a[i], a[N - i + 1])));
		bool flg(1);
		fp( i, 1, N >> 1 ){
			if ( !S.count(make_pair(min(b[i], b[N - i + 1]), max(b[i], b[N - i + 1]))) ){
				cout << "No" << endl; flg = 0; break;
			}
			S.erase(S.lower_bound(make_pair(min(b[i], b[N - i + 1]), max(b[i], b[N - i + 1]))));
		}
		if ( flg ) cout << "Yes" << endl;
	}
	return 0;
}
