#include<bits/stdc++.h>
using namespace std;
#define fp(i, b, e) for ( int i = b, I = e; i <= I; ++i )
#define fd(i, b, e) for ( int i = b, I = e; i >= I; --i )
#define go(i, b) for ( int i = b, v = to[b]; i; v = to[i = nxt[i]] )
#define i64 long long
inline bool cmin( int &x, int y ){ return x > y ? x = y, 1 : 0; }
inline bool cmax( int &x, int y ){ return x < y ? x = y, 1 : 0; }

const int _ = 2e5 + 55;
int N, M, Q;
int fa[_<<1];

int find( int x ){ return fa[x] >= 0 ? fa[x] = find(fa[x]) : x; }
void Merge( int x, int y ){
	x = find(x), y = find(y);
	if ( x == y ) return;
	if ( fa[x] < fa[y] ) fa[x] += fa[y], fa[y] = x;
	else fa[y] += fa[x], fa[x] = y;
}

int main(){
	scanf( "%d%d%d", &N, &M, &Q );
	memset(fa, -1, sizeof fa);
	int x, y;
	fp( i, 1, Q ){
		scanf( "%d%d", &x, &y );
		Merge(x, y + N);
	} int ans(0);
	fp( i, 1, N + M ) ans += fa[i] < 0;
	printf( "%d\n", ans - 1 );
	return 0;
}