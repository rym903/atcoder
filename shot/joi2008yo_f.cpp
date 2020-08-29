#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
#define MOD (1000000007)
#define INF (1e9)
#define INFL (1e18)

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
template<class T>using arr=vector<vector<T>>;
template<class T>int popcount(T &a){int c=0; rep(i, 8*(int)sizeof(a)){if((a>>i)&1) c++;} return c;}
template<class T>void pr(T x){cout << x << endl;}
template<class T>void prvec(vector<T>& a){rep(i, a.size()-1){cout << a[i] << " ";} pr(a[a.size()-1]);}
template<class T>void prarr(arr<T>& a){rep(i, a.size()) if(a[i].empty()) pr(""); else prvec(a[i]);}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

arr<int> d;
// 全頂点から各点への最短距離を求める。O(V^3)
void warshall_floyd(int n) {
    for (int k = 0; k < n; k++){       // 経由する頂点
      for (int i = 0; i < n; i++) {    // 始点
        for (int j = 0; j < n; j++) {  // 終点
          d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        }
      }
    }
  }

int n, k;

int main()
{
    cin >> n >> k;
    d.resize(n, vector<int>(n, INF));

    bool update = false;
    rep(i, k){
        int t, a, b, c;
        cin >> t;
        // pr(t);
        if(t==0){
            cin >> a >> b;
            a--; b--;
            if(update) warshall_floyd(n);
            if(d[a][b]==INF) pr(-1);
            else pr(d[a][b]);
            update = false;
        }else{
            cin >> a >> b >> c;
            a--; b--;
            if(d[a][b] > c) {
                d[a][b] = c;
                d[b][a] = c;
            }
            update = true;
        }
    }
    return 0;}