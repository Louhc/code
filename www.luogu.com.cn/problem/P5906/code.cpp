#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define open(s) freopen( s".in", "r", stdin ), freopen( s".out", "w", stdout )
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline void cmax( T &x, T y ){ x < y ? x = y : x; }
template<typename T> inline void cmin( T &x, T y ){ y < x ? x = y : x; }

const int _ = 2e5 + 55;
int N, M, B, a[_], b[_], n, ans[_];

struct query{
	int l, r, w;
	bool operator < ( const query &t ){
		return b[l] == b[t.l] ? r < t.r : l < t.l;
	}
}q[_];

int L[_], R[_];
inline int calc( int l, int r ){
	int ans(0);
	fp( i, l, r ){
		if ( !R[a[i]] ) L[a[i]] = R[a[i]] = i;
		else R[a[i]] = i, cmax(ans, R[a[i]] - L[a[i]]);
	} fp( i, l, r ) L[a[i]] = 0x7f7f7f7f, R[a[i]] = 0;
	return ans;
}

struct modi{
	int *x, y;
	modi(){}
	modi( int *a ){ x = a, y = *a; }
}stk[_<<1]; int tp;

// ofstream fans("data.ans"), fout("data.out");

int main(){
	// freopen( "data.in", "r", stdin );
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N, B = sqrt(N);
	fp( i, 1, N ) cin >> a[i], b[i] = a[i];
	sort(b + 1, b + N + 1);
	n = unique(b + 1, b + N + 1) - b - 1;
	fp( i, 1, N ) a[i] = lower_bound(b + 1, b + n + 1, a[i]) - b;
	fp( i, 1, N ) b[i] = (i - 1) / B + 1;
	cin >> M, n = 1, memset(L, 0x7f, sizeof L);
	fp( i, 1, M ){
		cin >> q[n].l >> q[n].r, q[n].w = i;
		// fans << calc(q[n].l, q[n].r) << endl;
		if ( b[q[n].r] == b[q[n].l] ) ans[i] = calc(q[n].l, q[n].r); else ++n;
	}
	sort(q + 1, q + n); int cur(0);
	fp( i, 1, n - 1 ){
		if ( b[q[i].l] != b[q[i - 1].l] ){
			memset(L, 0x7f, sizeof L), memset(R, 0, sizeof R), cur = 0;
			fp( j, B * b[q[i].l] + 1, q[i].r ){
				if ( !R[a[j]] ) L[a[j]] = R[a[j]] = j;
				else R[a[j]] = j, cmax(cur, R[a[j]] - L[a[j]]);
			}
		} else{
			fp( j, q[i - 1].r + 1, q[i].r ){
				if ( !R[a[j]] ) L[a[j]] = R[a[j]] = j;
				else R[a[j]] = j, cmax(cur, R[a[j]] - L[a[j]]);
			}
		}
		stk[++tp] = modi(&cur);
		fd( j, B * b[q[i].l], q[i].l ){
			if ( !R[a[j]] ) stk[++tp] = modi(L + a[j]), stk[++tp] = modi(R + a[j]), L[a[j]] = R[a[j]] = j;
			else stk[++tp] = L + a[j], L[a[j]] = j, cmax(cur, R[a[j]] - L[a[j]]);
		} ans[q[i].w] = cur;
		while( tp ) *(stk[tp].x) = stk[tp].y, --tp;
	}
	fp( i, 1, M ) printf( "%d\n", ans[i] );//, fout << ans[i] << endl;
	return 0;
}