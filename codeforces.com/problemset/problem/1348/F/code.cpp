#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline bool cmax( T &x, T y ){ return x < y ? x = y, 1 : 0; }
template<typename T> inline bool cmin( T &x, T y ){ return y < x ? x = y, 1 : 0; }

const int _ = 2e5 + 55;
int N, l[_], r[_], a[_], b[_];
vector<pair<int, int> > v[_];
priority_queue<pair<int, int> > Q;
int s[_], tp;

void print(){
	fp( i, 1, N ) b[a[i]] = i;
	fp( i, 1, N ) printf( "%d%c", b[i], "\n "[i < N] );
}

int main(){
	scanf( "%d", &N );
	fp( i, 1, N ) scanf( "%d%d", l + i, r + i ), v[l[i]].push_back(make_pair(-r[i], i));
	fp( i, 1, N ){
		for ( auto j : v[i] ) Q.push(j);
		a[i] = Q.top().second; Q.pop();
	}
	s[tp = 1] = 1;
	fp( i, 2, N ){
		while( tp && r[a[s[tp]]] < i ) --tp;
		if ( tp && s[tp] >= l[a[i]]){
			printf("NO\n"), print(), swap(a[s[tp]], a[i]), print();
			return 0;
		}
		while( tp && r[a[s[tp]]] <= r[a[i]] ) --tp;
		s[++tp] = i;
	}
	printf("YES\n");
	print();
	return 0;
}
