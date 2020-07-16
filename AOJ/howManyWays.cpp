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
ll ans;
void dfs(vector<int> a, int n, int x){
    // prvec(a);
    if(a.size()==4){
        int s = 0;
        rep(i, 3) s += a[i+1];
        // pr(s);
        if(s==x) ans++;
        return;
    }
    int b = a.back();
    vector<int> aa = a;
    FOR(i, b+1, n+1){
        a.push_back(i);
        dfs(a, n, x);
        a = aa;
    }
}

ll solve(int n, int x){
    vector<int> a;
    a.push_back(0);
    ans = 0;
    dfs(a, n, x);
    return ans;
}

int main()
{
    int n, x; 
    while(cin >> n >> x){
        if(n==0 && x==0) break;
        pr(solve(n, x));        
    }
    return 0;}