#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline bool cmax( T &x, T y ){ return x < y ? x = y, 1 : 0; }
template<typename T> inline bool cmin( T &x, T y ){ return y < x ? x = y, 1 : 0; }

int N, M;
string s, a[105], ss;
multiset<string> S;
int c[105][26], sum[26];

int main(){
	cin >> N;
	if ( N == 1 ){
		cout << "? 1 1" << endl;
		cin >> s;
		cout << "! " << s << endl;
		return 0;
	}
	M = N >> 1;
	if ( M == 1 ){
		cout << "? 1 1" << endl;
		cin >> ss;
	} else {
		cout << "? 1 " << M << endl;
		fp( i, 1, M * (M + 1) / 2 ){
			cin >> s;
			sort(s.begin(), s.end());
			S.insert(s);
		}
		cout << "? 2 " << M << endl;
		fp( i, 1, M * (M - 1) / 2 ){
			cin >> s;
			sort(s.begin(), s.end());
			S.erase(S.lower_bound(s));
		}
		fp( i, 1, M ) a[S.begin()->size()] = *S.begin(), S.erase(S.begin());
		fp( i, 1, M ) fp( j, 0, i - 1 )
			if ( i == 1 || a[i][j] != a[i - 1][j] ){
				ss += a[i][j]; break;
			}
	}
	cout << "? 1 " << N << endl;
	fp( i, 1, N * (N + 1) / 2 ){
		cin >> s; for ( char j : s ) ++c[s.size()][j - 'a'];
	}
	cout << "! " + ss;
	if ( N & 1 ) fp( i, 0, 25 ) if ( c[M + 1][i] - c[M][i] > 0 ){ putchar(i + 'a'); break; }
	fd( i, M, 1 ) fp( j, 0, 25 )
		if ( c[i][j] - c[i - 1][j] + c[i][j] - c[i + 1][j] - (ss[i - 1] == j + 'a') > 0 ){ putchar(j + 'a'); break; } 
	cout << endl;
	return 0;
}