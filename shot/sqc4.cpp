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
using P = pair<int, ll>;
void prp(P& p) {cout << p.first << " " << p.second << endl;}

int n, k;
vector<int> p;
P getK(vector<int> b, int bit){
    int cnt = 0;
    ll cost = 0;
    int maxheight = 0;
    FOR(i, 1, n+1){
        if(maxheight < b[i]) cnt++;
        else if(bit>>(i-1)&1){
            cost += (ll)maxheight - b[i] + 1;
            b[i] = maxheight + 1;
            cnt++;
        }
        chmax(maxheight, b[i]);
    }
    // cout << bitset<15>(bit) << endl;
    // prvec(b);
    return {cnt, cost};
}

int main()
{
    cin >> n >> k;
    p.resize(n+1);
    p[0] = 0;
    rep(i, n) cin >> p[i+1];
    ll ans = INFL;
    rep(i, 1<<n){
        P K = getK(p, i);
        if(K.first >= k) chmin(ans, K.second);
    }
    pr(ans);
    return 0;}