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

vector<bool> row(8, false), col(8, false), diag(15, false), eiag(15, false);
vector<string> field(8);
vector<int> q;

void dfs(vector<string> f, vector<bool> r, vector<bool> c, vector<bool> d, vector<bool> e, int k){
    if(k==8){
        field = f;
        return;
    }

    rep(i, 8) rep(j, 8){
        if(r[i] || c[j] || d[i-j+7] || e[i+j]) continue;
        f[i][j] = 'Q';
        vector<bool> rn=r, cn=c, dn=d, en=e;
        rn[i] = true;
        cn[j] = true;
        dn[i-j+7] = true;
        en[i+j] = true;
        dfs(f, rn, cn, dn, en, k+1);
        f[i][j] = '.';
    }
}

int main()
{
    int n; cin >> n;
    int a, b;
    rep(i, 8){
        field[i] = "........";
    }
    rep(i, n){
        cin >> a >> b;
        row[a] = true;
        col[b] = true;
        diag[a-b+7] = true;
        eiag[a+b] = true;
        field[a][b] = 'Q';
        q.push_back(a*8 + b);
    }

    dfs(field, row, col, diag, eiag, n);
    rep(i, 8){
        cout << field[i] << endl;
    }

    return 0;}