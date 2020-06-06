#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define open(s) freopen( s".in", "r", stdin ), freopen( s".out", "w", stdout )
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline bool cmax( T &x, T y ){ return x < y ? x = y, 1 : 0; }
template<typename T> inline bool cmin( T &x, T y ){ return y < x ? x = y, 1 : 0; }

const int _ = 1e5 + 55;

int N;
double k[_], b[_];
char s[10]; int x;
int tr[_<<1];

double calc( int i, int x ){
	return x * k[i] + b[i];
}

void Modify( int c, int l, int r, int x ){
	if ( !tr[c] ) return tr[c] = x, void();
	if ( l == r ){
		if ( calc(tr[c], l) < calc(x, l) ) tr[c] = x;
		return;
	}
	const int mid((l + r) >> 1), ls(c << 1), rs(ls | 1);
	if ( fabs(k[tr[c]] - k[x]) < 1e-8 ){
		if ( b[tr[c]] < b[x] ) tr[c] = x;
	} else if ( k[tr[c]] < k[x] ){
		if ( calc(tr[c], mid) < calc(x, mid) )
			Modify( ls, l, mid, tr[c] ), tr[c] = x;
		else
			Modify( rs, mid + 1, r, x );
	} else {
		if ( calc(tr[c], mid) < calc(x, mid) )
			Modify( rs, mid + 1, r, tr[c] ), tr[c] = x;
		else
			Modify( ls, l, mid, x );
	}
}

double Query( int c, int l, int r, int x ){
	if ( l == r ) return calc(tr[c], x);
	const int mid((l + r) >> 1), ls(c << 1), rs(ls | 1);
	return max(x <= mid ? Query(ls, l, mid, x) : Query(rs, mid + 1, r, x), calc(tr[c], x));
}

int main(){
	scanf( "%d", &N );
	fp( i, 1, N ){
		scanf( "%s", s );
		if ( s[0] == 'P' ){
			scanf( "%lf%lf", b + i, k + i ), b[i] -= k[i];
			Modify(1, 1, 5e4, i);
		} else {
			scanf( "%d", &x );
			printf( "%d\n", (int)(Query(1, 1, 5e4, x) / 100) );
		}
	}
	return 0;
}