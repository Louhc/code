#include<bits/stdc++.h>
using namespace std;
#define fp(i, b, e) for ( int i = b, I = e; i <= I; ++i )
#define fd(i, b, e) for ( int i = b, I = e; i >= I; --i )
#define go(i, b) for ( int i = b, v = to[b]; i; v = to[i = nxt[i]] )
#define i64 long long
inline bool cmin( int &x, int y ){ return x > y ? x = y, 1 : 0; }
inline bool cmax( int &x, int y ){ return x < y ? x = y, 1 : 0; }

const int _ = 1e5 + 55;
int N, n;
int p[_], a[_], cnt[_<<1];
bool vis[_<<1];

int main(){
	scanf( "%d", &N );
	fp( i, 1, N ) scanf( "%d", a + i );
	fp( i, 2, 2e5 ) if ( !vis[i] ){
		p[++n] = i;
		for ( int j = i << 1; j <= 2e5; j += i )
			vis[j] = 1;
	}
	i64 ans(1);
	fp( i, 1, n ){
		if ( p[i] > 450 ) break;
		int t, t1(1e9), t2(1e9);
		fp( j, 1, N ){
			t = 0;
			while( a[j] % p[i] == 0 ) a[j] /= p[i], ++t;
			if ( t < t1 ) t2 = t1, t1 = t;
			else if ( t < t2 ) t2 = t;
		}
		fp( j, 1, max(t1, t2) ) ans *= p[i];
	}
	fp( i, 1, N ) ++cnt[a[i]];
	fp( i, 2, 2e5 ){
		if ( cnt[i] + 1 >= N ) ans = ans * i;
	}
	cout << ans << endl;
	return 0;
}