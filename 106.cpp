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

ll exgcd(ll a, ll b, ll &x, ll &y) {
	if (!b) {
		x = 1, y = 0;
		return a;
	} else {
		ll g = exgcd(b, a % b, y, x);
		y -= a / b * x;
		return g;
	}
}

pair<ll, ll> get(ll x0, ll delta, ll x1, ll x2) {
	x1 -= x0, x2 -= x0;
	if (delta < 0) {
		swap(x1, x2);
		x1 *= -1, x2 *= -1, delta *= -1;
	}
	double low = 1.0 * x1 / delta;
	double high = 1.0 * x2 / delta;
	return make_pair(ceil(low), floor(high));
}

int main() {
	ll a, b, c, x1, x2, y1, y2;
	cin >> a >> b >> c >> x1 >> x2 >> y1 >> y2;
	ll x0, y0, gcd;
	c = -c;
	gcd = exgcd(a, b, x0, y0);
	if (gcd == 0) {
		if (c == 0) 
			cout << (x2 - x1 + 1) * (y2 - y1 + 1) << endl;
		else 
			cout << 0 << endl;	
	} else if (c % gcd != 0) {
		cout << 0 << endl;
	} else {
		x0 *= c / gcd;	
		y0 *= c / gcd;
		// ax + by = c
		// x = x0 + b / gcd * k
		// y = y0 - a / gcd * k
		ll answer = 0;
		if (a == 0) {
			if (y1 <= y0 && y0 <= y2)
				answer = x2 - x1 + 1;
		} else if (b == 0) {
			if (x1 <= x0 && x0 <= x2)
				answer = y2 - y1 + 1;
		} else {
			pair<ll, ll> xk = get(x0, b / gcd, x1, x2);	
			pair<ll, ll> yk = get(y0, -a / gcd, y1, y2);
			ll low = max(xk.first, yk.first);
			ll high = min(xk.second, yk.second);
			answer = max(0ll, high - low + 1);	
		}
		cout << answer << endl;
	}
	return 0;
}
