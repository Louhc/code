#include<bits/stdc++.h>
using namespace std;
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
template<typename T> inline bool cmin( T &x, T y ){ return y < x ? x = y, 1 : 0; }

const int MAXN = 2e3 + 15;
struct node{ int ls, rs; }o[MAXN], p[MAXN];
int ans(1e9), tmp, n, cnt, cur; char s[MAXN];

void Build( int &c ){
	if ( !c ) c = ++cnt;
	char t(s[n++]);
	if ( t & 1 ) Build(o[c].ls);
	if ( t & 2 ) Build(o[c].rs);
}
void Merge( int &c, int l ){
	if ( !c ) c = ++cnt;
	if ( l == cur ) return;
	if ( o[l].ls ) Merge(p[c].ls, o[l].ls);
	if ( o[l].rs ) Merge(p[c].rs, o[l].rs);
}

char pth[MAXN];
void Work( int c, int stp ){
	if ( c != 1 ){
		memset( p, 0, sizeof p ), cnt = cur = 1;
		while( cur ){
			const int t(cur);
			fp( i, 0, stp - 1 ) cur = pth[i] == 'L' ? o[cur].ls : o[cur].rs;
			Merge(tmp = 1, t);
		} cmin( ans, (cnt - 1) * 2 - stp );
	}
	pth[stp] = 'L';
	if ( o[c].ls ) Work(o[c].ls, stp + 1);
	pth[stp] = 'R';
	if ( o[c].rs ) Work(o[c].rs, stp + 1);
}


signed main(){
	scanf( "%s", s ), n = 0, cnt = 1;
	Build(tmp = 1), Work(1, 0);
	printf( "%d\n", ans );
	return 0;
}
