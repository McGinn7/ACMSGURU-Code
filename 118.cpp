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

int main() {
	int K; cin >> K;
	rep(_, 0, K) {
		int N; cin >> N;	
		int sum = 0, prod = 1;		
		rep(i, 0, N) {
			int x; cin >> x;
			prod = x % 9 * prod % 9;
			sum += prod;
		}
		sum %= 9;
		if (sum == 0) sum = 9;	
		cout << sum << endl;
	}
	return 0;
}
