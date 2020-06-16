#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
#define MOD (1000000007)
#define INF (1e9)
#define INFL (1e12)
 
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
template<class T>using arr=vector<vector<T>>;
template<class T>void pr(T x){cout << x << endl;}
template<class T>void prvec(vector<T>& a){rep(i, a.size()-1){cout << a[i] << " ";} cout << a[a.size()-1] << endl;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
 
int main()
{
    int n, k; cin >> n >> k;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    bool is_all = false;
    int cnt = 0;
    // prvec(a);
    while(cnt < k){
        vector<ll> b(n, 0);
        rep(i, n){
            for(ll j=i-a[i]; j <= i+a[i]; j++){
                if(j<0) continue;
                if(j>=n) break;
                b[j]++;
            }
        }
        is_all = true;
        rep(i, n){
            if(b[i] >= (ll)i && b[i] >= n-1-i) continue;
            else {
                is_all = false;
                break;
            }
        }
        a = b;
        // prvec(a);
        cnt++;
        if(is_all) break;
    }

    if(cnt==k){
        prvec(a);
        return 0;
    }

    k -= cnt;

    rep(i, n){
        a[i] += k*n;
    }
    prvec(a);
    return 0;}