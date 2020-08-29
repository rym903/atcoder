#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
#define MOD (1000000007)
#define INF (2e9)
#define INFL (2e18)

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
using vint=vector<int>;
using vll=vector<ll>;
template<class T>using arr=vector<vector<T>>;
template<class T>int popcount(T &a){int c=0; rep(i, 8*(int)sizeof(a)){if((a>>i)&1) c++;} return c;}
template<class T>void pr(T x){cout << x << endl;}
template<class T>void prvec(vector<T>& a){rep(i, a.size()-1){cout << a[i] << " ";} pr(a[a.size()-1]);}
template<class T>void prarr(arr<T>& a){rep(i, a.size()) if(a[i].empty()) pr(""); else prvec(a[i]);}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main()
{
    int n; cin >> n;
    vint t(n), a(n);
    rep(i, n) cin >> t[i]; 
    rep(i, n) cin >> a[i]; 

    vector<ll> ans(n);

    if(n==1) {
        if(a[0] != t[0]) pr(0);
        else pr(1);
        return 0;
    }
    if(a[0] > a[1] && t[0] != a[0]) {pr(0); return 0;}
    if(t[n-2] < t[n-1] && t[n-1] != a[n-1]) {pr(0); return 0;}

    if(n==2) {pr(1); return 0;}

    ans[0] = 1;
    ans[n-1] = 1;
    FOR(i, 1, n-1){
        if(t[i] < t[i-1] || a[i] < a[i+1]){pr(0); return 0;}
        if(t[i] > t[i-1] && a[i] > a[i+1]){
            if(a[i] != t[i]) {
                pr(0); 
                return 0;
                }
            ans[i] = 1;
        }else if(t[i] > t[i-1]){
            if(a[i] < t[i]) {pr(0); return 0;}
            ans[i] = 1;
        }else if(a[i] > a[i+1]){
            if(a[i] > t[i]) {pr(0); return 0;}
            ans[i] = 1;
        }else{
            ans[i] = (ll)min(a[i], t[i]);
        }
    }

    ll k = 1;
    rep(i, n){
        k *= ans[i];
        k %= MOD;
    }
    pr(k);
    return 0;}