#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline bool cmax( T &x, T y ){ return x < y ? x = y, 1 : 0; }
template<typename T> inline bool cmin( T &x, T y ){ return y < x ? x = y, 1 : 0; }

int N;
string s, a[105];
multiset<string> S;
int c[105][26];

int main(){
	cin >> N;
	if ( N == 1 ){
		cout << "? 1 1" << endl;
		cin >> s;
		cout << "! " << s << endl;
		return 0;
	}
	cout << "? 1 " << N << endl;
	fp( i, 1, N * (N + 1) / 2 ){
		cin >> s;
		sort(s.begin(), s.end());
		S.insert(s);
	}
	cout << "? 2 " << N << endl;
	fp( i, 1, N * (N - 1) / 2 ){
		cin >> s;
		sort(s.begin(), s.end());
		S.erase(S.lower_bound(s));
	}
	cout << "! ";
	fp( i, 1, N ) a[S.begin()->size()] = *S.begin(), S.erase(S.begin());
	fp( i, 1, N ){
		fp( j, 0, a[i].size() - 1 ){
			if ( ++c[i][a[i][j] - 'a'] > c[i - 1][a[i][j] - 'a'] )
				cout << a[i][j];
		}
	} cout << endl;
	return 0;
}