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
template<class T>int popcount(T &a){int c=0; rep(i, 8*(int)sizeof(a)){if((a>>i)&1) c++;} return c;}
template<class T>void pr(T x){cout << x << endl;}
template<class T>void prvec(vector<T>& a){rep(i, a.size()-1){cout << a[i] << " ";} pr(a[a.size()-1]);}
template<class T>void prarr(arr<T>& a){rep(i, a.size()) if(a[i].empty()) pr(""); else prvec(a[i]);}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main()
{
    int n, x; cin >> n >> x;
    vector<int> w(n);
    rep(i, n) cin >> w[i];
    vector<int> a, b;
    int half = n/2;
    rep(i, n){
        if(i < half) a.push_back(w[i]);
        else b.push_back(w[i]);
    }

    ll ans = 0;
    vector<int> p;
    rep(bit, 1<<a.size()){
        int t = 0;
        rep(i, a.size()){
            if((bit>>i)&1) t += a[i];
        }
        p.push_back(t);
        // if(t==x) ans++;
    }
    sort(ALL(p));

    rep(bit, 1<<b.size()){
        int t = 0;
        rep(i, b.size()){
            if((bit>>i)&1) t += b[i];
        }
        // if(t > x) continue;
        // if(t == x) {
        //     ans++;
        //     continue;
        // }
        int s = upper_bound(ALL(p), x - t) - lower_bound(ALL(p), x-t);
        ans += s;
    }

    pr(ans);
    return 0;}