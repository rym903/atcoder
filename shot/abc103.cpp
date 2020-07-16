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
using P = pair<int, int>;
void prp(P& p) {cout << p.first << " " << p.second << endl;}
int main()
{
    int n, m; cin >> n >> m;
    vector<P> x(m);
    rep(i, m){
        cin >> x[i].second >> x[i].first;
    }
    sort(ALL(x),
        [](P& x, P& y){return x.first < y.first;}
    );
    rep(i, m) prp(x[i]);
    int cnt = 1;
    int p = x[0].first;
    rep(i, m){
        if(x[i].second >= p){
            cnt++;
            p = x[i].first;
        }
    }
    pr(cnt);
    return 0;}