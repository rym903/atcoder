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

bool is_odd_eight(int x){
    if(x%2==0) return false;

    unordered_map<int, int> m;
    for(int i=3; i<x; i+=2){
        if(x%i==0){
            while(x%i==0 && x!=1){
                m[i]++;
                x /= i;
            }
        }
    }

    if(x!=1) m[x]++;

    int k = 1;
    for(auto p: m){
        k *= 1+p.second;
    }

    if(k==8) return true;
    else return false;
}

int main()
{
    int n; cin >> n;
    int ans = 0;
    FOR(i, 1, n+1) ans += is_odd_eight(i);
    pr(ans);
    return 0;}