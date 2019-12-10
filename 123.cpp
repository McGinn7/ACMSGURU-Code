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
	long long F0 = 0, F1 = 1, S = 1;
	rep(i, 1, K) {
		swap(F0, F1);
		F1 += F0;
		S += F1;
	}
	cout << S << endl;
	return 0;
}
