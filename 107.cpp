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
	int N; cin >> N;	
	if (N < 9) {
		cout << 0 << endl;
	} else if (N == 9) {
		cout << 8 << endl;
	} else {
		cout << 72;
		rep(i, 0, N - 10) cout << 0;
		cout << endl;
	}
	return 0;
}
