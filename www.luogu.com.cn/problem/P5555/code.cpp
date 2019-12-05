#include<bits/stdc++.h>
using namespace std;
inline bool cmax( int &x, int y ){ return x < y ? x = y, 1 : 0; }
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )

const int MAXN = 540000;
int N, M, p, q, mx, ct;
int ch[MAXN][26], fail[MAXN], len[MAXN], tot(-1);
char s1[MAXN], s2[MAXN]; int v[MAXN];
inline int newnode( int x ){ return len[++tot] = x, tot; }
inline int getfail( char *s, int x, int n ){ while( s[n] != s[n - len[x] - 1] ) x = fail[x]; return x; }
inline void ins( char *s, int n, int t ){
	q = getfail(s, p, n);
	if ( !ch[q][(int)s[n]] ){
		p = newnode(len[q] + 2);
		fail[p] = ch[getfail(s, fail[q], n)][(int)s[n]];
		ch[q][(int)s[n]] = p;
	} v[p = ch[q][(int)s[n]]] |= t;
}

int main(){
	scanf( "%d%d", &N, &M ), scanf( "%s", s1 + 1 ),
	scanf( "%s", s2 + 1 ), s1[0] = s2[0] = 33;
	newnode(0), newnode(-1), fail[0] = p = 1;
	fp( i, 1, N ) s1[i] -= 'a', ins( s1, i, 1 );
	p = 1; fp( i, 1, M ) s2[i] -= 'a', ins( s2, i, 2 );
	fp( i, 0, tot ) if ( v[i] == 3 ) cmax( mx, len[i] );
	fp( i, 0, tot ) if ( v[i] == 3 ) ct += mx == len[i];
	printf( "%d %d\n", mx, ct );
	return 0;
}