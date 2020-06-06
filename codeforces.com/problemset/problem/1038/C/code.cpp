#include<bits/stdc++.h>
using namespace std;
inline bool cmin( int &x, int y ){ return x > y ? x = y, 1 : 0; }
inline bool cmax( int &x, int y ){ return x < y ? x = y, 1 : 0; }
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[b]); i; v = to[i = nxt[i]] )
#define i64 long long

const int _ = 1e5 + 55;
int N, x; i64 ans(0);
priority_queue<int> A, B;

int main(){
	scanf( "%d", &N );
	fp( i, 1, N ) scanf( "%d", &x ), A.push(x);
	fp( i, 1, N ) scanf( "%d", &x ), B.push(x);
	fp( i, 1, N ){
		if ( !A.size() ) B.pop();
		else if ( !B.size() ) ans += A.top(), A.pop();
		else if ( A.top() > B.top() ) ans += A.top(), A.pop();
		else B.pop();
		if ( !A.size() ) ans -= B.top(), B.pop();
		else if ( !B.size() ) A.pop();
		else if ( A.top() > B.top() ) A.pop();
		else ans -= B.top(), B.pop();
	} printf( "%lld\n", ans );
	return 0;
}