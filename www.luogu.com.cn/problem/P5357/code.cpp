#include<bits/stdc++.h>
using namespace std;
#define fp(i, b, e) for ( int i = b, I = e; i <= I; ++i )
#define fd(i, b, e) for ( int i = b, I = e; i >= I; --i )
#define go(i, b) for ( int i = b, v = to[b]; i; v = to[i = nxt[i]] )
#define i64 long long
inline bool cmin( int &x, int y ){ return x > y ? x = y, 1 : 0; }
inline bool cmax( int &x, int y ){ return x < y ? x = y, 1 : 0; }

const int _ = 2e5 + 55;

int N; string s;
int tr[_][26], num(0), fail[_];
queue<int> Q; int id[_], cnt[_];
int hd[_], nxt[_<<1], to[_<<1], tot(1);

void Ins( int c, string s ){
	int cur(0), d;
	fp( i, 0, s.size() - 1 ){
		d = s[i] - 'a';
		if ( !tr[cur][d] ) tr[cur][d] = ++num;
		cur = tr[cur][d];
	} id[c] = cur;
}

void Build(){
	fp( i, 0, 25 ) if ( tr[0][i] ) Q.push(tr[0][i]);
	while( !Q.empty() ){
		int t(Q.front()); Q.pop();
		fp( i, 0, 25 ){
			if ( tr[t][i] ) fail[tr[t][i]] = tr[fail[t]][i], Q.push(tr[t][i]);
			else tr[t][i] = tr[fail[t]][i];
		}
	}
}

inline void addedge( int x, int y ){
	nxt[++tot] = hd[x], hd[x] = tot, to[tot] = y;
}

void DFS( int u, int fa ){
	go( i, hd[u] ) if ( v != fa ){
		DFS(v, u);
		cnt[u] += cnt[v];
	}
}

int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	fp( i, 1, N ) cin >> s, Ins(i, s);
	Build();
	cin >> s; int cur(0);
	fp( i, 0, s.size() - 1 ) cur = tr[cur][(int)(s[i] - 'a')], ++cnt[cur];
	fp( i, 1, num ) addedge(fail[i], i), addedge(i, fail[i]);
	DFS(0, 0);
	fp( i, 1, N ) printf( "%d\n", cnt[id[i]] );
	return 0;
}