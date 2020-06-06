#include<bits/stdc++.h>
using namespace std;
inline bool cmin( int &x, int y ){ return x > y ? x = y, 1 : 0; }
inline bool cmax( int &x, int y ){ return x < y ? x = y, 1 : 0; }
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[b]); i; v = to[i = nxt[i]] )
#define i64 long long

const int _ = 1e5 + 55;
int T, N, M;
string s, str[_];
int tr[_*30][26], cnt[_*30], fail[_*30], num;
int o[_], w[_], ans[_];
queue<int> Q;

int Ins( string s ){
	int cur(0), d;
	fp( i, 0, s.size() - 1 ){
		d = s[i] - 'a';
		if ( !tr[cur][d] ) tr[cur][d] = ++num;
		cur = tr[cur][d];
	} return cur;
}

void Build(){
	fp( i, 0, 25 ) if ( tr[0][i] ) Q.push(tr[0][i]);
	while( !Q.empty() ){
		int t(Q.front()); Q.pop();
		fp( i, 0, 25 ){
			if ( tr[t][i] ){
				Q.push(tr[t][i]);
				fail[tr[t][i]] = tr[fail[t]][i];
			} else tr[t][i] = tr[fail[t]][i];
		}
	}
}

int query( string s ){
	int cur(0), d, t, ans(0);
	fp( i, 0, s.size() - 1 ){
		d = s[i] - 'a'; cur = tr[cur][d];
		for ( t = cur; t; t = fail[t] ) ans += cnt[t];
	} return ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin >> T;
	while( T-- ){
		memset(tr, 0, (num + 1) * 78 * 4);
		memset(cnt, 0, (num + 1) * 3 * 4);
		memset(fail, 0, (num + 1) * 3 * 4);
		num = 0;
		cin >> N >> M;
		fp( i, 1, N ) cin >> s, ++cnt[Ins(s)];
		fp( i, 1, M ){
			cin >> o[i] >> str[i];
			if ( o[i] == 1 ) ++cnt[w[i] = Ins(str[i])];
		}
		Build();
		fd( i, M, 1 ){
			if ( o[i] == 2 ) ans[i] = query(str[i]);
			else --cnt[w[i]];
		}
		fp( i, 1, M ) if ( o[i] == 2 ) printf( "%d\n", ans[i] );
	}
	return 0;
}