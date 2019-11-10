#include<bits/stdc++.h>
using namespace std;
#define rgt register
#pragma GCC optimize(3)
#define fp( i, b, e ) for ( rgt short i(b), I(e); i <= I; ++i )
inline void cmax( short &x, short y ){ x < y ? x = y : x; }

short v[9][9], s[9], h, tot(0); const short all = (1 << 9) - 1;
short a[9], b[9], c[9], cnt[512], w[512];
short ans(-1);
const short f[9][9] = {{1,1,1,2,2,2,3,3,3},{1,1,1,2,2,2,3,3,3},{1,1,1,2,2,2,3,3,3},{4,4,4,5,5,5,6,6,6},{4,4,4,5,5,5,6,6,6},{4,4,4,5,5,5,6,6,6},{7,7,7,8,8,8,9,9,9},{7,7,7,8,8,8,9,9,9},{7,7,7,8,8,8,9,9,9}};
const short g[9][9] = {{6,6,6,6,6,6,6,6,6},{6,7,7,7,7,7,7,7,6},{6,7,8,8,8,8,8,7,6},{6,7,8,9,9,9,8,7,6},{6,7,8,9,10,9,8,7,6},{6,7,8,9,9,9,8,7,6},{6,7,8,8,8,8,8,7,6},{6,7,7,7,7,7,7,7,6},{6,6,6,6,6,6,6,6,6}};
inline short Get( rgt short x, rgt short y ){ return a[x] | b[y] | c[f[x][y]]; }
struct node{
	short x, y;
	bool operator < ( const node &t )const{ return Get(x, y) > Get(t.x, t.y); }
}o[100];

void DFS( rgt short t, rgt short sum ){
	if ( t > tot ) return cmax( ans, sum );
	if ( sum + (tot - t + 1) * 9 * 10 <= ans ) return;
	const short x(o[t].x), y(o[t].y);
	for ( rgt short i(Get(x, y) ^ all), j(i & -i), k(w[j]); i; i -= j, j = i & -i, k = w[j] )
		a[x] |= j, b[y] |= j, c[f[x][y]] |= j, DFS( t + 1, sum + g[x][y] * (k + 1) ), a[x] ^= j, b[y] ^= j, c[f[x][y]] ^= j;
}

signed main(){
	srand(time(0));
	fp( i, 0, 8 ) fp( j, 0, 8 ){
		cin >> v[i][j];
		if ( v[i][j] ){
			h += g[i][j] * v[i][j], a[i] |= 1 << (v[i][j] - 1),
			b[j] |= 1 << (v[i][j] - 1), c[f[i][j]] |= 1 << (v[i][j] - 1);
		} else o[++tot].x = i, o[tot].y = j;
	} fp( i, 1, (1 << 9) - 1 ) cnt[i] = cnt[i >> 1] + (i & 1);
	fp( i, 0, 8 ) w[1 << i] = i;
	sort( o + 1, o + tot + 1 );
	DFS(1, h), cout << ans;
	return 0;
}