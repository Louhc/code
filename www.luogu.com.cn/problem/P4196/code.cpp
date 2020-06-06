#include<bits/stdc++.h>
using namespace std;
#define fp(i, b, e) for ( int i = b, I = e; i <= I; ++i )
#define fd(i, b, e) for ( int i = b, I = e; i >= I; --i )
#define go(i, b) for ( int i = b, v = to[b]; i; v = to[i = nxt[i]] )
#define i64 long long
inline bool cmin( int &x, int y ){ return x > y ? x = y, 1 : 0; }
inline bool cmax( int &x, int y ){ return x < y ? x = y, 1 : 0; }

const double eps = 1e-5;
inline int dcmp( double x ){ return fabs(x) > eps ? x < 0 ? -1 : 1 : 0; }
struct vect{
	double x, y; vect( double a = 0, double b = 0 ):x(a), y(b){}
	vect operator + ( const vect &t ){ return vect(x + t.x, y + t.y); }
	vect operator - ( const vect &t ){ return vect(x - t.x, y - t.y); }
	double operator * ( const vect &t )const{ return x * t.y - y * t.x; }
};
vect operator * ( double a, vect b ){ return vect(b.x * a, b.y * a); }
struct line{
	vect s, t, l; double p; line(){}
	line( vect x, vect y ):s(x), t(y), l(y - x), p(atan2(l.y, l.x)){}
	bool operator < ( const line &x )const{ return p < x.p; }
};

inline vect intersection( line l1, line l2 ){
	vect a(l1.s - l2.s), b(l1.t - l1.s), c(l2.t - l2.s);
	return l1.s + (a * c) / (c * b) * b;
}
inline bool check( line l1, line l2, line l3 ){
	return dcmp((intersection(l1, l2) - l3.s) * l3.l) > 0;
}

int N, M, n, m;
vect p[55], b[555];
line l[555];
int q[555], hd(1), tl(0);

int main(){
	cin >> N;
	fp( i, 1, N ){
		cin >> M;
		fp( j, 1, M ) cin >> p[j].x >> p[j].y;
		p[0] = p[M];
		fp( j, 1, M ) l[++n] = line(p[j - 1], p[j]);
	}
	sort(l + 1, l + n + 1);
	fp( i, 1, n ){
		if ( !dcmp(l[i].p - l[m].p) ){
			if ( dcmp(l[m].l * (l[i].s - l[m].s)) > 0 ) l[m] = l[i];
		} else l[++m] = l[i];
	}
	q[++tl] = 1, q[++tl] = 2;
	fp( i, 3, m ){
		while( hd < tl && check(l[q[tl - 1]], l[q[tl]], l[i]) ) --tl;
		while( hd < tl && check(l[q[hd + 1]], l[q[hd]], l[i]) ) ++hd;
		q[++tl] = i;
	}
	while( hd < tl && check(l[q[tl - 1]], l[q[tl]], l[q[hd]]) ) --tl;
	while( hd < tl && check(l[q[hd + 1]], l[q[hd]], l[q[tl]]) ) ++hd;
	q[tl + 1]  = q[hd]; n = 0;
	fp( i, hd, tl ) b[++n] = intersection( l[q[i + 1]], l[q[i]] );
	b[n + 1] = b[1];
	double ans(0);
	fp( i, 1, n ) ans += b[i] * b[i + 1];
	printf( "%.3lf\n", fabs(ans) / 2 );
	return 0;
}