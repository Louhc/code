#include<bits/stdc++.h>
using namespace std;
#define Re register
#define MAXN 2005
#define LD long double

int N, M, V, E;
int c[MAXN], d[MAXN];
LD r[MAXN];
LD dis[305][305];
LD f[MAXN][MAXN][2];

int main(){
	scanf( "%d%d%d%d", &N, &M, &V, &E );
	for ( int i = 1; i <= N; ++i ) scanf( "%d", &c[i] );
	for ( int i = 1; i <= N; ++i ) scanf( "%d", &d[i] );
	for ( int i = 1; i <= N; ++i ) scanf( "%Lf", &r[i] );
	int x, y, z;
	for ( int i = 1; i <= V; ++i )
		for ( int j = 1; j <= V; ++j )
			dis[i][j] = 1e15;
	for ( int i = 1; i <= V; ++i ) dis[i][i] = 0;
	for ( int i = 1; i <= E; ++i ) scanf( "%d%d%d", &x, &y, &z ), dis[x][y] = dis[y][x] = min( (LD)z, dis[x][y] );
	for ( int k = 1; k <= V; ++k )
		for ( int i = 1; i <= V; ++i )
			for ( int j = 1; j <= V; ++j )
				dis[i][j] = min( dis[i][j], dis[i][k] + dis[k][j] );
	
	for ( int i = 1; i <= N; ++i )
		for ( int j = 0; j <= M; ++j )
			f[i][j][0] = f[i][j][1] = 1e15;
	f[1][0][0] = 0; f[1][1][1] = 0;
	
	for ( int i = 2; i <= N; ++i )
		for ( int j = 0; j <= M; ++j ){
			f[i][j][0] = min( f[i - 1][j][0] + dis[c[i - 1]][c[i]],
			f[i - 1][j][1] + r[i - 1] * dis[d[i - 1]][c[i]] + ( 1 - r[i - 1] ) * dis[c[i - 1]][c[i]] );
			
			if ( j ) f[i][j][1] = min( f[i - 1][j - 1][0] + dis[c[i - 1]][d[i]] * r[i] + dis[c[i - 1]][c[i]] * ( 1 - r[i] ),
			f[i - 1][j - 1][1] + dis[d[i - 1]][d[i]] * r[i - 1] * r[i] + dis[d[i - 1]][c[i]] * r[i - 1] * ( 1 - r[i] )
			+ dis[c[i - 1]][d[i]] * ( 1 - r[i - 1] ) * r[i] + dis[c[i - 1]][c[i]] * ( 1 - r[i - 1] ) * ( 1 - r[i] ) );
		}
	LD ans(1e15);
	for ( int i = 0; i <= M; ++i ) ans = min( ans, min( f[N][i][0], f[N][i][1] ) );
	printf( "%.2Lf\n", ans );
	return 0;
}
