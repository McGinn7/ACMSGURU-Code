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

bool is_prime(int n) {
	if (n == 1) return false;
	for (int x = 2; x * x <= n; ++x)
		if (n % x == 0) return false;
	return true;
}

int main() {
	int N; cin >> N;
	rep(_, 0, N) {
		int x; cin >> x;
		int P1 = 0, P2;	
		for (int i = 2; i * i <= x; ++i)
			if (x % i == 0) {
				P1 = i;
				break;
			}
		if (P1) {
			P2 = x / P1;
			if (!is_prime(P1) || !is_prime(P2))
				P1 = P2 = 0;
		}		
		if (P1 * P2 == x)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}
