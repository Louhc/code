#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline bool cmax( T &x, T y ){ return x < y ? x = y, 1 : 0; }
template<typename T> inline bool cmin( T &x, T y ){ return y < x ? x = y, 1 : 0; }

const int _ = 105;
int N, ox, oy, ax, ay, bx, by, cx, cy, tmp;
int s[_], dx[_], dy[_];

void ask( int t, int &x, int &y ){
	int tx, ty;
	cout << "+ " << t << endl;
	cin >> tx >> ty;
	x = tx - ox, y = ty - oy;
	ox = tx, oy = ty;
}

int main(){
	cin >> N >> ox >> oy;
	fd( i, N - 1, 3 ) ask(i, dx[i], dy[i]);
	ask(1, ax, ay);
	ask(2, bx, by);
	ask(1, cx, cy);
	s[1] = cx - ax;
	s[3] = cy - ay - 1;
	s[2] = ay / (s[3] + 1);
	s[4] = by / (s[3] + 1) - s[1] - 2;
	fp( i, 5, N )
		s[i] = (dy[i - 2] - s[i - 4] * s[i - 3] - s[i - 3] * (s[i - 1] + 1)) / (s[i - 1] + 1) - 1;
	++s[N]; cout << "!";
	fp( i, 1, N ) cout << " " << s[i];
	cout << endl;
	return 0;
}
