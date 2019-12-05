#include<bits/stdc++.h>
#define rgt register
using namespace std;
#define MAXN 100005

char s[MAXN], mp[128];
int T, N, Q[MAXN], ft, tl, f[MAXN];
int ch[MAXN][4], len[MAXN], fail[MAXN], tr[MAXN], tot, p, q;

inline int newnode( int x ){ return ++tot, fail[tot] = tr[tot] = 0, f[tot] = len[tot] = x, ch[tot][0] = ch[tot][1] = ch[tot][2] = ch[tot][3] = 0, tot; }
inline int getfail( int x, int n ){ while( s[n] != s[n - len[x] - 1] ) x = fail[x]; return x; }

signed main(){
	scanf( "%d", &T ), mp['A'] = 0, mp['T'] = 1, mp['G'] = 2, mp['C'] = 3;
	while( T-- ){
		scanf( "%s", s + 1 ), s[0] = 88, N = strlen(s + 1), tot = -1;
		newnode(0), newnode(-1), fail[0] = p = 1;
		for ( int i = 1, d, t; i <= N; ++i ){
			d = mp[s[i]], q = getfail(p, i);
			if ( !ch[q][d] ){
				p = newnode(len[q] + 2);
				fail[p] = ch[getfail(fail[q], i)][d];
				ch[q][d] = p;
				if ( len[p] <= 2 ) tr[p] = fail[p];
				else{
					t = tr[q];
					while( len[t] + 2 > ( len[p] >> 1 ) || s[i] != s[i - len[t] - 1] ) t = fail[t];
					tr[p] = ch[t][d];
				}
			} p = ch[q][d];
		} Q[ft = tl = 1] = 0, f[0] = 1;
		int ans(N);
		while( ft <= tl ){
			int c(Q[ft++]), x;
			for ( int i = 0; i < 4; ++i ) if ( ch[c][i] ){
				x = ch[c][i], Q[++tl] = x,
				f[x] = min( f[c] + 1, f[tr[x]] + (len[x] >> 1) - len[tr[x]] + 1 );
				ans = min( ans, f[x] + N - len[x] );
			}
		} printf( "%d\n", ans ); 
	}
	return 0;
}