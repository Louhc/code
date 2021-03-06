#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define f80 long double
#define rgt register
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline bool cmax( T &x, T y ){ return x < y ? x = y, 1 : 0; }
template<typename T> inline bool cmin( T &x, T y ){ return y < x ? x = y, 1 : 0; }
#define getchar() ( p1 == p2 && ( p1 = bf, p2 = bf + fread( bf, 1, 1 << 21, stdin ), p1 == p2 ) ? EOF : *p1++ )
char bf[1 << 21], *p1(bf), *p2(bf);
template<typename T>
inline void read( T &x ){ char t(getchar()), flg(0); x = 0;
	for ( ; !isdigit(t); t = getchar() ) flg = t == '-';
	for ( ; isdigit(t); t = getchar() ) x = x * 10 + ( t & 15 );
	flg ? x = -x : x;
}


int N = 200, M = 300;
set<pair<int, int> > S;

struct edge{
	int x, y;
	bool operator < ( const edge &t )const{ return y == t.y ? x < t.x : y < t.y; }
	edge( int a = 0, int b = 0 ){
		x = a, y = b;
		if ( x > y ) swap(x, y);
	}
};

struct random_t {
	unsigned state;
	random_t() : state(0) { }
	random_t( unsigned seed ) : state(seed) { }
	unsigned next() {
		state ^= state << 13;
		state ^= state >> 17;
		state ^= state << 5;
		return state;
	}
	void permute(int* permutation, int n) {
		for (int k = 1; k <= n; k++) {
			permutation[k] = k;
			int p = next() % k + 1;
			int tmp = permutation[p];
			permutation[p] = k;
			permutation[k] = tmp;
		}
	}
	void sh( edge *a, int n ){
		for ( int i = 1; i <= n; ++i ){
			int t(next() % i + 1);
			swap(a[t], a[i]);
		}
	}
}rnd;

struct G{
	int n;
	edge e[10000];
	set<edge> S;
	bool ins( int x, int y ){
		if ( S.count(edge(x, y)) ) return 0;
		if ( x == y ) return 0;
		e[++n] = edge(x, y);
		S.insert(edge(x, y));
		return 1;
	}
	void rs( int l, int r ){ rnd.sh(e + l - 1, r - l + 1); }
	void print(){
		fp( i, 1, n ){
			printf( "%d %d\n", e[i].x, e[i].y );
		}
	}
}g1, g2;

int Get(){
	int x;
	ifstream fin("seed.txt");
	fin >> x;
	return x;
}
void Put( int x ){
	ofstream fout("seed.txt");
	fout << x;
}

signed main(){
//	freopen( "input.txt", "w", stdout );
	int seed; rnd = random_t(seed = Get()), Put(seed + 1);
	
	printf( "%d %d\n", N, M );
	fp( i, 2, N ) g1.ins(rnd.next() % (i - 1) + 1, i);
	fp( i, 2, N ) g2.ins(rnd.next() % (i - 1) + 1, i);
	fp( i, N, M ) while( !g1.ins(rnd.next() % N + 1, rnd.next() % N + 1) );
	fp( i, N, M ) while( !g2.ins(rnd.next() % N + 1, rnd.next() % N + 1) );
	
	g1.rs(1, M);
	
	g1.print();
	printf("\n");
	g2.print();
	
	cerr << seed;
	
	return 0;
}


