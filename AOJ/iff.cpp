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
template<class T>void prarr(vector<vector<T>>& a){
rep(i, a.size()){
rep(j, a[i].size()){
cout << a[i][j]; printf(" ");}
printf("\n");} printf("\n");}

int n, m;
set<int> s[305];
arr<bool> G;

void makeG(int a, int b){
    if(G[a][b]) return;

    G[a][b] = true;
    rep(i, n){
        if(!G[i][a]) continue;
        rep(j, n){
            if(!G[b][j]) continue;
            G[i][j] = true;
        }
    }
}

int main()
{
    cin >> n >> m;
    G.resize(n, vector<bool>(n, false));
    // memset(G, 0, sizeof(G));
    rep(i, n) {
        G[i][i] = true;
        // s[i].insert(i);
    }
    rep(i, m){
        int a, b; cin >> a >> b;
        makeG(--a,--b);
    }

    // prarr(G);
    vector<int> ans[n];
    rep(i, n){
        rep(j, n){
            if(G[i][j] && G[j][i]) ans[i].push_back(j+1); 
        }
    }

    rep(i, n){
        prvec(ans[i]);
    }
    return 0;}