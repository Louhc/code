#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline bool cmax( T &x, T y ){ return x < y ? x = y, 1 : 0; }
template<typename T> inline bool cmin( T &x, T y ){ return y < x ? x = y, 1 : 0; }

struct node{ int x, y; node( int a = 0, int b = 0 ):x(a), y(b){} };
struct dl{ node p; int t; dl( node a = node(0, 0), int b = 0 ):p(a), t(b){} };

int N, M, Q, ans[2000005], a[305][305], b[305][305];
vector<node> vec[2000005];
vector<dl> d[2000005];
int fa[90005];
int id( int x, int y ){ return (x - 1) * M + y; }

int find( int x ){ return fa[x] > 0 ? fa[x] = find(fa[x]) : x; }
int Merge( int x, int y ){
	x = find(x), y = find(y);
	if ( x == y ) return 0;
	fa[y] = x; return 1;
}

int main(){
	scanf( "%d%d%d", &N, &M, &Q );
	ans[0] = 1;
	int x, y, z;
	fp( i, 1, Q ){
		scanf( "%d%d%d", &x, &y, &z ), ans[i] = 1;
		if ( !vec[z].size() ) fp( j, 1, N * M ) fa[j] = 0;
		vec[z].push_back(node(x, y));
		d[a[x][y]].push_back(dl(node(x, y), i)), a[x][y] = z;
		if ( a[x - 1][y] == z ) ans[i] -= Merge(id(x, y), id(x - 1, y));
		if ( a[x + 1][y] == z ) ans[i] -= Merge(id(x, y), id(x + 1, y));
		if ( a[x][y - 1] == z ) ans[i] -= Merge(id(x, y), id(x, y - 1));
		if ( a[x][y + 1] == z ) ans[i] -= Merge(id(x, y), id(x, y + 1));
	}
	fp( i, 1, N ) b[i][0] = b[i][M + 1] = -1;
	fp( i, 1, M ) b[0][i] = b[N + 1][i] = -1;
	fp( k, 0, z ){
		fp( i, 1, N * M ) fa[i] = 0;
		reverse(d[k].begin(), d[k].end());
		fp( i, 1, N ) fp( j, 1, M ){
			if ( a[i][j] == k ){
				b[i][j] = k;
				if ( b[i - 1][j] == k ) Merge(id(i, j), id(i - 1, j));
				if ( b[i][j - 1] == k ) Merge(id(i, j - 1), id(i, j));
			} else b[i][j] = -1;
		}
		for ( auto i : d[k] ){
			--ans[i.t]; b[i.p.x][i.p.y] = k;
			if ( b[i.p.x - 1][i.p.y] == k ) ans[i.t] += Merge(id(i.p.x, i.p.y), id(i.p.x - 1, i.p.y));
			if ( b[i.p.x + 1][i.p.y] == k ) ans[i.t] += Merge(id(i.p.x, i.p.y), id(i.p.x + 1, i.p.y));
			if ( b[i.p.x][i.p.y - 1] == k ) ans[i.t] += Merge(id(i.p.x, i.p.y), id(i.p.x, i.p.y - 1));
			if ( b[i.p.x][i.p.y + 1] == k ) ans[i.t] += Merge(id(i.p.x, i.p.y), id(i.p.x, i.p.y + 1));
		}
	}
	fp( i, 1, Q ) printf( "%d\n", ans[i] += ans[i - 1] );
	return 0;
}
