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

const int N = 1e4 + 7;
int minn[N], lastsp[N];
bool isprime[N];
vector<int> primes, superprimes;

void init_primes(int n = N) {
	memset(isprime, true, sizeof(*isprime) * (n + 1));		
	isprime[1] = false;
	rep(i, 2, n + 1) {
		if (isprime[i]) 
			primes.emplace_back(i);
		for (auto p : primes) {
			if (i * p > n) break;
			isprime[i * p] = false;
			if (i % p == 0) break;
		}
	}	
	rep(i, 0, sz(primes)) if (isprime[i + 1]) 
		superprimes.emplace_back(primes[i]);
}

int main() {
	int n; cin >> n;
	init_primes(n);
	memset(minn, -1, sizeof(*minn) * (n + 1));
	minn[0] = 0;
	for (auto sp : superprimes) {
		rep(i, 0, n - sp + 1) if (minn[i] != -1) {
			if (minn[i + sp] == -1 ||
					minn[i + sp] > minn[i] + 1) {
				minn[i + sp] = minn[i] + 1;
				lastsp[i + sp] = sp;
			}
		}
	}
	if (minn[n] == -1) {
		cout << 0 << endl;
	} else {
		vector<int> presentation;
		for (int i = n; i > 0; i -= lastsp[i])
			presentation.emplace_back(lastsp[i]);
		cout << presentation.size() << endl;
		rep(i, 0, sz(presentation)) {
			if (i) cout << " ";
			cout << presentation[i];
		}
		cout << endl;
	}
	return 0;
}
