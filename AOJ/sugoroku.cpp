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
template<class T>void prvec(vector<T>& a){rep(i, a.size()-1){cout << a[i] << " ";} cout << a[a.size()-1] << endl;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int n;
vector<int> a;
vector<bool> seen;
bool flag;

void is_reach(int s, int k){
    if(k==n+2) {
        flag = true;
        return;
    }
    seen[k] = true;
    FOR(i, 1, s+1){
        if(seen[k+i]) continue;
        if(k+i > n+2) break;
        if(a[k+i]==0){
            is_reach(s, k+i);
        }
    }
}

int main()
{
    cin >> n;
    a.resize(n+3);
    seen.resize(n+3);
    // vector<int> pos;
    rep(i, n){
        cin >> a[i+1];
    }
    a[n+2] = 0;

    FOR(i, 1, n+2){
        flag = false;
        seen.assign(n+3, false);
        is_reach(i, 0);
        if(flag) {
            pr(i);
            return 0;
        }
    }
    return 0;}