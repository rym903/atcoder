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
int n, m;
vector<int> a;

void solve(){
    vector<int> c(n*(n-1)/2 + n + 1);
    int ci=0;
    rep(i, n) FOR(j, i+1, n){
        c[ci++] = a[i] + a[j];
    }
    rep(i, n) c[ci++] = a[i];
    c[ci] = 0;
    sort(ALL(c));
    // prvec(c);
    int ans = 0;
    rep(i, n) rep(j, n){
        if(a[i] + a[j] > m) continue;
        // printf("%d, %d, %d\n", a[i], a[j], m - a[i] - a[j]);
        int k = *(--upper_bound(ALL(c), m - a[i] - a[j]));
        // printf("k=%d\n", k);
        // pr(a[i] + a[j] + k);
        chmax(ans, a[i] + a[j] + k);
    }
    pr(ans);
}

int main()
{
    while(cin >> n >> m){
        if(n==0 && m==0) break;
        a.resize(n);
        rep(i, n) cin >> a[i];
        solve();
    }
    return 0;}