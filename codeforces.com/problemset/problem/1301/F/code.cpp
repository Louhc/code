#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline bool cmax( T &x, T y ){ return x < y ? x = y, 1 : 0; }
template<typename T> inline bool cmin( T &x, T y ){ return y < x ? x = y, 1 : 0; }

const int _ = 1005, dir[][2] = {1, 0, 0, 1, -1, 0, 0, -1};
int N, M, K, T;
int a[_][_], d[45][_][_];
#define pii pair<int, int>
vector<pii> v[45];
queue<pii> Q;
bool vis[45];

void work( int k ){
	while( Q.size() ) Q.pop();
	memset(d[k], 0x7f, sizeof d[k]), memset(vis, 0, sizeof vis);
	for ( auto i : v[k] ) Q.push(i), d[k][i.first][i.second] = 0;
	while( !Q.empty() ){
		int x(Q.front().first), y(Q.front().second), tx, ty; Q.pop();
		if ( !vis[a[x][y]] ){
			vis[a[x][y]] = 1;
			for ( auto i : v[a[x][y]] ){
				tx = i.first, ty = i.second;
				if ( d[k][tx][ty] > d[k][x][y] + 1 ){
					d[k][tx][ty] = d[k][x][y] + 1;
					Q.push(make_pair(tx, ty));
				}
			}
		}
		fp( i, 0, 3 ){
			tx = x + dir[i][0], ty = y + dir[i][1];
			if ( tx > N || ty > M || tx < 1 || ty < 1 ) continue;
			if ( d[k][tx][ty] > d[k][x][y] + 1 ){
				d[k][tx][ty] = d[k][x][y] + 1;
				Q.push(make_pair(tx, ty));
			}
		}
	}
}

int main(){
	scanf( "%d%d%d", &N, &M, &K );
	fp( i, 1, N ) fp( j, 1, M )
		scanf( "%d", a[i] + j ), v[a[i][j]].push_back(make_pair(i, j));
	fp( i, 1, K ) work(i);
	scanf( "%d", &T );
	while( T-- ){
		int sx, sy, tx, ty, ans;
		scanf( "%d%d%d%d", &sx, &sy, &tx, &ty );
		ans = abs(sx - tx) + abs(sy - ty);
		fp( i, 1, K ) cmin(ans, d[i][sx][sy] + d[i][tx][ty] + 1);
		printf( "%d\n", ans );
	}
	return 0;
}
