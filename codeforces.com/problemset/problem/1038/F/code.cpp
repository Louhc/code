#include<bits/stdc++.h>
using namespace std;
#define fp(i, b, e) for ( int i = b, I = e; i <= I; ++i )
#define fd(i, b, e) for ( int i = b, I = e; i >= I; --i )
#define go(i, b) for ( int i = b, v = to[b]; i; v = to[i = nxt[i]] )
#define i64 long long
inline bool cmin( int &x, int y ){ return x > y ? x = y, 1 : 0; }
inline bool cmax( int &x, int y ){ return x < y ? x = y, 1 : 0; }

const int _ = 105;
int N; string s;
int tr[_][2], fail[_], num;
queue<int> Q;
i64 ans, f[_][_][_];

void Ins( string s ){
	int cur(0), d;
	fp( i, 0, s.size() - 1 ){
		d = s[i] - '0';
		if ( !tr[cur][d] ) tr[cur][d] = ++num;
		cur = tr[cur][d];
	}
}

void Build(){
	if ( tr[0][0] ) Q.push(tr[0][0]);
	if ( tr[0][1] ) Q.push(tr[0][1]);
	while( !Q.empty() ){
		int t(Q.front()); Q.pop();
		if ( tr[t][0] ){
			fail[tr[t][0]] = tr[fail[t]][0];
			Q.push(tr[t][0]);
		} else tr[t][0] = tr[fail[t]][0];
		if ( tr[t][1] ){
			fail[tr[t][1]] = tr[fail[t]][1];
			Q.push(tr[t][1]);
		} else tr[t][1] = tr[fail[t]][1];
	}
}

void DP(){
	ans = 1ll << N;
	fp( i, 0, num - 1 ){
		memset(f, 0, sizeof f);
		f[0][0][i] = 1;
		fp( j, 0, N - 1 ){
			fp( l, 0, num - 1 ){
				fp( k, 0, num - 1 ){
					fp( v, 0, 1 ){
						int a = tr[l][v], b = tr[k][v];
						if ( a == num || b == num ) continue;
						f[j + 1][a][b] += f[j][l][k];
					}
				}
			}
		}
		fp( j, 0, num - 1 ) ans -= f[N][i][j];
	}
}

int main(){
	cin >> N;
	cin >> s;
	Ins(s);
	Build();
	DP();
	printf( "%lld\n", ans );
	return 0;
}