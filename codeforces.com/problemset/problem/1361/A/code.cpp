#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline bool cmax( T &x, T y ){ return x < y ? x = y, 1 : 0; }
template<typename T> inline bool cmin( T &x, T y ){ return y < x ? x = y, 1 : 0; }

const int _ = 5e5 + 55;
int N, M;
vector<int> e[_];
int t[_], p[_];
#define pb push_back

bool cmp( int x, int y ){ return t[x] < t[y]; }

int main(){
	scanf( "%d%d", &N, &M ); int x, y;
	fp( i, 1, M ) scanf( "%d%d", &x, &y ), e[x].pb(y), e[y].pb(x);
	fp( i, 1, N ) scanf( "%d", t + i ), p[i] = i;
	fp( i, 1, N ) sort(e[i].begin(), e[i].end(), cmp);
	sort(p + 1, p + N + 1, cmp);
	fp( i, 1, N ){
		int flg(-1);
		if ( !e[p[i]].size() || t[e[p[i]][0]] != 1 ) flg = 1;
		else{
			fp( j, 0, (int)e[p[i]].size() - 2 )
				if ( t[e[p[i]][j + 1]] > t[e[p[i]][j]] + 1 ){
					flg = t[e[p[i]][j]] + 1;
					break;
				}
		}
		if ( flg == -1 ) flg = t[e[p[i]][e[p[i]].size() - 1]] + 1;
		if ( flg != t[p[i]] ) return printf("-1\n"), 0;
	} fp( i, 1, N ) printf( "%d%c", p[i], "\n "[i < N] );
	return 0;
}