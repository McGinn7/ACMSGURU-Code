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

const int MAXN = 1e4 + 7;
int N, dis[MAXN], S[MAXN];
vector<pair<int, int> > e[MAXN];

void dfs(int u, int d, int f) {
	dis[u] = d;
	for (auto p : e[u]) if (p.fi != f)
		dfs(p.fi, d + p.se, u);
}

int furthest(int root) {
	dfs(root, 0, -1);
	pair<int, int> ret(root, 0);
	rep(i, 1, N + 1) 
		ret = max(ret, make_pair(dis[i], i));
	return ret.se;
}

int main() {
	cin >> N;
	rep(u, 2, N + 1) {
		int v, w; cin >> v >> w;
		e[u].emplace_back(make_pair(v, w));
		e[v].emplace_back(make_pair(u, w));
	}

	int du = furthest(1);
	int dv = furthest(du);
	rep(i, 1, N + 1) S[i] = max(S[i], dis[i]);
	furthest(dv);	
	rep(i, 1, N + 1) S[i] = max(S[i], dis[i]);

	rep(i, 1, N + 1) 
		cout << S[i] << endl;
	return 0;
}
