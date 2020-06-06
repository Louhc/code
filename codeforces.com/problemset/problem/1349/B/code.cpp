#include<bits/stdc++.h>
using namespace std;
#define fp(i, b, e) for ( int i = b, I = e; i <= I; ++i )
#define fd(i, b, e) for ( int i = b, I = e; i >= I; --i )
#define go(i, b) for ( int i = b, v = to[b]; i; v = to[i = nxt[i]] )
#define i64 long long
inline bool cmin( int &x, int y ){ return x > y ? x = y, 1 : 0; }
inline bool cmax( int &x, int y ){ return x < y ? x = y, 1 : 0; }

const int _ = 1e5 + 55, mod = 998244353;
int T, N, K, M;
int a[_], b[_];

int main(){
	scanf( "%d", &T );
	while( T-- ){
		scanf( "%d%d", &N, &K ), M = 0; bool flg(0);
		fp( i, 1, N ){
			scanf( "%d", a + i );
			if ( a[i] == K ) flg = 1;
			if ( a[i] >= K ) b[++M] = i;
		}
		if ( !flg ){ printf( "no\n"); continue; }
		if ( N == 1 && a[N] == K ){ printf( "yes\n"); continue; }
		flg = 0;
		fp( i, 2, M ) if ( b[i] - b[i - 1] <= 2 ){ printf( "yes\n"); flg = 1; break; }
		if ( !flg ) cout << "no" << endl;
	}
	return 0;
}