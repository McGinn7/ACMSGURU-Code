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

#define sqr(x) ((x)*(x))

int main() {
	double X, Y, Z;
	cin >> X >> Y >> Z;
	double D = 60 * (Y - X);	
	double P = 1;
	if (Z < D) 
		P = (sqr(D) - sqr(D - Z)) / sqr(D);
	cout << fixed << setprecision(7) << P << endl;

	return 0;
}
