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
	int N, G = 0; cin >> N;
	vector<pair<int, int> > a;
	rep(i, 1, N + 1) {
		int x; cin >> x;
		if (x > 0)
			a.emplace_back(make_pair(x, i));
		G += x;
	}
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());

	G /= 2;
	int sum = 0, start_j = sz(a) - 1;
	rep(i, 0, sz(a)) if (sum + a[i].fi >= G) {	
		a[i].fi -= G - sum;
		a.insert(a.begin() + i, make_pair(G - sum, a[i].se));	
		start_j = i + 1;
		break;
	} else {
		sum += a[i].fi - 1;
	}

	cout << G << endl;	
	for (int i = 0, j = start_j; i < start_j; ++i) {
		while (a[i].fi > 0) {
			if (i + 1 < start_j && a[i].fi == 1) {
				--a[i].fi, --a[i + 1].fi;	
				cout << a[i + 1].se << " " << a[i].se << endl;
			} else {
				while (j < sz(a) && a[j].fi <= 0) ++j;
				--a[i].fi, --a[j].fi;
				cout << a[i].se << " " << a[j].se << endl;
			}
		}
	}
	return 0;
}
