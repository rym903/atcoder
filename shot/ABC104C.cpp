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

int d;
ll g;
vector<int> p;
vector<int> c;
vector<bool> seen;
int ans;

void dfs(ll sum, int n, int i){
    ll rowmax = 100*(i+1)*p[i] + c[i];
    // printf("%lld, %d, %d, %lld\n", sum, n, i, rowmax);
    if(sum + rowmax >= g){
        int div, mod;
        div = (g - sum) / (100*(i+1));
        mod = (g - sum) % (100*(i+1));
        if(mod>0) div++;
        if(div >= p[i]) n += p[i];
        else n += div;
        // pr(n);
        chmin(ans, n);
        // return;
    }else{
        sum += rowmax;
        n += p[i];
        seen[i] = true;
        rep(j, d){
            if(seen[j]) continue;
            dfs(sum, n, j);
            seen[j] = false;
        }
    }
}

int main()
{
    cin >> d >> g;
    p.resize(d); c.resize(d);
    rep(i, d) cin >> p[i] >> c[i];
    ans = INF;
    rep(i, d){
        seen.assign(d, false);
        dfs(0, 0, i);
    }
    pr(ans);
    return 0;}