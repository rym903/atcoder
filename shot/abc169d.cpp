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

int div_game(ll x){
    unordered_map<ll, ll> m;
    
    if(!(x&1)){
        while(!(x&1) && x!=1){
            m[2]++;
            x >>= 1;
        }
    }

    for(ll i=3; i*i<=x; i+=2){
        // pr(i);
        if(x%i==0){
            while(x%i==0 && x!=1){
                m[i]++;
                x /= i;
            }
        }
    }

    if(x!=1) m[x]++;

    ll ans=0;

    vector<ll> v(101, 0);
    rep(i, 100) v[i+1] = v[i] + i + 1;

    for(auto e: m){
        int t = upper_bound(ALL(v), e.second) - v.begin() - 1;
        ans += t;
    } 

    return ans;
}

int main()
{
    ll x; cin >> x;
    pr(div_game(x));
    return 0;}