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
    ll n; cin >> n;
    vector<ll> s, v;
    s.push_back(0);
    v.push_back(0);
    ll d = 0;
    while(1){
        d++;
        v.push_back((ll)powl(26, d));
        s.push_back(s[d-1] + (ll)powl(26, d));
        if(n <= s[d]) break;
    }

    rep(i, d){
        n -= v[i];
    }

    // pr(n);
    string ans;

    ll inc = 0;
    while(d>0){
        ll t;
        if(d!=1) t = ((n-1) / v[d-1]);
        else t = n - 1;
        // printf("%ld %ld\n", n, t);
        ans.push_back(t + 'a');
        n -= (t)*v[d-1];
        d--;
    }
    pr(ans);
    return 0;}