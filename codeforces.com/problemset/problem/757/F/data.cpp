#include<bits/stdc++.h>
using namespace std;
#define fp(i, b, e) for ( int i = b, I = e; i <= I; ++i )
#define fd(i, b, e) for ( int i = b, I = e; i >= I; --i )
#define go(i, b) for ( int i = b, v = to[b]; i; v = to[i = nxt[i]] )
#define i64 long long
template<class T> inline bool cmin( T &x, T y ){ return x > y ? x = y, 1 : 0; }
template<class T> inline bool cmax( T &x, T y ){ return x < y ? x = y, 1 : 0; }

int N = 10, M = 15, S = 1, x;
vector<int> e[1005];
int dfn[1005], num;
set<pair<int, int> > st;

void DFS( int u ){
	dfn[u] = ++num;
	for ( int v : e[u] ) DFS(v);
}

int main(){
	freopen("data.in", "w", stdout);
	srand(time(0));
	cout << N << " " << M << " " << S << endl;
	fp( i, 2, N ){
		x = rand() % (i - 1) + 1;
		e[x].push_back(i);
		cout << x << " " << i << " " << rand() % 3 + 1 << endl;
		st.insert(make_pair(x, i));
		st.insert(make_pair(i, x));
	}
	fp( i, N, M ){
		int x, y;
		while( (x = rand() % N + 1) == (y = rand() % N + 1) || st.count(make_pair(x, y)) );
		if ( dfn[x] < dfn[y] ) swap(x, y);
		cout << x << " " << y << " " << rand() % 3 + 1 << endl;
		st.insert(make_pair(x, y));
		st.insert(make_pair(y, x));
	}
	return 0;
}