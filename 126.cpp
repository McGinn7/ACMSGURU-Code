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
	int A, B;
	cin >> A >> B;
	int moves;
	for (moves = 0; moves < 32 && min(A, B) > 0; ++moves) {
		if (A > B) swap(A, B);
		B -= A;
		A += A;
	}
	if (min(A, B) > 0) {
		cout << -1 << endl;
	} else {
		cout << moves << endl;
	}
	return 0;
}
