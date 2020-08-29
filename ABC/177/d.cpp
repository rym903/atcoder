#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
#define MOD (1000000007)
#define INF (2e9)
#define INFL (2e18)

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
using vint=vector<int>;
using vll=vector<ll>;
template<class T>using arr=vector<vector<T>>;
template<class T>int popcount(T &a){int c=0; rep(i, 8*(int)sizeof(a)){if((a>>i)&1) c++;} return c;}
template<class T>void pr(T x){cout << x << endl;}
template<class T>void prvec(vector<T>& a){rep(i, a.size()-1){cout << a[i] << " ";} pr(a[a.size()-1]);}
template<class T>void prarr(arr<T>& a){rep(i, a.size()) if(a[i].empty()) pr(""); else prvec(a[i]);}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
int n, m;
arr<int> G;
arr<bool> d;
vector<bool> seen;


int main()
{
    cin >> n >> m;
    
    G.resize(n);
    // d.resize(n, vector<bool>(n, 0));
    rep(i, m){
        int a, b; cin >> a >> b;
        a--; b--;
        // if(d[a][b]) continue;
        // d[a][b] = true;
        // d[b][a] = true;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    seen.assign(n, false);
    // prarr(G);

    int s = 0;
    rep(i, n){
        if(seen[i]) continue;
        seen[i] = true;
        int t = 1;
        queue<int> que;
        que.push(i);

        while(!que.empty()){
            int a = que.front(); que.pop();
            for(auto p: G[a]){
                if(seen[p]) continue;
                seen[p] = true;
                t++;
                que.push(p);
            }
        }

        chmax(s, t);
    }
    pr(s);
    return 0;}