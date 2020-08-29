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
using P = pair<int, int>;
void prp(P& p) {cout << p.first << " " << p.second << endl;}

bool is_able(int n, vector<ll> h, vector<ll> s, ll mid){
    // pr(mid);
    vector<ll> t(n);
    rep(i, n){
        if(mid-h[i] < 0) return false;
        t[i] = (mid - h[i])/s[i];
        // if(t[i]<0) return false; 最初こうしていたが、これだと-1/2みたいな割り算になったときに弾いてくれない
    }
    sort(ALL(t));
    // prvec(t);
    for(ll i=0; i < n; i++){
        if(i > t[i]) return false;
    }
    return true;
}

int main()
{
    int n; cin >> n;
    vector<ll> h(n), s(n);
    rep(i, n) cin >> h[i] >> s[i];
    ll left, right;
    left = INFL; right = 0;
    rep(i, n){
        chmin(left, h[i]);
        chmax(right, h[i]+s[i]*(n-1));
    }
    ll mid = (left+right)/2;
    ll ans = INFL;
    while(left+1<right){
        mid = (left+right)/2;
        if(is_able(n, h, s, mid)){
            right = mid;
        }else{
            left = mid;
        }
    }
    pr(right);
    // pr(-1/2);
    return 0;}