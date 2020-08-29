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

int main()
{
    int n, d; cin >> n >> d;
    arr<int> X(n, vector<int>(d));

    rep(i, n) rep(j, d) cin >> X[i][j];

    vector<int> v;
    rep(i, 1000) v.push_back((i+1)*(i+1));

    int ans = 0;
    FOR(i, 0, n-1) FOR(j, i+1, n){
        int dist = 0;
        rep(k, d) dist += (X[i][k] - X[j][k])*(X[i][k] - X[j][k]);

        auto t = lower_bound(ALL(v), dist);
        if(*t == dist) ans++;
    }
    pr(ans);
    return 0;}