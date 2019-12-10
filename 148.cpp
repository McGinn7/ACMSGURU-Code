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

const int MAXN = 15e3 + 7;
int W[MAXN], L[MAXN], P[MAXN];
int sum_w[MAXN];

int main() {	
	int N; cin >> N;	
	rep(i, 1, N + 1) 
		cin >> W[i] >> L[i] >> P[i];	
	rep(i, 1, N + 1)
		sum_w[i] = sum_w[i - 1] + W[i];
	int sum_p = 0;
	pair<int, int> ans(INT_MAX, 0);
	priority_queue<pair<int, int> > pq;
	per(i, 1, N + 1) {
		sum_p += P[i];	
		pq.push(make_pair(sum_w[i] - L[i], i));
		while (!pq.empty() && pq.top().fi > sum_w[i - 1]) {
			sum_p -= P[pq.top().se];	
			pq.pop();
		}
		ans = min(ans, make_pair(sum_p, i));
	}
	rep(i, ans.se, N + 1) {
		if (sum_w[i] - L[i] <= sum_w[ans.se - 1]) {
			cout << i << endl;
		}
	}

	return 0;
}
