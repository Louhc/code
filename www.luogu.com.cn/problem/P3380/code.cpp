#include<bits/stdc++.h>
using namespace std;
#define fp( i, b, e ) for ( int i = b, I = e; i <= I; ++i )

const int _ = 5e4 + 55;

int n, m;
int opt[_], oa[_], ob[_], oc[_];
int a[_], b[_<<1], nn;

struct node{
	int l, r, s;
}w[_<<7]; int cnt;

int T[_];

void Change( int c, int l, int r, int x, int y ){
	if ( l == r ) return void(w[c].s += y);
	int mid((l + r) >> 1);
	if ( x <= mid ){
		if ( !w[c].l ) w[c].l = ++cnt;
		Change(w[c].l, l, mid, x, y);
	}else{
		if ( !w[c].r ) w[c].r = ++cnt;
		Change(w[c].r, mid + 1, r, x, y);
	}
	w[c].s = w[w[c].l].s + w[w[c].r].s;
}

int Query( int c, int l, int r, int L, int R ){
	if ( L <= l && r <= R ) return w[c].s;
	if ( r < L || R < l || !c ) return 0;
	int mid((l + r) >> 1);
	return Query( w[c].l, l, mid, L, R ) + Query( w[c].r, mid + 1, r, L, R );
}

void Add( int x, int y, int z ){
	for ( ; x <= n; x += x & -x ) Change( T[x], 1, nn, y, z );
}

int t1[50], n1, t2[50], n2;
void work( int l, int r ){
	n1 = n2 = 0;
	for ( ; r; r -= r & -r ) t1[++n1] = T[r];
	for ( l -= 1; l; l -= l & -l ) t2[++n2] = T[l];
}

int Qk( int v ){
	int ans(0);
	fp( i, 1, n1 ) ans += Query( t1[i], 1, nn, 1, v - 1 );
	fp( i, 1, n2 ) ans -= Query( t2[i], 1, nn, 1, v - 1 );
	return ans + 1;
}

int Qv( int l, int r, int k ){
	if ( l == r ) return l;
	int ans(0), mid((l + r) >> 1);
	fp( i, 1, n1 ) ans += w[w[t1[i]].l].s;
	fp( i, 1, n2 ) ans -= w[w[t2[i]].l].s;
	// cout << l << " " << r << " " << ans << endl;
	if ( ans >= k ){
		fp( i, 1, n1 ) t1[i] = w[t1[i]].l;
		fp( i, 1, n2 ) t2[i] = w[t2[i]].l;
		return Qv( l, mid, k );
	}else{
		fp( i, 1, n1 ) t1[i] = w[t1[i]].r;
		fp( i, 1, n2 ) t2[i] = w[t2[i]].r;
		return Qv( mid + 1, r, k - ans );
	}
}

void print( int c, int l, int r ){
	if ( !c ) return;
	printf( "%d %d %d %d\n", c, l, r, w[c].s );
	int mid((l + r) >> 1);
	print(w[c].l, l, mid), print(w[c].r, mid + 1, r);
}

int main(){
	scanf( "%d%d", &n, &m ), nn = n;
	fp( i, 1, n ) scanf( "%d", a + i ), b[i] = a[i];
	fp( i, 1, m ){
		scanf( "%d%d%d", opt + i, oa + i, ob + i );
		if ( opt[i] != 3 ) scanf( "%d", oc + i );
		if ( opt[i] == 3 ) b[++nn] = ob[i];
		else if ( opt[i] != 2 ) b[++nn] = oc[i];
	}
	sort( b + 1, b + nn + 1 );
	nn = unique(b + 1, b + nn + 1) - b - 1;
	fp( i, 1, n ) a[i] = lower_bound(b + 1, b + nn + 1, a[i]) - b;
	fp( i, 1, m ){
		if ( opt[i] == 3 ) ob[i] = lower_bound(b + 1, b + nn + 1, ob[i]) - b;
		else if ( opt[i] != 2 ) oc[i] = lower_bound(b + 1, b + nn + 1, oc[i]) - b;
	}
	fp( i, 1, n ) T[i] = ++cnt;
	fp( i, 1, n ) Add( i, a[i], 1 );
	int k;
	// fp( i, 1, n ) print(T[i], 1, nn);
	fp( i, 1, m ){
		switch( opt[i] ){
			case 1 : work(oa[i], ob[i]); printf( "%d\n", Qk(oc[i]) ); break;
			case 2 : work(oa[i], ob[i]); printf( "%d\n", b[Qv(1, nn, oc[i])] ); break;
			case 3 : Add( oa[i], a[oa[i]], -1 ); Add( oa[i], a[oa[i]] = ob[i], 1 ); break;
			case 4 :
				work(oa[i], ob[i]); k = Qk(oc[i]) - 1;
				if ( k == 0 ) printf("-2147483647\n");
				else work(oa[i], ob[i]), printf( "%d\n", b[Qv(1, nn, k)] );
				break;
			case 5 :
				work(oa[i], ob[i]); k = Qk(oc[i] + 1) - 1;
				if ( k == ob[i] - oa[i] + 1 ) printf("2147483647\n");
				else work(oa[i], ob[i]), printf( "%d\n", b[Qv(1, nn, k + 1)] );
				break;
		}
	}
	return 0;
}