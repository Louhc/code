#include<bits/stdc++.h>
using namespace std;
#define fp(i, b, e) for ( int i = b, I = e; i <= I; ++i )
#define fd(i, b, e) for ( int i = b, I = e; i >= I; --i )
#define go(i, b) for ( int i = b, v = to[b]; i; v = to[i = nxt[i]] )
#define i64 long long
inline bool cmin( int &x, int y ){ return x > y ? x = y, 1 : 0; }
inline bool cmax( int &x, int y ){ return x < y ? x = y, 1 : 0; }

const int _ = 5e3 + 55;
int N, a[_];
int f[_][3];

int main(){
	scanf( "%d", &N );
	fp( i, 1, N ) scanf( "%d", a + i );
	memset(f, 0x3f, sizeof f), f[0][0] = f[1][2] = 0;
	fp( i, 2, N ) fd( j, (i + 1) >> 1, 1 ){
		f[j][0] = min(f[j][0], f[j][1]);
		f[j][1] = f[j][2] + max(0, a[i] - a[i - 1] + 1);
		f[j][2] = min(f[j - 1][0] + max(0, a[i - 1] - a[i] + 1), f[j - 1][1] + max(0, min(a[i - 1], a[i - 2] - 1) - a[i] + 1));
	} fp( i, 1, (N + 1) >> 1 ) printf( "%d ", min(f[i][0], min(f[i][1], f[i][2])));
	return 0;
}
