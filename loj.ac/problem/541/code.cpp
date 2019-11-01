#include<bits/stdc++.h>
using namespace std;
#define u32 unsigned
#define u64 unsigned long long
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )

const int mod = 998244353, MAXN = 1e6 + 5;
int T, m, a, b, c, d, opt; u32 seed, res;
unsigned int randnum(){ return seed ^= seed << 13, seed ^= seed >> 17, seed ^= seed << 5; }
inline void update_ans( u32 &ans_sum, u32 cur_ans, int no ){ ans_sum ^= (u64)no * (no + 7) % mod * cur_ans % mod; }
int q1[MAXN], h1, t1, q2[MAXN], h2, t2; char v[MAXN<<1], in[MAXN<<1]; int p;

signed main(){
	scanf( "%d", &T );
	while( T-- ){
		scanf( "%d%u%d%d%d%d", &m, &seed, &a, &b, &c, &d );
		res = 0; fp( i, 0, a ) v[i] = in[i] = 1;
		h1 = h2 = 1, t1 = t2 = 0, p = 0; while( v[p] ) ++p;
		fp( i, 1, m ){
			if ( randnum() % c == 0 ) opt = -1;
			else opt = randnum() % b;
			if ( opt != -1 && in[opt] ){
				if ( d ) continue;
				in[opt] = 0; q1[++t1] = opt;
				while( h2 <= t2 && q2[t2] > opt ) --t2;
				q2[++t2] = opt;
			}else if ( opt != -1 && !v[opt] ){
				v[opt] = in[opt] = 1; while( v[p] ) ++p;
			}else{
				if ( d || h1 > t1 ) continue;
				if ( h2 <= t2 && q2[h2] == q1[h1] ) ++h2;
				in[q1[h1++]] = 1;
			} update_ans(res, h2 <= t2 ? min( q2[h2], p ) : p, i);
		} printf( "%u\n", res );
		memset( v, 0, b ), memset( in, 0, b );
	}
	return 0;
}


