#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline void cmax( T &x, T y ){ x < y ? x = y : x; }
template<typename T> inline void cmin( T &x, T y ){ y < x ? x = y : x; }
#define getchar() ( p1 == p2 && ( p1 = bf, p2 = bf + fread( bf, 1, 1 << 21, stdin ), p1 == p2 ) ? EOF : *p1++ )
char bf[1 << 21], *p1(bf), *p2(bf);
template<typename T>
inline void read( T &x ){ char t(getchar()), flg(0); x = 0;
	for ( ; !isdigit(t); t = getchar() ) flg = t == '-';
	for ( ; isdigit(t); t = getchar() ) x = x * 10 + ( t & 15 );
	flg ? x = -x : x;
}

struct vec{
	int x, y;
	vec(){}; vec( int a, int b ):x(a), y(b){}
	vec operator - ( const vec &t ){ return vec( x - t.x, y - t.y ); }
	double length(){ return sqrt(1ll * x * x + y * y); }
} p[306];
int gs[105], gt[105];
int nt[305], pr[305], bl[305];

inline int cross( vec A, vec B ){
	if ( A.x * B.y == A.y * B.x ) return 0;
	return A.x * B.y > A.y * B.x ? 1 : -1;
}

bool iscross( vec A, vec B, vec C, vec D ){
	if ( max( A.x, B.x ) < min( C.x, D.x ) || max( C.x, D.x ) < min( A.x, B.x ) || max( A.y, B.y ) < min( C.y, D.y ) || max( C.y, D.y ) < min( A.y, B.y ) ) return 0;
	if ( cross(B - A, C - A) * cross(B - A, D - A) > 0 ) return 0;
	if ( cross(D - C, A - C) * cross(D - C, B - C) > 0 ) return 0;
	return 1;
}

int N, M, S, T;
double d[305][305];

bool check( int s, int t ){
	if ( bl[s] == bl[t] && nt[s] != t && pr[s] != t ) return 0;
	fp( o, 1, N ) fp( i, gs[o], gt[o] ){
		int j(nt[i]), k(nt[j]);
		if ( i != s && i != t && j != s && j != t ){
			if ( iscross( p[s], p[t], p[i], p[nt[i]] ) ) return 0;
			if ( p[j].x < max(p[s].x,p[t].x) && p[j].x > min(p[s].x,p[t].x) && !cross(p[t]-p[s],p[j]-p[s]) && cross(p[t]-p[s],p[i]-p[s]) * cross(p[t]-p[s],p[k]-p[s]) < 0 ) return 0;
		}
	} return 1;
}

signed main(){
	read(N);
	fp( i, 1, N ){
		gs[i] = M + 1;
		int t; read(t), M += t;
		gt[i] = M;
		fp( j, gs[i], gt[i] ) read(p[j].x), read(p[j].y), nt[j] = j + 1, pr[j] = j - 1, bl[j] = i;
		nt[gt[i]] = gs[i], pr[gs[i]] = gt[i];
	} read(S), read(T);
	fp( i, 1, M ) fp( j, 1, M ) if ( i != j ) d[i][j] = 1e10;
	fp( i, 1, M ) fp( j, i + 1, M ) if ( check( i, j ) )
		d[j][i] = d[i][j] = (p[i] - p[j]).length();
	fp( k, 1, M ) fp( i, 1, M ) fp( j, 1, M )
		if ( d[i][k] + d[k][j] < d[i][j] ) d[i][j] = d[i][k] + d[k][j];
	printf( "%.4lf\n", d[S][T] );
	return 0;
}

