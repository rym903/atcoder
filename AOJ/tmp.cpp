#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> P;

struct WUF {
	int par[100000];
	int w[100000];
	//int rank[100000];
	
	WUF() {
		for (int i = 0; i < 100000; i++) {
			par[i] = i;
			w[i] = 0;
			//rank[i] = 0;
		}
	}
	
	P root(int x) {	//(root, rootまでの距離)
		if (par[x] == x) {
			return P(x, 0);
		}
		P res = root(par[x]);
		par[x] = res.first;
		// w[x] += res.second;
        // cout << "res=" << res.second << endl;
		return P(par[x], w[x]);
	}
	
	void unit(int x, int y, int c) {
		P res1 = root(x);
		P res2 = root(y);
		int rt1 = res1.first;
		int rt2 = res2.first;
		
		if (rt1 == rt2) return;
		//if (rank[rt1] < rank[rt2]) {
        par[rt1] = rt2;
        // printf("%d %d\n",res2.second, res1.second);
        w[rt1] = c + res2.second - res1.second;
		//}
		/*else {
			if (rank[rt1] == rank[rt2]) { rank[rt1]++; }
			par[rt2] = rt1;
			w[rt2] = -c + res1.second - res2.second;
		}*/
	}
	
	bool same(int x, int y) {
		return root(x).first == root(y).first;
	}
};

WUF wuf;

int main() {
	int n, q;
	cin >> n >> q;
	
	for (int i = 0; i < q; i++) {
		int type;
		cin >> type;
		
		if (type == 0) {
			int x, y, c;
			cin >> x >> y >> c;
			wuf.unit(x, y, c);
		}
		else {
			int x, y;
			cin >> x >> y;
			if (wuf.same(x, y) == false) {
				cout << "?" << endl;
			}
			else {
				int cx = wuf.root(x).second;
				int cy = wuf.root(y).second;
				cout << cx - cy << endl;
			}
		}
	}
	return 0;
}