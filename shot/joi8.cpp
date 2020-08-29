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
template<class T>void pr(T x){cout << x << endl;}
template<class T>void prvec(vector<T>& a){rep(i, a.size()-1){cout << a[i] << " ";} pr(a[a.size()-1]);}
template<class T>void prarr(arr<T>& a){rep(i, a.size()) if(a[i].empty()) pr(""); else prvec(a[i]);}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main()
{
    int D, n, m; cin >> D >> n >> m;
    vector<int> d(n), k(m);
    d[0] = 0;
    rep(i, n-1) cin >> d[i+1];
    rep(i, m) cin >> k[i];
    sort(ALL(d));
    ll ans = 0;
    rep(i, m){
        int t = lower_bound(ALL(d), k[i]) - d.begin();
        // pr(t);
        int dd;
        if(t==n) dd = min(D-k[i], abs(k[i] - d[t-1]));
        else dd = min(abs(k[i]-d[t]), abs(k[i] - d[t-1]));
        // pr(dd);
        ans += dd;
    }
    pr(ans);
    return 0;}