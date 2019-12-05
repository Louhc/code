#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define u64 unsigned long long 

u64 N, K;

void work( u64 n, u64 k ){
	if ( n == 1 ){
		cout << k;
		return;
	}
	if ( k < (1ull << (n - 1)) ) cout << 0, work(n - 1, k);
	else cout << 1, work(n - 1, (1ull << (n - 1)) - 1 + (1ull << (n - 1)) - k );
}

signed main(){
	cin >> N >> K;
	work(N, K);
	cout << endl;
	return 0;
}


