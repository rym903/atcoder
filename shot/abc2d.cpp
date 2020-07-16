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

int main()
{
    int n, m; cin >> n >> m;
    bool know[12][12];
    rep(i, 12) rep(j, 12) know[i][j] = false;
    rep(i, m){
        int x, y; cin >> x >> y;
        x--; y--;
        know[x][y] = true;
        know[y][x] = true;
    }

    int ans = 1;
    FOR(i, 1, 1<<n){
        vector<int> group;
        bool flag = false;
        rep(j, n) if(i & (1<<j)) group.push_back(j);

        rep(k, group.size()) {
            rep(l, group.size()){
                if(k==l) continue;
                if(know[group[k]][group[l]] == false){
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }

        if(flag) continue;
        chmax(ans, (int)group.size());
    }

    pr(ans);
    return 0;}