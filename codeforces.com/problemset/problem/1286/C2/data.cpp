#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline bool cmax( T &x, T y ){ return x < y ? x = y, 1 : 0; }
template<typename T> inline bool cmin( T &x, T y ){ return y < x ? x = y, 1 : 0; }

string s = "xasdungo";

int main(){
	cout << s.size() << endl;
	fp( i, 0, 3 ) fp( j, i, 3 ) cout << s.substr(i, j - i + 1) << endl;
	fp( i, 1, 3 ) fp( j, i, 3 ) cout << s.substr(i, j - i + 1) << endl;
	fp( i, 0, 7 ) fp( j, i, 7 ) cout << s.substr(i, j - i + 1) << endl;
	return 0;
}