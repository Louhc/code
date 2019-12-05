#include<bits/stdc++.h>
using namespace std;
#define open(s) freopen( s".in", "r", stdin ), freopen( s".out", "w", stdout )
#define MAXN 22000555

int rd[MAXN], n, ans;
char s[MAXN];

void manacher(){
	int mr(0), md(0);
	for ( int i = 1; i < n; ++i ){
		if ( i < mr ) rd[i] = min( rd[(md << 1) - i], rd[md] - i + md );
		else rd[i] = 1;
		while( s[i + rd[i]] == s[i - rd[i]] ) rd[i]++;
		if ( i + rd[i] > mr ) mr = i + rd[i], md = i;
		ans = max( ans, ( ( rd[i] << 1 ) - 1 ) >> 1 );
	}
}

void change(){
	for ( int i = n; i >= 1; --i ) s[i << 1] = s[i], s[(i << 1) - 1] = '*';
	n = ( n << 1 ) + 1; s[n] = '*'; s[0] = '&';
}

int main(){
	scanf( "%s", s + 1 ); n = strlen( s + 1 );
	change(), manacher();
	printf( "%d\n", ans );
	return 0;
}