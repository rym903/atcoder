#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
#define MOD 1000000007
 
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
template<class T>void print(T x){cout << x << endl;}
template<class T>void printvec(vector<T>& a){rep(i, a.size()-1){cout << a[i] << " ";} cout << a[a.size()-1] << endl;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
 
int main()
{
    ll n, k; cin >>n >>k;
    vector<ll> h(n); 
    rep(i, n) cin>>h[i];

    vector<ll> cost(n, INT64_MAX);
    cost[0]=0;
    rep(i, n){
        for(int j=1; j<=k; j++){
            if(i-j<0) break;
            chmin(cost[i], cost[i-j]+abs(h[i]-h[i-j]));
        }
    }
    print(cost[n-1]);
    return 0;
}