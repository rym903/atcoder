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

int main()
{
    ll n; cin >> n;
    if(n==2) {pr(1); return 0;}
    ll ans = 2;
    for(ll k=2; k*k <= n; k++){
        ll kt = k;
        ll nt = n;
        if((nt-1)%kt == 0){
            if((nt-1)/kt==kt) ans++;
            else ans += 2;
            // pr(kt);
            // pr((nt-1)/kt);
        }else{
            while(nt%kt==0 && nt!=1) {
                nt /= kt;
            }
            if(nt%kt==1) {
                ans++;
                // pr(kt);
            }
        }
    }

    pr(ans);
    return 0;}