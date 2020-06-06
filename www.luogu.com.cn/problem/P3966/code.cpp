#include<bits/stdc++.h>
using namespace std;
#define fp(i, b, e) for ( int i = b, I = e; i <= I; ++i )
#define fd(i, b, e) for ( int i = b, I = e; i >= I; --i )
#define go(i, b) for ( int i = b, v = to[b]; i; v = to[i = nxt[i]] )
#define i64 long long
inline bool cmin( int &x, int y ){ return x > y ? x = y, 1 : 0; }
inline bool cmax( int &x, int y ){ return x < y ? x = y, 1 : 0; }

const int _ = 1e6 + 55;
int N; string s[205];
int tr[_][26], num, fail[_], id[205], cnt[_];
vector<int> e[_];
queue<int> Q;

void Ins( int k, string s ){
	int cur(0), d;
	fp( i, 0, s.size() - 1 ){
		d = s[i] - 'a';
		if ( !tr[cur][d] ) tr[cur][d] = ++num;
		cur = tr[cur][d];
	} id[k] = cur;
}

void Build(){
	fp( i, 0, 25 ) if ( tr[0][i] ) Q.push(tr[0][i]);
	while( !Q.empty() ){
		int t(Q.front()); Q.pop();
		fp( i, 0, 25 ){
			if ( tr[t][i] ){
				fail[tr[t][i]] = tr[fail[t]][i];
				Q.push(tr[t][i]);
			} else tr[t][i] = tr[fail[t]][i];
		}
	}
}

void DFS( int u, int fa ){
	for ( int v : e[u] ) if ( v != fa ){
		DFS(v, u);
		cnt[u] += cnt[v];
	}
}

int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	fp( i, 1, N ) cin >> s[i], Ins(i, s[i]);
	Build();
	fp( i, 1, N ){
		int cur(0);
		fp( j, 0, s[i].size() - 1 )
			cur = tr[cur][(int)(s[i][j] - 'a')], ++cnt[cur];
	}
	fp( i, 1, num ) e[fail[i]].push_back(i), e[i].push_back(fail[i]);
	DFS(0, 0);
	fp( i, 1, N ) printf( "%d\n", cnt[id[i]] );
	return 0;
}