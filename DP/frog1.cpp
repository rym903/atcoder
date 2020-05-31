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
    ll n; cin>>n;
    vector<ll> h(n);
    rep(i, n) cin >> h[i];
    vector<ll> cost(n, 0);
    cost[0]=0; cost[1]=abs(h[1]-h[0]);

    for(int i=2;i<n;i++){
        cost[i] = min(cost[i-2] + abs(h[i]-h[i-2]), cost[i-1]+ abs(h[i]-h[i-1]));
    }

    print(cost[n-1]);
    return 0;
}