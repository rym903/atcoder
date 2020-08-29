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
    vector<int> p(n), q(n);
    rep(i, n) cin >> p[i];
    rep(i, n) cin >> q[i];
    vector<int> a(n);
    rep(i, n) a[i] = i+1;
    int k = 1;
    rep(i, n) k*=i+1;
    int pn, qn;
    rep(i, k){
        // prvec(a);
        if(p==a) pn = i;
        if(q==a) qn = i; 
        next_permutation(ALL(a));
    }
    pr(abs(pn-qn));
    return 0;}