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
template<class T>int popcount(T &a){int c=0; rep(i, 8*(int)sizeof(a)){if((a>>i)&1) c++;} return c;}
template<class T>void pr(T x){cout << x << endl;}
template<class T>void prvec(vector<T>& a){rep(i, a.size()-1){cout << a[i] << " ";} pr(a[a.size()-1]);}
template<class T>void prarr(arr<T>& a){rep(i, a.size()) if(a[i].empty()) pr(""); else prvec(a[i]);}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

#define N 1000000
// #define N 200
int main()
{
    int n;
    vector<int> p, q;
    int k=1;
    while(1){
        int a = k*(k+1)*(k+2)/6;
        if(a>N) break;
        p.push_back(a);
        if(a&1) q.push_back(a);
        k++;
    }
    
    vector<int> dp(N+1), dq(N+1);
    rep(i, N+1){
        dp[i] = i;
        dq[i] = i;
    }
    FOR(i, 1, p.size()){
        // prvec(dp);
        FOR(j, p[i], N+1){
            chmin(dp[j],dp[j-p[i]] + 1);
        }
        // pr(dp[40]);
    }
    
    FOR(i, 1, q.size()){
        FOR(j, q[i], N+1){
            chmin(dq[j], dq[j-q[i]] + 1);
        }
    }
    // prvec(p);
    while(cin >> n){
        if(n==0) break;
        printf("%d %d\n", dp[n], dq[n]);
    }
    return 0;}