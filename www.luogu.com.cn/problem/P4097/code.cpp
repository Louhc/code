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
double k[100055], b[100055];
int tr[160000];

double calc( int i, int x ){
	return k[i] * x + b[i];
}

void Modify( int c, int l, int r, int L, int R, int i ){
	if ( l > R || L > r ) return;
	const int mid((l + r) >> 1), ls(c << 1), rs(ls | 1);
	if ( L <= l && r <= R ){
		if ( tr[c] == 0 ) return tr[c] = i, void();
		if ( l == r ){
			if ( calc(i, l) > calc(tr[c], l) ) tr[c] = i;
			return;
		}
		if ( fabs(k[i] - k[tr[c]]) < 1e-8 ){
			if ( b[i] > b[tr[c]] ) tr[c] = i;
		} else if ( k[i] < k[tr[c]] ){
			if ( calc(i, mid) < calc(tr[c], mid) ) Modify( ls, l, mid, L, R, i );
			else Modify( rs, mid + 1, r, L, R, tr[c] ), tr[c] = i;
		} else {
			if ( calc(i, mid) < calc(tr[c], mid) ) Modify( rs, mid + 1, r, L, R, i );
			else Modify( ls, l, mid, L, R, tr[c] ), tr[c] = i;
		}
	} else 
		Modify(ls, l, mid, L, R, i), Modify(rs, mid + 1, r, L, R, i);
}

pair<double, int> Query( int c, int l, int r, int x ){
	if ( l == r ) return make_pair(calc(tr[c], x), tr[c]);
	const int mid((l + r) >> 1), ls(c << 1), rs(ls | 1);
	return max(x <= mid ? Query(ls, l, mid, x) : Query(rs, mid + 1, r, x), make_pair(calc(tr[c], x), tr[c]));
}

int main(){
	scanf( "%d", &N );
	int opt, x, y, xx, yy, lastans = 0;
	fp( i, 1, N ){
		scanf( "%d", &opt );
		if ( opt ){
			scanf( "%d%d%d%d", &x, &y, &xx, &yy ), ++M;
			x = (x + lastans - 1) % 39989 + 1;
			xx = (xx + lastans - 1) % 39989 + 1;
			y = (y + lastans - 1) % 1000000000 + 1;
			yy = (yy + lastans - 1) % 1000000000 + 1;
			if ( x == xx ) k[M] = 0, b[M] = max(y, yy);
			else k[M] = 1. * (y - yy) / (x - xx), b[M] = y - k[M] * x;
			Modify(1, 1, 39989, min(x, xx), max(x, xx), M);
		} else {
			scanf( "%d", &x );
			x = (x + lastans - 1) % 39989 + 1;
			lastans = Query(1, 1, 39989, x).second;
			printf( "%d\n", lastans );
		}
	}
	return 0;
}