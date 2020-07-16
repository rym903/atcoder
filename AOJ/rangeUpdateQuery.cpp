#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<(n); i++)
#define FOR(i,x,n) for(ll i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
#define MOD (1000000007)
#define INF (1e9)
#define INFL (1e18)

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
template<class T>using arr=vector<vector<T>>;
template<class T>void pr(T x){cout << x << endl;}
template<class T>void prvec(vector<T>& a){rep(i, a.size()-1){cout << a[i] << " ";} cout << a[a.size()-1] << endl;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
#define LEAF ((ll)pow(2, 17)-1)
#define NUM ((ll)pow(2, 18)-1)
using P=pair<ll, ll>;
vector<P> seg(NUM, {(ll)pow(2,31)-1, 0});

void update(ll s, ll t, ll x, ll n, ll l, ll r, ll k){
    if(r < s || t < l) {return;}
    if(l==r) {seg[k] = {x, n}; return;}
    if(s<=l && r<=t) {seg[k] = {x, n}; return;}
    ll mid = (l+r)/2;
    ll chl = 2*k+1, chr = 2*k+2;
    update(s, t, x, n, l, mid, chl);
    update(s, t, x, n, mid+1, r, chr);
}

ll find(ll i, P p){
    if(seg[i].second > p.second) p = seg[i];
    if(i==0) return p.first;
    return find((i-1)/2, p); 
}

int main()
{
    ll n, q; cin >> n >> q;
    ll c, s, t, x;
    rep(i, q){
        cin >> c;
        if(c==1){
            cin >> x;
            ll k = find(LEAF + x, {0, -1});
            pr(k);
        }else{
            cin >> s >> t >> x;
            update(s, t, x, i+1, 0, LEAF, 0);
        }
    }

    return 0;}