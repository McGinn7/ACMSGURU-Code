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

const int MAXK = 31;
long long dp[MAXK];

int main() {
	int k; cin >> k;
	dp[0] = 1;
	rep(i, 1, k + 1) {
		rep(j, 0, i) {
			dp[i] += dp[j] * dp[i - 1 - j];
		}
	}
	cout << dp[k] << " " << k + 1 << endl;
	return 0;
}
