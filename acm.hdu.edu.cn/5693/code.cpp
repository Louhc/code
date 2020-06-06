#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
void cmax( int &x, int y ){ x < y ? x = y, 0 : 0; }

int T, N, M, a[305], x;
unordered_set<int> S;
int f[305][305];
bool g[305][305];

int F( int l, int r ){
	if ( f[l][r] >= 0 ) return f[l][r];
	f[l][r] = 0;
	if ( l >= r ) return 0;
	if ( g[l][r] && F(l + 1, r - 1) == r - l - 1 ) cmax(f[l][r], r - l + 1);
	fp( i, l, r ){
		cmax(f[l][r], F(l, i) + F(i + 1, r));
		if ( g[l][i] && a[i] * 2 == a[l] + a[r] && F(l + 1, i - 1) == i - l - 1 && F(i + 1, r - 1) == r - i - 1 )
			cmax(f[l][r], r - l + 1);
	}
	return f[l][r];
}

int main(){
	scanf( "%d", &T );
	while( T-- ){
		scanf( "%d%d", &N, &M );
		memset(f, -1, sizeof f);
		memset(g, 0, sizeof g);
		fp( i, 1, N ) scanf( "%d", a + i );
		S.clear();
		fp( i, 1, M ) scanf( "%d", &x ), S.insert(x);
		fp( i, 1, N ) fp( j, i + 1, N ) if ( S.count(a[j] - a[i]) ) g[i][j] = 1;
		printf( "%d\n", F(1, N) );
	}
	return 0;
}