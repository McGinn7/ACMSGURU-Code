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
 
int phi(int n) {
	int ret = n;
	for (int x = 2; x * x <= n; ++x) {
		if (n % x) continue;
		ret -= ret / x;	
		while (n % x == 0) n /= x;
	}
	if (n > 1) ret -= ret / n;
	return ret;
}
 
int main() {
	int n; scanf("%d", &n);
	printf("%d", phi(n));
	return 0;
}
