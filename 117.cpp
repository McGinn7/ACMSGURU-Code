#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) begin(x),end(x)
#define rep(i,l,r) for(int i=(l);i<(r);++i)
#define per(i,l,r) for(int i=(r)-1;i>=(l);--i)
#define dd(x) cout << #x << "=" << x << ", "
#define de(x) cout << #x << "=" << x << endl
//-------

int fast_power(int a, int b, int mod) {
	int ret = 1;
	while (b > 0) {
		if (b & 1) 
			ret = ret * a % mod;
		a = a * a % mod;
		b = b >> 1;
	}
	return ret;
}

int main() {
	int N, M, K;
	cin >> N >> M >> K;
	int count = 0;
	rep(_, 0, N) {
		int x; cin >> x;
		count += fast_power(x, M, K) == 0;
	}
	cout << count << endl;
	return 0;
}
