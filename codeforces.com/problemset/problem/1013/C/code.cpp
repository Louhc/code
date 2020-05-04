#include<bits/stdc++.h>
using namespace std;
#define fp(i, b, e) for ( int i = b, I = e; i <= I; ++i )
#define fd(i, b, e) for ( int i = b, I = e; i >= I; --i )
#define go(i, b) for ( int i = b, v = to[b]; i; v = to[i = nxt[i]] )
#define i64 long long
inline bool cmin( i64 &x, i64 y ){ return x > y ? x = y, 1 : 0; }

const int _ = 2e5 + 55;
int N, a[_];
i64 ans(1e18);

int main(){
	scanf( "%d", &N );
	fp( i, 1, N * 2 ) scanf( "%d", a + i );
	sort(a + 1, a + N + N + 1);
	ans = (i64)(a[N] - a[1]) * (a[N * 2] - a[N + 1]);
	fp( i, 1, N - 1 ) cmin(ans, (i64)(a[i + N] - a[i + 1]) * (a[N * 2] - a[1]));
	cout << ans << endl;
	return 0;
}