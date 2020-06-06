#include<cstdio>
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )

const int _ = 1e6 + 66;
int N, Q, tr[_<<2], x;

void Add( int c, int l, int r, int x ){
	++tr[c]; if ( l == r ) return;
	const int mid((l + r) >> 1), ls(c << 1), rs(ls | 1);
	if ( x <= mid ) Add(ls, l, mid, x); else Add(rs, mid + 1, r, x);
}

void Get( int c, int l, int r, int k ){
	--tr[c]; if ( l == r ) return;
	const int mid((l + r) >> 1), ls(c << 1), rs(ls | 1);
	if ( tr[ls] >= k ) Get(ls, l, mid, k); else Get(rs, mid + 1, r, k - tr[ls]);
}

int main(){
	scanf( "%d%d", &N, &Q );
	fp( i, 1, N ) scanf( "%d", &x ), Add(1, 1, N, x);
	fp( i, 1, Q ) scanf( "%d", &x ), x < 0 ? Get(1, 1, N, -x) : Add(1, 1, N, x);
	if ( tr[1] ){
		int c = 1, l = 1, r = N;
		while( l < r ){
			if ( tr[c << 1] ) c <<= 1, r = ((l + r) >> 1);
			else c = c << 1 | 1, l = ((l + r) >> 1) + 1;
		} printf( "%d\n", l );
	} else printf( "%d\n", 0 );
	return 0;
}