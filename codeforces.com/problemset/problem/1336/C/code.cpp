#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline bool cmax( T &x, T y ){ return x < y ? x = y, 1 : 0; }
template<typename T> inline bool cmin( T &x, T y ){ return y < x ? x = y, 1 : 0; }

const int mod = 998244353;
string S, T;
int N, M, E, c[26], f[3005][3005], ans;
void add( int &x, int y ){ x += y; if (x > mod) x -= mod; }

int main(){
	cin >> S >> T;
	N = S.size(), M = T.size();
	S = " " + S, T = " " + T;
	fp( i, 1, N ) f[i][i] = i > M || S[1] == T[i] ? 2 : 0;
	fp( l, 2, N ){
		fp( i, 1, N - l + 1 ){
			int j = i + l - 1;
			if ( i > M || S[l] == T[i] ) add(f[i][j], f[i + 1][j]);
			if ( j > M || S[l] == T[j] ) add(f[i][j], f[i][j - 1]);
		}
	}
	fp( i, M, N ) add(ans, f[1][i]);
	printf( "%d\n", ans );
	return 0;
}
