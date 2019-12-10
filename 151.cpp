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
	double c, b, m;
	cin >> c >> b >> m;
	long long C = round(1e2 * c);
	long long B = round(1e2 * b);
	long long M = round(1e2 * m);
	if (abs(4 * M * M - B * B - C * C) <= 2 * B * C) {
		double x = (4 * m * m - b * b - c * c) / (2 * c);
		double y = sqrt(b * b - x * x);
		cout << fixed << setprecision(5);
		cout << 0. << " " << 0. << endl;
		cout << c << " " << 0. << endl;
		cout << x << " " << y << endl;
	} else {
		cout << "Mission impossible" << endl;
	}
	return 0;
}
