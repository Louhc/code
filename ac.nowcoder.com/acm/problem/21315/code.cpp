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

int N, M, n, w;
double ans;

struct node{ int x, y; }a[55], b[55];
struct D{
	double d; bool c;
	bool operator < ( const D &t )const{ return d < t.d; }
} c[105];

inline double sqr( double x ){ return x * x; }
inline double dist( node a, node b ){ return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));}

signed main(){
	cin >> N >> M;
	fp( i, 1, N ) cin >> a[i].x; fp( i, 1, N ) cin >> a[i].y;
	fp( i, 1, M ) cin >> b[i].x; fp( i, 1, M ) cin >> b[i].y;
	fp( i, 1, M ){
		n = 0;
		fp( j, 1, N ) c[++n].d = dist(a[j], b[i]), c[n].c = 1;
		fp( j, 1, M ) if ( j != i ) c[++n].d = dist(b[j], b[i]), c[n].c = 0;
		sort( c + 1, c + n + 1 );
		fp( j, 1, n ) if ( c[j].c ){ ans += c[j].d / j; break; } else ans += c[j].d / (j * (j + 1));
	} printf( "%.10lf\n", ans );
	return 0;
}