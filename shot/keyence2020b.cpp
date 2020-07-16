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
using P = pair<ll, ll>;
void prp(P& p) {cout << p.first << " " << p.second << endl;}
int main()
{
    int n; cin >> n;
    vector<P> x(n);
    rep(i, n) {
        ll a, b; cin >> a >> b;
        x[i].first = a + b;
        x[i].second = a - b;
    }
    sort(ALL(x));
    int cnt = 1;
    P p = x[0];
    FOR(i, 1, x.size()){
        if(p.first <= x[i].second){ 
            cnt++;
            p = x[i];
        }
    }
    pr(cnt);
    return 0;}