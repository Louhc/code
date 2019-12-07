#pragma GCC optimize("Ofast")

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

typedef long long LL;
const int _ = 2500050;
const int mod = 998244353;

inline LL pow_mod(LL a, LL b){ LL ans = 1; for ( ; b; b >>= 1, a = a * a % mod) if (b & 1) ans = ans * a % mod; return ans; }
inline LL dec( LL x ){ return x >= mod ? x - mod : x; }

int L, rev[_];
LL w[_], inv[_], fac[_];

void Init(int n) {
  L = 1;
  while (L <= n) L <<= 1;
  for (int i = 1; i < L; ++i)
    rev[i] = (rev[i >> 1] >> 1) | ((i & 1) * L / 2);
  LL wn = pow_mod(3, (mod - 1) / L);
  w[L >> 1] = 1;
  for (int i = L >> 1; i < L; ++i) w[i + 1] = w[i] * wn % mod;
  for (int i = (L >> 1) - 1; i; --i) w[i] = w[i << 1];
}

void DFT(LL *A, int len) {
  int k = __builtin_ctz(L) - __builtin_ctz(len);
  for (int i = 1; i < len; ++i) {
    int j = rev[i] >> k;
    if (j > i) std::swap(A[i], A[j]);
  }
  for (int h = 1; h < len; h <<= 1)
    for (int i = 0; i < len; i += (h << 1))
      for (int j = 0; j < h; ++j) {
        LL t = A[i + j + h] * w[j + h] % mod;
        (A[i + j + h] = A[i + j] - t)%=mod;
        (A[i + j] += t)%=mod;
      }
  for (int i = 0; i < len; ++i) A[i] %= mod;
}

void IDFT(LL *A, int len) {
  std::reverse(A + 1, A + len);
  DFT(A, len);
  int v = mod - (mod - 1) / len;
  for (int i = 0; i < len; ++i) A[i] = A[i] * v % mod;
}

void offset(const LL *f, int n, LL c, LL *g) {
  static LL tA[_], tB[_];
  int l = 1; while (l <= n + n) l <<= 1;
  for (int i = 0; i < n; ++i) tA[n - i - 1] = f[i] * fac[i] % mod;
  LL pc = 1;
  for (int i = 0; i < n; ++i, pc = pc * c % mod) tB[i] = pc * inv[i] % mod;
  for (int i = n; i < l; ++i) tA[i] = tB[i] = 0;
  DFT(tA, l); DFT(tB, l);
  for (int i = 0; i < l; ++i) tA[i] = tA[i] * tB[i] % mod;
  IDFT(tA, l);
  for (int i = 0; i < n; ++i)
    g[i] = tA[n - i - 1] * inv[i] % mod;
}

void Solve(int n, LL *f) {
  if (n == 0) return void(f[0] = 1);
  static LL tA[_], tB[_];
  int m = n / 2;
  Solve(m, f);
  int l = 1; while (l <= n) l <<= 1;
  offset(f, m + 1, m, tA);
  for (int i = 0; i <= m; ++i) tB[i] = f[i];
  for (int i = m + 1; i < l; ++i) tA[i] = tB[i] = 0;
  DFT(tA, l); DFT(tB, l);
  for (int i = 0; i < l; ++i) tA[i] = tA[i] * tB[i] % mod;
  IDFT(tA, l);
  if (n & 1)
    for (int i = 0; i <= n; ++i)
      f[i] = ((i ? tA[i - 1] : 0) + (n - 1) * tA[i]) % mod;
  else
    for (int i = 0; i <= n; ++i)
      f[i] = tA[i];
}

LL f[_], T, p, r, N;

inline LL sum( LL x ){ return x > 1 ? dec(pow_mod(x, N + 1) + mod - 1) * pow_mod(dec(x + mod - 1), mod - 2) % mod : ( x > 0 ? N + 1 : 0 ); }

int main() {
	fac[0] = 1;
	for ( int i = 1; i <= 1e6; ++i ) fac[i] = fac[i - 1] * i % mod;
	inv[1000000] = pow_mod(fac[1000000], mod - 2);
	for ( int i = 1e6; i; --i ) inv[i - 1] = inv[i] * i % mod;
	
	cin >> T;
	while( T-- ){
		cin >> N >> p >> r;
		Init(2 * r), Solve(r, f);
		LL ans(0), t(1);
		fp( i, 0, r ){
			ans = (ans + (((r - i) & 1) ? mod - f[i] : f[i]) * sum(t)) % mod;
			t = t * p % mod;
		} printf( "%lld\n", (ans * inv[r] % mod + mod) % mod );
	}
	return 0;
}
