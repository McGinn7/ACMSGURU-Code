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
	int N, A0, B0;
	cin >> N >> A0 >> B0;
	int g = __gcd(A0, B0);
	int d = __gcd(g, N);
	int A = A0 / g * d;	
	int B = B0 / g * d;
	vector<pair<int, int> > ans;		
	rep(i, 0, N)
		ans.emplace_back(make_pair(i * A % N, i * B % N));
	sort(ans.begin(), ans.end());
	ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
	cout << ans.size() << endl;
	for (auto ab : ans)
		cout << ab.first << " " << ab.second << endl;
	return 0;
}
