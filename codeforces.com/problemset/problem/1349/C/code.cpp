#include<bits/stdc++.h>
using namespace std;
#define fp(i, b, e) for ( int i = b, I = e; i <= I; ++i )
#define fd(i, b, e) for ( int i = b, I = e; i >= I; --i )
#define go(i, b) for ( int i = b, v = to[b]; i; v = to[i = nxt[i]] )
#define i64 long long
inline bool cmin( int &x, int y ){ return x > y ? x = y, 1 : 0; }
inline bool cmax( int &x, int y ){ return x < y ? x = y, 1 : 0; }

const int _ = 1055;
int N, M, T;
char a[_][_];
int f[_][_];
queue<pair<int, int> > Q;

int main(){
	scanf( "%d%d%d", &N, &M, &T );
	fp( i, 1, N ) fp( j, 1, M ) while( (a[i][j] = getchar()) != '0' && a[i][j] != '1' );
	memset(f, 0x7f, sizeof f);
	fp( i, 1, N ) fp( j, 1, M )
		if ( a[i][j] == a[i - 1][j] || a[i][j] == a[i + 1][j] || a[i][j] == a[i][j - 1] || a[i][j] == a[i][j + 1] )
			f[i][j] = 0, Q.push(make_pair(i, j));
	while( !Q.empty() ){
		int x(Q.front().first), y(Q.front().second); Q.pop();
		// cerr << x << "   " << y << "   " << f[x][y] << endl;
		if ( f[x][y] > 1e9 ) continue;
		int tx, ty;
		tx = x + 1, ty = y;
		if ( tx > 0 && ty > 0 && tx <= N && ty <= M && f[tx][ty] > 1e9 ){
			f[tx][ty] = f[x][y] + 1;
			Q.push(make_pair(tx, ty));
		}
		tx = x - 1, ty = y;
		if ( tx > 0 && ty > 0 && tx <= N && ty <= M && f[tx][ty] > 1e9 ){
			f[tx][ty] = f[x][y] + 1;
			Q.push(make_pair(tx, ty));
		}
		tx = x, ty = y + 1;
		if ( tx > 0 && ty > 0 && tx <= N && ty <= M && f[tx][ty] > 1e9 ){
			f[tx][ty] = f[x][y] + 1;
			Q.push(make_pair(tx, ty));
		}
		tx = x, ty = y - 1;
		if ( tx > 0 && ty > 0 && tx <= N && ty <= M && f[tx][ty] > 1e9 ){
			f[tx][ty] = f[x][y] + 1;
			Q.push(make_pair(tx, ty));
		}
	}
	i64 p; int x, y;
	while( T-- ){
		scanf( "%d%d%lld", &x, &y, &p );
		if ( f[x][y] > 1e9 || p <= f[x][y] || (p - f[x][y]) % 2 == 0 ) printf("%c\n", a[x][y]);
		else printf( "%c\n", '0' + '1' - a[x][y]);
	}
	return 0;
}