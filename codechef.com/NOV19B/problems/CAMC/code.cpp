#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define f80 long double
#define rgt register
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline bool cmax( T &x, T y ){ return x < y ? x = y, 1 : 0; }
template<typename T> inline bool cmin( T &x, T y ){ return y < x ? x = y, 1 : 0; }
#define getchar() ( p1 == p2 && ( p1 = bf, p2 = bf + fread( bf, 1, 1 << 21, stdin ), p1 == p2 ) ? EOF : *p1++ )
char bf[1 << 21], *p1(bf), *p2(bf);
template<typename T>
inline void read( T &x ){ char t(getchar()), flg(0); x = 0;
	for ( ; !isdigit(t); t = getchar() ) flg = t == '-';
	for ( ; isdigit(t); t = getchar() ) x = x * 10 + ( t & 15 );
	flg ? x = -x : x;
}

const int MAXN = 1e5 + 15;
int T, N, M;
struct node{
	int x, b;
	bool operator < ( const node &t ){ return x < t.x; }
}a[MAXN];
vector<int> v[MAXN];
vector<int>::iterator p[MAXN];

signed main(){
	read(T);
	while( T-- ){
		read(N), read(M);
		fp( i, 1, N ) read(a[i].x), v[a[i].b = i % M].push_back(a[i].x);
		int ans(2e9), cur(0); bool flg(1); sort(a + 1, a + N + 1);
		fp( i, 0, M - 1 ) sort(v[i].begin(), v[i].end()), p[i] = v[i].begin(), cmax(cur, *p[i] - a[1].x);
		for ( int i = 1; flg && i <= N; ){
			cmin(ans, cur); int t(a[i].x), d(0);
			while( i <= N && a[i].x == t ){
				if ( ++p[a[i].b] == v[a[i].b].end() ){ flg = 0; break; }
				cmax(d, *p[a[i].b]), ++i;
			} cur = max(cur - (a[i].x - a[i - 1].x), d - a[i].x);
		} printf( "%d\n", ans ); fp( i, 0, M - 1 ) v[i].clear();
	}
	return 0;
}
