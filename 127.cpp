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
	int N; cin >> N;
	vector<int> count(10, 0);
	string str;
	rep(_, 0, N) {
		cin >> str;
		++count[str[0] - '0'];
	}
	int P = 2;	
	for (auto c : count) if (c) 	
		P += (c - 1) / K + 1;
	cout << P << endl;
	return 0;
}
