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
    int k; cin >> k;
    if(k<10) {printf("%d\n", k); return 0;}

    queue<ll> que;
    rep(i, 9) {
        // print(i+1);
        que.push(i+1);
    }

    int cnt=9;
    ll ans=0;
    while(1){
        ll x = que.front(); que.pop();
        // printf("x=%lld\n", x);
        if(x%10!=0) {
            cnt++;
            que.push(10*x + x%10 - 1);
            // print(10*x + x%10 - 1);
            if(cnt==k) {ans=10*x + x%10 - 1; break;}
        }
        cnt++;
        que.push(10*x + x%10);
        // print(10*x + x%10);
        if(cnt==k) {ans=10*x + x%10; break;}
        if(x%10!=9) {
            cnt++;
            que.push(10*x + x%10 + 1);
            // print(10*x + x%10 + 1);
            if(cnt==k) {ans=10*x + x%10 + 1; break;}
        }
    }
    print(ans);

    return 0;
}