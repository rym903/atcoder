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

#define LEAFNUM 2000000
ll DEPTH = (ll)ceil(log2(LEAFNUM));
ll SIZE = (ll)powl(2, DEPTH+1)-1;
ll LEAFHEAD = (ll)powl(2, DEPTH)-1;
vector<ll> v(SIZE, 0);

ll getmax(ll a, ll b, ll k, ll l, ll r){
    if(b<l || r<a) return 0;
    if(a<=l && r<=b) return v[k];
    ll chl=2*k+1, chr=2*k+2, mid=(l+r)/2;
    return max(getmax(a, b, chl, l, mid), getmax(a, b, chr, mid+1, r));
}

void update(ll k, ll x){
    v[k] = x;
    if(k==0) return;
    ll p = (k-1)/2;
    if(v[p] >= v[k]) return;
    // printf("%d, %d\n", k, v[k]);
    update(p, x);
}

int main()
{
    int n; cin >> n;
    vector<ll> h(n), a(n);
    rep(i, n) cin >> h[i];
    rep(i, n) h[i]--;
    rep(i, n) cin >> a[i];
    rep(i, n){
        ll t = getmax(0, h[i]-1, 0, 0, LEAFNUM-1);
        update(LEAFHEAD+h[i], t+a[i]);
        // printf("%lld, %lld, %lld\n", t, t+a[i], v[0]);
    } 
    
    pr(v[0]);
    return 0;}
