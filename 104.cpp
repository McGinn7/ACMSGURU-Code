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
 
const int MAXF = 101;
const int MAXV = 101;
 
int F, V, A[MAXF][MAXV];
int pos[MAXF], dp[MAXF][MAXV], go[MAXF][MAXV];
 
int main() {
	ios::sync_with_stdio(false);
	cin >> F >> V;
	rep(i, 0, F) rep(j, 0, V)
		cin >> A[i][j];
 
	rep(i, 1, V + 1) rep(j, 0, min(i, F) + 1) {
		dp[i][j] = j < i ? dp[i - 1][go[i][j] = j] : INT_MIN; 		
		if (j > 0 && dp[i][j] < dp[i - 1][j - 1] + A[j - 1][i - 1]) 
			dp[i][j] = dp[i - 1][go[i][j] = j - 1] + A[j - 1][i - 1];
	}
 
	for (int i = V, j = F; i > 0; --i) {
		if (go[i][j] != j)
			pos[j - 1] = i;
		j = go[i][j];
	}
	
	cout << dp[V][F] << endl;
	rep(i, 0, F) {
		if (i) cout << ' ';
		cout << pos[i];
	}
	return 0;
}
