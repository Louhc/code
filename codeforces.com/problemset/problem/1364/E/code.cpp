#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline bool cmax( T &x, T y ){ return x < y ? x = y, 1 : 0; }
template<typename T> inline bool cmin( T &x, T y ){ return y < x ? x = y, 1 : 0; }

int N, p[10000], ans[10000];

int qry( int x, int y ){
	int z;
	cout << "? " << p[x] << " " << p[y] << endl;
	cin >> z;
	return z;
}

bool check( int x ){
	int s(2147483647), y;
	fp( i, 1, 30 ){
		while( (y = rand() % N + 1) == x );
		s &= qry(x, y);
	}
	return !s;
}

int main(){
	srand(time(0));
	cin >> N;
	fp( i, 1, N ) p[i] = i;
	random_shuffle(p + 1, p + N + 1);
	int a(1), b(2), v1(qry(a, b));
	fp( i, 3, N ){
		if ( b == -1 ){
			b = i, v1 = qry(a, b);
			continue;
		}
		int v2(qry(a, i));
		if ( v1 == v2 ) a = b, b = i, v1 = qry(a, b);
		else if ( (v1 & v2) == v2 ) b = i, v1 = v2;
		else if ( (v1 & v2) != v1 ) b = -1;
	}
	if ( !check(a) ) a = b;
	fp( i, 1, N ) ans[p[i]] = i == a ? 0 : qry(a, i);
	cout << "!";
	fp( i, 1, N ) cout << " " << ans[i];
	cout << endl;
	return 0;
}
