#include<bits/stdc++.h>
#define u32 unsigned
#define i64 long long
#define u64 unsigned long long
#define f80 long double
#define rgt register
using namespace std;
#define MAXN 300005

char s[MAXN];
int ch[MAXN][26], fail[MAXN], len[MAXN], cnt[MAXN], tot(-1), p, q;
i64 ans;

inline int newnode( int x ){ return len[++tot] = x, tot; }
inline int getfail( int x, int n ){ while( s[n] != s[n - len[x] - 1] ) x = fail[x]; return x; }

signed main(){
	scanf( "%s", s + 1 );
	newnode(0), newnode(-1), fail[0] = p = 1, s[0] = 96;
	for ( int i = 1; s[i] != '\0'; ++i ){
		s[i] -= 'a', q = getfail(p, i);
		if ( !ch[q][s[i]] ){
			p = newnode(len[q] + 2),
			fail[p] = ch[getfail(fail[q], i)][s[i]],
			ch[q][s[i]] = p;
		} ++cnt[p = ch[q][s[i]]];
	} for ( int i = tot; i; --i ) ans = max( ans, 1ll * len[i] * cnt[i] ), cnt[fail[i]] += cnt[i];
	printf( "%lld\n", ans );
	return 0;
}