#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
#define MOD 1000000007
 
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
template<class T>void p(T x){cout << x << endl;}
template<class T>void pvec(vector<T>& a){rep(i, a.size()-1){cout << a[i] << " ";} cout << a[a.size()-1] << endl;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
 
ll k;
vector<ll> pn(3);

int main()
{
    cin >> pn[0] >> pn[1] >> pn[2] >> k;
    sort(ALL(pn),greater<int>());
    ll ans=1, cnt=0;
    priority_queue<ll, vector<ll>, greater<ll>> que;
    set<ll> st;
    que.push(ans);
    while(1){
        ans = que.top(); que.pop();
        while(!que.empty() && ans==que.top()) que.pop();
        if(st.find(ans) != st.end()) continue;
        st.insert(ans);
        cnt++;
        if(cnt==k) break;
        rep(i, 3){
            que.push(ans*pn[i]);
        }
    }
    p(ans);
    return 0;
}