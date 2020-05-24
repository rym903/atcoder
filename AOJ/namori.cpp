#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
#define MOD 1000000007
 
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
void print(int x){printf("%d\n", x);}
void print(ll x){printf("%lld\n", x);}
void printvec(vector<int> a){
rep(i, a.size()-1){
printf("%d ", a[i]);
}
printf("%d\n", a[a.size()-1]);
}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
 
int main()
{
    int n;
    cin >> n;

    vector<vector<int>> G(n);
    vector<int> deg(n, 0);
    int a, b;
    rep(i, n){
        scanf("%d %d", &a, &b);
        --a; --b;
        deg[a]++; deg[b]++;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<bool> ispushed(n, false);
    queue<int> que;

    rep(i, n) if(deg[i]==1) que.push(i);
    while(!que.empty()){
        int e = que.front(); que.pop();
        ispushed[e] = true;
        for(auto to: G[e]){
            deg[to]--;

            if(deg[to]==1) que.push(to);
        }
    }

    int q;
    cin >> q;
    int u, v;
    rep(i, q){
        scanf("%d %d", &u, &v);
        if(!ispushed[u-1] && !ispushed[v-1]) printf("2\n");
        else printf("1\n");
    }
    return 0;
}