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
    int n; cin >> n;
    vector<int> a(n), b(n), c(n);
    rep(i, n) cin >> a[i];    
    rep(i, n) cin >> b[i];
    rep(i, n) cin >> c[i];
    sort(ALL(a));    
    sort(ALL(b));
    sort(ALL(c));

    vector<ll> d(n);
    rep(i, n){
        d[i] = (ll)(c.size() - (upper_bound(ALL(c), b[i]) - c.begin()));
    }
    // prvec(a);
    // prvec(b);
    // prvec(c);
    // prvec(d);
    for(int i=n-2; i>=0; i--) d[i] += d[i+1];
    // prvec(d);
    ll ans = 0;
    rep(i, n){
        int t = upper_bound(ALL(b), a[i]) - b.begin();
        // pr(t);
        if(t<n) ans += (ll)d[t];
    }
    pr(ans);
    return 0;}