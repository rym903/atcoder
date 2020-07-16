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
template<class T>void prvec(vector<T>& a){rep(i, a.size()-1){cout << a[i] << " ";} cout << a[a.size()-1] << endl;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
 
int main()
{
    int n, m; cin >> n >> m;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    vector<ll> left(m), right(m);
    vector<int> ok(n+1, 0);
    rep(i, m){
        cin >> left[i] >> right[i];
        left[i]--; right[i]--;
        ok[left[i]] = 1;
        ok[right[i]+1] = -1;
    }
    rep(i, n) ok[i+1] += ok[i];
    prvec(ok);

    ll ans = 0;
    rep(i, n){
        if(ok[i]==0) ans += a[i];
    }
    

    return 0;}