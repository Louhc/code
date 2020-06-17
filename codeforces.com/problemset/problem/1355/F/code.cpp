#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline bool cmax( T &x, T y ){ return x < y ? x = y, 1 : 0; }
template<typename T> inline bool cmin( T &x, T y ){ return y < x ? x = y, 1 : 0; }

struct node{
	i64 s; int q, i;
	node( int x = 0, int y = 0, int z = 0 ):s(x), q(y), i(z){}
	bool operator < ( const node &t )const{
		return q == t.q ? s > t.s : q < t.q;
	}
};

int T;
int p[205], n, c[205];
bool vis[1005];
priority_queue<node> Q;
node a[205]; int m;

i64 gcd( i64 x, i64 y = 4194304 ){
	return y ? gcd( y, x % y ) : x;
}

i64 get( i64 x ){
	i64 y;
	cout << "? " << x << endl;
	cin >> y;
	return y;
}

signed main(){
	cin >> T;
	fp( i, 2, 1000 ) if ( !vis[i] ){
		p[++n] = i; for ( int j = i + i; j <= 1000; j += i ) vis[j] = 1;
	}
	while( T-- ){
		while( Q.size() ) Q.pop();
		fp( i, 1, n ) Q.push(node(p[i], 1, i));
		memset( c, 0, sizeof c );
		fp( i, 1, 22 ){
			i64 x(1), y; m = 0;
			while( !Q.empty() && 1. * x * Q.top().s <= 1e18 )
				a[++m] = Q.top(), Q.pop(), x *= a[m].s;
			y = get(x);
			fp( j, 1, m ){
				int t(p[a[j].i]), s(0);
				while( y % t == 0 ) y /= t, ++s;
				if ( s > c[i] ) c[a[j].i] = s, a[j].s *= t, ++a[j].q, Q.push(a[j]);
			}
		}
		i64 ans(2);
		fp( i, 1, n ) ans *= 1 + c[i];
		cout << "! " << ans << endl;
	}
	return 0;
}
