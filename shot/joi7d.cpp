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

vector<P> z;
vector<P> star;
vector<P> pos;
int n, m;

P solve(int a){
    int x, y;
    x = star[a].first; y = star[a].second;
    FOR(i, 1, n){
        int xe = x + z[i].first; 
        int ye = y + z[i].second;
        P t = {xe, ye};
        if(t != *lower_bound(ALL(star), t)){
            return {INF, INF};
        }
    }
    return {x - z[0].first, y - z[0].second};
}

int main()
{
    cin >> n;
    z.resize(n);
    rep(i, n){
        int a, b; cin >> a >> b;
        z[i] = {a, b};
    }
    FOR(i, 1, n) {
        z[i].first -= z[0].first;
        z[i].second -= z[0].second;
    }
    cin >> m;
    star.resize(m);
    rep(i, m){
        int a, b; cin >> a >> b;
        star[i] = {a, b};
    }
    sort(ALL(star));
    rep(i, m){
        pos.resize(n);
        P a = solve(i);
        if(a.first!=INF) prp(a);
    }
    return 0;}