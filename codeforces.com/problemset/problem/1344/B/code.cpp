#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define open(s) freopen( s".in", "r", stdin ), freopen( s".out", "w", stdout )
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline bool cmax( T &x, T y ){ return x < y ? x = y, 1 : 0; }
template<typename T> inline bool cmin( T &x, T y ){ return y < x ? x = y, 1 : 0; }

int N, M;
char s[1005][1005];
int a[1005][1005], num;
const int dr[][2] = {1, 0, 0, 1, -1, 0, 0, -1};
queue<pair<int, int> > Q;
void BFS( int x, int y ){
	Q.push(make_pair(x, y)); s[x][y] = 0; a[x][y] = ++num;
	while( !Q.empty() ){
		int cx(Q.front().first), cy(Q.front().second), tx, ty; Q.pop();
		fp( i, 0, 3 ){
			tx = cx + dr[i][0];
			ty = cy + dr[i][1];
			if ( s[tx][ty] ) Q.push(make_pair(tx, ty)), s[tx][ty] = 0, a[tx][ty] = num;
		}
	}
}

int main(){
	scanf( "%d%d", &N, &M );
	fp( i, 1, N ){
		scanf( "%s", s[i] + 1 );
		fp( j, 1, M ) s[i][j] = s[i][j] == '#';
	}
	fp( i, 1, N ) fp( j, 1, M ) if ( s[i][j] ) BFS(i, j);
	bool flg1(0), flg2(0);
	fp( i, 1, N ){
		int flg(-1), s(0);
		fp( j, 1, M ){
			if ( a[i][j] ){
				if ( s == 2 ) printf("-1\n"), exit(0);
				s = 1;
				if ( flg == -1 ) flg = a[i][j];
				else if ( flg != a[i][j] ) printf("-1\n"), exit(0);
			} else if ( s == 1 ) s = 2;
		}
		flg1 |= flg == -1;
	}
	fp( j, 1, M ){
		int flg(-1), s(0);
		fp( i, 1, N ){
			if ( a[i][j] ){
				if ( s == 2 ) printf("-1\n"), exit(0);
				s = 1;
				if ( flg == -1 ) flg = a[i][j];
				else if ( flg != a[i][j] ) printf("-1\n"), exit(0);
			} else if ( s == 1 ) s = 2;
		}
		flg2 |= flg == -1;
	}
	if ( flg1 ^ flg2 ) printf("-1\n"), exit(0);
	printf( "%d\n", num );
	return 0;
}