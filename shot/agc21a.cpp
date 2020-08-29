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

int dsum(ll n){
    int d=1;
    while(1){
        ll k = (ll)powl(10, d);
        if(n/k==0){
            break;
        }
        d++;
    }

    int ans=0;
    rep(i, d){
        ll t = n / (ll)powl(10, i);
        t %= 10;
        ans += t;
    }

    return ans;
}

int main()
{
    ll n; cin >> n;
    int d=1;
    while(1){
        ll k = (ll)powl(10, d);
        if(n/k==0){
            break;
        }
        d++;
    }
    
    // pr(d);
    vector<ll> e(d);
    
    int ans=0;
    rep(i, d){
        ll t = n / (ll)powl(10, i);
        t %= 10;
        e[i] = t;
        ans += t;
    }

    // prvec(e);

    ll m = n;
    ll c = 1;
    rep(i, d-1){
        c += e[i] * (ll)powl(10, i);
        n -= c;
        // pr(n);
        chmax(ans, dsum(n));
        n = m;
    }
    
    pr(ans);
    return 0;}