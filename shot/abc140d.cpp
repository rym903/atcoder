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
    vector<ll> pows;
    vector<ll> av;
    ll k=0;
    while(1){
        ll t = k*k*k*k*k;
        if(t>INFL) break;
        av.push_back(k);
        pows.push_back(t);
        k++;
    }
    vector<ll> tv=pows;

    FOR(i, 1, k){
        av.push_back(-i);
        pows.push_back(-tv[i]);
    }
    sort(ALL(av));
    sort(ALL(pows));

    ll x; cin >> x;
    ll a, b;
    rep(i, pows.size()){
        a = pows[i];
        int t = lower_bound(ALL(pows), a-x) - pows.begin();
        b = pows[t];
        if(a-b==x){
            cout << av[i] << " " << av[t] << endl;
            break;
        }
    }
    return 0;}