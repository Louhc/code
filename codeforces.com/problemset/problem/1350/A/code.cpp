#include<bits/stdc++.h>
using namespace std;
#define fp(i, b, e) for ( int i = b, I = e; i <= I; ++i )
#define fd(i, b, e) for ( int i = b, I = e; i >= I; --i )
#define go(i, b) for ( int i = b, v = to[b]; i; v = to[i = nxt[i]] )
#define i64 long long
inline bool cmin( int &x, int y ){ return x > y ? x = y, 1 : 0; }
inline bool cmax( int &x, int y ){ return x < y ? x = y, 1 : 0; }

int T, N, K;

int main(){
	scanf( "%d", &T );
	while( T-- ){
		scanf( "%d%d", &N, &K );
		if ( N % 2 == 0 ) cout << N + K * 2ll << endl;
		else{
			bool flg = 1;
			for ( int i = 2; i * i <= N; ++i ) if ( N % i == 0 ){ N += i, flg = 0; break; }
			if ( flg ) N <<= 1;
			cout << N + (K - 1) * 2ll << endl;
		}
	}
	return 0;
}