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

ll join(ll a, ll b){
    return a*10 + b;
}

int main()
{
    int k; cin >> k;
    vector<ll> a;
    rep(i,9) a.push_back(i+1);

    while(1){
        // prvec(a);
        if(k <= a.size()) break;
        k -= a.size();
        vector<ll> b;
        rep(i, a.size()){
            ll one = a[i]%10;
            FOR(j, -1, 2){
                if(j==-1 && one==0) continue;
                if(j==1 && one==9) continue;
                b.push_back(join(a[i], one+j));
            }
        }
        a = b;
    }

    pr(a[k-1]);
    return 0;}