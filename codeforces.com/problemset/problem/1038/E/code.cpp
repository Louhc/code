#include<bits/stdc++.h>
using namespace std;
inline bool cmin( int &x, int y ){ return x > y ? x = y, 1 : 0; }
inline bool cmax( int &x, int y ){ return x < y ? x = y, 1 : 0; }
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[b]); i; v = to[i = nxt[i]] )
#define i64 long long
 
int N;
int f[105][105][5][5];
int x, y, z, ans;

int main(){
	scanf( "%d", &N );
	memset(f, 0xf3, sizeof f);
	fp( i, 1, N ) scanf( "%d%d%d", &x, &y, &z ), f[i][i][x][z] = f[i][i][z][x] = y, cmax(ans, y);
	fd( i, N, 1 ) fp( j, i, N )
		fp( x, 1, 4 ) fp( y, 1, 4 ){
			fp( k, i, j - 1 ){
				cmax(f[i][j][x][y], max(f[i][k][x][y], f[k + 1][j][x][y]));
				fp( p, 1, 4 ){
					cmax(f[i][j][x][y], f[i][k][x][p] + f[k + 1][j][p][y]),
					cmax(f[i][j][x][y], f[i][k][p][x] + f[k + 1][j][y][p]);
				}
			}
			cmax(ans, f[i][j][x][y]);
		}
	printf( "%d\n", ans );
	return 0;
}