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

const int MAXN = 16e3 + 7;
pair<int, int> O[MAXN];

int main() {
	int N; cin >> N;	
	rep(i, 0, N) 
		cin >> O[i].first >> O[i].second;
	sort(O, O + N);	
	int answer = 0, MAXB = INT_MIN; 
	for (int i = 0, j; i < N; i = j) {
		j = i + 1;
		while (j < N && O[i].first == O[j].first)
			++j;	
		rep(k, i, j)
			answer += O[k].second < MAXB;
		rep(k, i, j)
			MAXB = max(MAXB, O[k].second);
	}
	cout << answer << endl;
	return 0;
}
