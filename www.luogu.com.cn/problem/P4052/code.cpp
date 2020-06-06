#include<bits/stdc++.h>
using namespace std;
inline bool cmin( int &x, int y ){ return x > y ? x = y, 1 : 0; }
inline bool cmax( int &x, int y ){ return x < y ? x = y, 1 : 0; }
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[b]); i; v = to[i = nxt[i]] )
#define i64 long long

const int _ = 6055, mod = 1e4 + 7;
int N, M; string s;
int tr[_][26], fail[_], num;
bool ed[_]; queue<int> Q;
int f[105][_];

void Ins( string s ){
	int cur(0), d;
	fp( i, 0, s.size() - 1 ){
		d = s[i] - 'A';
		if ( !tr[cur][d] ) tr[cur][d] = ++num;
		cur = tr[cur][d];
	} ed[cur] = 1;
}

void Build(){
	fp( i, 0, 25 ) if ( tr[0][i] ) Q.push(tr[0][i]);
	while( !Q.empty() ){
		int t(Q.front()); Q.pop();
		fp( i, 0, 25 ){
			if ( tr[t][i] )
				fail[tr[t][i]] = tr[fail[t]][i],
				ed[tr[t][i]] |= ed[tr[fail[t]][i]],
				Q.push(tr[t][i]);
			else tr[t][i] = tr[fail[t]][i];
		}
	}
}

void add( int &x, int y ){
	x += y, x >= mod ? x -= mod : x;
}

int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> M;
	fp( i, 1, N ) cin >> s, Ins(s);
	Build();
	f[0][0] = 1;
	fp( i, 0, M - 1 ) fp( j, 0, num ) fp( k, 0, 25 ) if ( !ed[tr[j][k]] )
		add(f[i + 1][tr[j][k]], f[i][j]);
	int ans(0), sum(1);
	fp( i, 0, num ) add(ans, f[M][i]);
	fp( i, 1, M ) sum = sum * 26 % mod;
	printf( "%d\n", (sum + mod - ans) % mod );
	return 0;
}