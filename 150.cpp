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

struct P {
	int x, y;
	P() {}
	P(int _x, int _y) {
		x = _x, y = _y;
	}
	P operator-(const P &p) const {
		return P(x - p.x, y - p.y);
	}
	long long operator/(const P &p) const {
		return 1ll * x * p.y - 1ll * y * p.x;	
	}
};

inline int sgn(const int &x) {
	return x == 0 ? 0 : (x < 0 ? -1 : 1);
}

int get_d(int x1, int x2) {
	return x1 == x2 ? 0 : (x2 - x1) / abs(x2 - x1);
}

bool sgm_intr(const P &a, const P &b, 
		const P &s, const P &t) {
	return sgn((b - a) / (s - a))
		* sgn((b - a) / (t - a)) < 0 
		&& sgn((t - s) / (a - s))
		* sgn((t - s) / (b - s)) < 0;
}

tuple<P, P, P, P> corner(const P &cntr) {
	return make_tuple(
			P(cntr.x - 1, cntr.y - 1), 
			P(cntr.x - 1, cntr.y + 1), 
			P(cntr.x + 1, cntr.y + 1), 
			P(cntr.x + 1, cntr.y - 1));
}

bool cell_intr(const P &s, const P &t, const P &cntr) {
	if (cntr.x < min(s.x, t.x) || cntr.x > max(s.x, t.x))
		return false;
	if (cntr.y < min(s.y, t.y) || cntr.y > max(s.y, t.y))
		return false;
	P a, b, c, d;
	tie(a, b, c, d) = corner(cntr);	
	return sgm_intr(s, t, a, c) || sgm_intr(s, t, b, d);	
}

int main() {
	int x1, y1, x2, y2, n;
	cin >> x1 >> y1 >> x2 >> y2 >> n;	

	int dx = get_d(x1, x2);	
	int dy = get_d(y1, y2);

	P A(2 * x1, 2 * y1), B(2 * x2, 2 * y2); 
	P nth_cell(INT_MAX, INT_MAX);
	if (cell_intr(A, B, P(2 * x1 + dx, 2 * y1 + dy))) {
		P cntr(2 * x1 - dx, 2 * y1 - dy);
		dx *= 2, dy *= 2;
		while (n-- > 0) {
			bool flag = false;
			rep(i, 1, 4) {
				P _cntr(cntr.x + (i & 1) * dx,
						cntr.y + (i >> 1) * dy);
				if (cell_intr(A, B, _cntr))	{
					cntr = _cntr;
					flag = true;
					break;
				}
			}
			if (!flag) break;
		}
		if (n == -1) nth_cell = cntr;
	}
	if (nth_cell.x < INT_MAX) {
		cout << (nth_cell.x - 1) / 2 << " " << (nth_cell.y - 1) / 2 << endl;
	} else
		cout << "no solution" << endl;

	return 0;
}
