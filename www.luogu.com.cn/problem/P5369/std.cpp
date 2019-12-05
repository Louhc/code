#include <bits/stdc++.h>
#define LL long long
using namespace std;
inline LL read(){
    LL x = 0,f = 1; char c = getchar();
    while (c != EOF && !isdigit(c)) {if (c == '-') f = -1;c = getchar();}
    while (isdigit(c)) {x = x * 10 + c - '0';c = getchar();}
    return x * f;
}
inline void write(LL x){
    if (x < 0) putchar('-'),x = -x;
    if (x > 9) write(x/10); putchar(x%10+'0');
}
inline void writeln(LL x){ write(x),putchar('\n'); }
const int P = 998244353,N = 20 + 5,L = 1<<20;
inline int add(int x,int y){ return (x+=y)>=P?x-P:x; }
inline int mul(LL x,int y){ return x*y-x*y/P*P; }
int n,l,f[L],g[L],ans; LL sum[L];
int main(){
    int i,j;
    n = read(),l = 1<<n;
    for (i = 0; i < n; ++i) sum[1<<i] = read(),f[1<<i] = 1;
    for (i = 1; i < l; ++i) sum[i] = sum[i^(i&-i)] + sum[i&-i];
    for (g[0] = i = 1; i < l; ++i){
		if (sum[i] >= 0)
        { for (j = 0; j < n; ++j) if (!(i>>j&1)) f[i|(1<<j)] = add(f[i|(1<<j)],f[i]); }
        else{ for (j = 0; j < n; ++j) if (i>>j&1) g[i] = add(g[i],g[i^(1<<j)]); }
    	printf( "%d %d %d %lld\n", i, f[i], g[i], sum[i] );
	}
    for (i = 1; i < l; ++i) ans = add(ans,mul(mul(sum[i]%P,f[i]),g[(l-1)^i])),ans = (ans % P + P) % P;
    writeln(ans);
    return 0;
}
