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

//nコからkコを取り出す。
//for(int bit = (1<<k)-1; bit < (1<<n); bit=next_combination(bit)){}
int next_combination(int sub) {
int x = sub & -sub, y = sub + x;
return (((sub & ~y) / x) >> 1) | y;
}

ll join(ll x, ll y){
    int dig = 1;
    ll div = 10;
    while(y/div != 0){
        dig++;
        div *= 10;
    }

    x *= div;
    return x+y;
}

int main()
{
    int n, k; 
    while(cin >> n >> k){
    if(n==0 && k==0) break;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    set<int> s;
    int w = 1;
    rep(i, k) w*=(i+1);

    for(int bit = (1<<k)-1; bit < (1<<n); bit=next_combination(bit)){
        vector<int> p(k);
        rep(i, k) p[i] = i;
        vector<int> b;
        rep(i, n){
            if(bit >> i & 1) {
                b.push_back(a[i]);
            }
        }
        // prvec(b);
        rep(wi, w){
            ll num = join(b[p[0]], b[p[1]]);
            FOR(i, 2, k) num = join(num, b[p[i]]);
            // pr(num);
            s.insert(num);
            next_permutation(ALL(p));
        }
    }

    pr(s.size());
    }
    return 0;}