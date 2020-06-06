#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
#define MOD 1000000007
#define INF 1e9
#define INFL 1e12
 
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
template<class T>void pr(T x){cout << x << endl;}
template<class T>void prvec(vector<T>& a){rep(i, a.size()-1){cout << a[i] << " ";} cout << a[a.size()-1] << endl;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
struct Node {
    int n;
    int c;
};

vector<Node> v;
vector<vector<Node*>> G;
 
int main()
{
    int n, m, q; cin >> n >> m >> q;
    G.resize(n);
    v.resize(n);
    rep(i, n) v[i].n = i;

    rep(i, m){
        int f, t;
        cin >> f >> t;
        f--; t--;
        G[f].push_back(&v[t]);
        G[t].push_back(&v[f]);
    }

    rep(i, n){
        int c;
        cin >> c;
        v[i].c = c;
    }

    rep(i, q){
        int com, x, y;
        cin >> com >> x; x--;
        if(com == 1){
            cout << v[x].c << endl;
            for(Node* nd: G[x]){
                nd->c = v[x].c;
            }
        }else{
            cin >> y;
            cout << v[x].c << endl;
            v[x].c = y;
        }
    }
    return 0;
}