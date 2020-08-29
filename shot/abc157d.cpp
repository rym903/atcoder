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

int n, m, k;
vector<bool> seen;
vector<int> tree_num;
arr<int> G;
// arr<int> F;
arr<int> B;
vector<int> cand;

void bfs(int x, int num){
    vector<int> tree;
    tree.push_back(x);
    seen[x] = true;
    tree_num[x] = num;

    queue<int> que;
    que.push(x);

    while(!que.empty()){
        int a = que.front(); que.pop();
        for(int b: G[a]){
            if(seen[b]) continue;
            seen[b] = true;
            tree.push_back(b);
            tree_num[b] = num;
            que.push(b);
        }
    }

    for(int t: tree){
        int bl = 0;
        for(int b: B[t]){
            if(tree_num[t]==tree_num[b]) bl++;
        }

        cand[t] = tree.size() - G[t].size() - bl - 1;
    }
}


int main()
{
    cin >> n >> m >> k;
    seen.assign(n, false);
    tree_num.assign(n, -1);
    G.resize(n);
    B.resize(n);
    cand.resize(n);

    rep(i, m){
        int a, b; cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    rep(i, k){
        int a, b; cin >> a >> b;
        a--; b--;
        B[a].push_back(b);
        B[b].push_back(a);
    }

    int num = 0;
    rep(i, n){
        if(seen[i]==false) bfs(i, num++);
    }

    prvec(cand);
    return 0;}